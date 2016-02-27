// Wii Nunchuck
// Author: Víctor Almaraz Sánchez
// Website: http://www.valmaraz.com

// Sources:
// - http://playground.arduino.cc/Main/WiiChuckClass
// - http://forum.arduino.cc/index.php?topic=45924.0
// - http://blog.oscarliang.net/wii-nunchuck-arduino-tutorial/
// License: MIT License (see root directory)

// Hardware info:
// - Nunchuck voltage: 3.3v
// - Nunchuck connections: see attached pictures (Readme.md) or oscarliang blog (sources)
#include <math.h>

#include "Wire.h"
#include "WiiChuck.h"

#define MAXANGLE 90
#define MINANGLE -90

WiiChuck chuck = WiiChuck();
int angleStart, currentAngle;
int tillerStart = 0;
double angle;

void setup() {
  Serial.begin(115200);
  chuck.begin();
  chuck.update();
  chuck.calibrateJoy();
}


void loop() {
  delay(20);
  chuck.update(); 
  
  Serial.print("Joystick X:");
  Serial.print(chuck.readJoyX());
  Serial.print("-");  
  Serial.print("Joystick Y:");
  Serial.print(chuck.readJoyY());
  Serial.print("-");  
  Serial.print("Rotacion sobre eje :");  
  Serial.print(chuck.readRoll());
  Serial.print("-");
  Serial.print("Rotacion sobre eje :");   
  Serial.print(chuck.readPitch());
  Serial.print("-");  
  Serial.print("Acelerometro X:"); 
  Serial.print((int)chuck.readAccelX()); 
  Serial.print(", ");  
  Serial.print("Acelerometro Y:"); 
  Serial.print((int)chuck.readAccelY()); 
  Serial.print("-");  
  Serial.print("Acelerometro Z:"); 
  Serial.print((int)chuck.readAccelZ()); 
  Serial.print("-   ");
  Serial.print("boton: ");
  if (chuck.buttonZ) {
    Serial.print("Z");
  } else  {
    Serial.print("-");
  }
  Serial.print(", ");  
  if (chuck.buttonC) {
    Serial.print("C");
  } else  {
    Serial.print("-");
  }
  Serial.println();
}
 
