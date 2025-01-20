/*
 Adapted from the Adafruit and Xark's PDQ graphicstest sketch.

 See end of file for original header text and MIT license info.
 
 This sketch uses the GLCD font only.

 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include <TFT_eSPI.h> // Hardware-specific library

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

TFT_eSPI display1 = TFT_eSPI();  // Create object for display 1

// Addresses for the displays (check your display documentation for the correct addresses)
#define DISPLAY1_CS   D4

// Eye parameters 
int leftEyeX = 120;  
int leftEyeY = 110;   
int eyeRadius = 90;   
int pupilRadius = 30; 

void setup(void) {
  Serial.begin(115200);

  display1.init();
  Serial.println("Display initialized"); 
  display1.setRotation(1); 
  display1.fillScreen(TFT_BLACK);  // Start with a gold background
  pinMode(DISPLAY1_CS, OUTPUT);
  digitalWrite(DISPLAY1_CS, HIGH); 
}

void loop() {

  display1.fillCircle(120, 110, eyeRadius, TFT_WHITE); 
  display1.fillCircle(leftEyeX, leftEyeY, pupilRadius, TFT_BLACK); 

  delay(100); 
}