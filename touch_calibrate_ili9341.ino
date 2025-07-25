#include <TFT_eSPI.h> 
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI(); 

void perform_calibration() {
  uint16_t calData[5];

  tft.fillScreen(TFT_GREEN);
  tft.setCursor(20, 0);
  tft.setTextFont(2);
  tft.setTextSize(1);
  tft.setTextColor(TFT_BLACK, TFT_GREEN);
  tft.println("Calibration");
  tft.setTextFont(1);
  tft.println("\ntouch that\nblue corner");
  delay(1000);

  tft.calibrateTouch(calData, TFT_MAGENTA, TFT_GREEN, 15); 

  tft.setTouch(calData);

  Serial.println("Your Screen Calibration");
  Serial.printf("uint16_t calData[5] = { %d, %d, %d, %d, %d };\n", calData[0], calData[1], calData[2], calData[3], calData[4]);
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  
  tft.init();
  tft.setRotation(2);

  perform_calibration();

  tft.fillScreen(TFT_GREEN);
  tft.setTextColor(TFT_BLACK, TFT_GREEN);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("Drwaing Test");
  tft.setTextSize(1);
  tft.println("\nYou can draw know.");
}

void loop() {
  uint16_t x, y;

  if (tft.getTouch(&x, &y, 200)) { 
    Serial.print("Drawing: X = "); Serial.print(x);
    Serial.print(", Y = "); Serial.println(y);
    
    tft.fillCircle(x, y, 4, TFT_BLACK);
  }
}
