// HC-06 (JY-MCU) Bluetooth adapter
// Author: Víctor Almaraz Sánchez
// Website: http://www.valmaraz.com

// Sources:
// - http://tallerarduino.com/2011/12/06/modulo-bluetooth-hc-06-o-gp-gc021-y-arduino/
// - http://www.instructables.com/id/AT-command-mode-of-HC-05-Bluetooth-module/
// License: MIT License (see root directory)

// Hardware info:
// - Module: HC-06 (verified) / HC-05 (must work, not verified)
// - Bluetooth voltage: 3.6v to 6v (3.3v recommended)

#include <SoftwareSerial.h>

const int PIN_RX = 10;
const int PIN_TX = 11;

SoftwareSerial mySerial(PIN_RX, PIN_TX);

void setup() {
  Serial.begin(9600);
  Serial.println("Setup...");
  mySerial.begin(9600);

  // One second as delay to send different commands
  delay(1000);
  mySerial.print("AT");
  delay(1000);
  mySerial.print("AT+VERSION");
  delay(1000);
  // Bluetooth password: "AT+PIN" plus the password you want, without white spaces
  mySerial.print("AT+PIN1234");
  delay(1000);
  // Bluetooth name: "AT+NAME" plus the name you want, without white spaces
  mySerial.print("AT+NAMEArduino");
  delay(1000);
  /*
   * Baud rates:
   * 
   * 1 -> 1200
   * 2 -> 2400
   * 3 -> 4800
   * 4 -> 9600 (default)
   * 5 -> 19200
   * 6 -> 38400
   * 7 -> 57600
   * 8 -> 115200
   */
  mySerial.print("AT+BAUD4");
  delay(1000);
  Serial.println("...finished. Ready to send and receive data.");
}

void loop() {
  if (mySerial.available()) {
    // Write (send) paired device data to serial port (PC)
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    // Write (send) serial port data (PC) to paired device
    mySerial.write(Serial.read());
  }
}
