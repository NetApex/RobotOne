#include "Particle.h"
#include <TFT_eSPI.h> 

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);

TFT_eSPI display1 = TFT_eSPI(); 
#define DISPLAY1_CS  D4

// Eye parameters 
int leftEyeX = 100;  
int leftEyeY = 110;   
int eyeRadius = 90;   
int pupilRadius = 30; 

// Variables to store the previous pupil position
int prevLeftEyeX = leftEyeX;
int prevLeftEyeY = leftEyeY;

void setup(void) {
  Serial.begin(115200);

  display1.init();
  Serial.println("Display initialized"); 
  display1.setRotation(1); 
  display1.fillScreen(TFT_BLACK); 
  pinMode(DISPLAY1_CS, OUTPUT);
  digitalWrite(DISPLAY1_CS, HIGH); 

  SPI.beginTransaction(SPISettings(40000000, MSBFIRST, SPI_MODE0)); 

  // Draw the initial eye and pupil
  display1.fillCircle(100, 110, eyeRadius, TFT_WHITE); 
  display1.fillCircle(leftEyeX, leftEyeY, pupilRadius, TFT_BLACK); 
}

void loop() {
  display1.startWrite(); 

  // Erase the previous pupil (draw a gold circle over it)
  display1.fillCircle(prevLeftEyeX, prevLeftEyeY, pupilRadius, TFT_BLACK); 

  // Draw the new pupil
  display1.fillCircle(leftEyeX, leftEyeY, pupilRadius, TFT_BLACK); 

  display1.endWrite(); 

  // Update the previous pupil position
  prevLeftEyeX = leftEyeX;
  prevLeftEyeY = leftEyeY;

  // Add code here to change leftEyeX, leftEyeY 
  // to animate the pupils (e.g., make them look left, right, etc.)

  delay(100); 
}