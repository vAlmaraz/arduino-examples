// HY-SRF05, HC-SR04 Ultrasonic sensor
// Author: Víctor Almaraz Sánchez
// Website: http://www.valmaraz.com

// Sources:
// - http://www.f15ijp.com/2012/09/arduino-ultrasonic-sensor-hc-sr04-or-hy-srf05/
// - http://forum.arduino.cc/index.php?topic=89524.0
// License: MIT License (see root directory)

// Hardware info:
// - Ultrasonic voltage: 5v

const int SERIAL_BAUDRATE = 9600;
const int PIN_TRIG = 12;
const int PIN_ECHO = 13;
const int DELAY_PULSE_SHORT_IN_MILLIS = 2;
const int DELAY_PULSE_LONG_IN_MILLIS = 2;
const int DELAY_SENSOR_IN_MILLIS = 1000;

void setup() {
  // Initialize serial communication:
  Serial.begin(SERIAL_BAUDRATE);
  
  pinMode(PIN_TRIG,OUTPUT);
  pinMode(PIN_ECHO,INPUT);
}

void loop() {
  long duration, distanceCm, distanceIn;
  
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(DELAY_PULSE_SHORT_IN_MILLIS);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(DELAY_PULSE_LONG_IN_MILLIS);
  digitalWrite(PIN_TRIG, LOW);
  duration = pulseIn(PIN_ECHO,HIGH);
  
  // Convert the time into a distance
  distanceCm = microsecondsToCentimeters(duration);
  distanceIn = microsecondsToInches(duration);
  
  if (distanceCm <= 0){
    Serial.println("Out of range");
  } else {
    Serial.print(distanceIn);
    Serial.print("in, ");
    Serial.print(distanceCm);
    Serial.print("cm");
    Serial.println();
  }
  delay(DELAY_SENSOR_IN_MILLIS);
}

/**
 * According to Parallax's datasheet for the PING))), there are
 * 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
 * second).  This gives the distance travelled by the ping, outbound
 * and return, so we divide by 2 to get the distance of the obstacle.
 * See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
 */
long microsecondsToInches(long microseconds) {
 return microseconds / 74 / 2;
}

/**
 * The speed of sound is 340 m/s or 29 microseconds per centimeter.
 * The ping travels out and back, so to find the distance of the
 * object we take half of the distance travelled.
 */
long microsecondsToCentimeters(long microseconds) {
 return microseconds / 29 / 2;
}
