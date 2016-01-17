// RF433 Receiver
// Author: Víctor Almaraz Sánchez
// Website: http://www.valmaraz.com

// Source: http://www.instructables.com/id/Modulos-RF433-Mhz-con-Arduino/?ALLSTEPS
// License: MIT License (see root directory)

// Required libraries (check 'Libraries' folder in root directory):
// - VirtualWire: https://www.pjrc.com/teensy/td_libs_VirtualWire.html

#include <VirtualWire.h>

const int SERIAL_BAUDRATE = 9600;
// Led pin that will show activity
const int PIN_LED = 13;
// Receiver data pin
const int PIN_TX = 12;
const int RF_BITS_PER_SECOND = 4000;
const int DELAY_IN_MILLIS = 125;

int count;

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);
    pinMode(PIN_LED, OUTPUT);
    
    vw_set_rx_pin(PIN_TX);
    vw_set_ptt_inverted(true);
    vw_setup(RF_BITS_PER_SECOND);
    vw_rx_start();
    Serial.println("Receiver started");
}

void loop()
{
    digitalWrite(PIN_LED, HIGH);
    // Save data in buffer
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    // Check character length
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    
    if (vw_get_message(buf, &buflen)) {
      // If there is a receiver message...
      Serial.print("Rx (");
      Serial.print(count);
      Serial.print("): ");
      
      // Print message
	    for (int i = 0; i < buflen; i++) {
        // Print received character
        char c = (buf[i]);
        Serial.print(c);
        Serial.print(" ");
	    }
      Serial.println("");
      count++;
    }

    // Turn led off to show that it is working
    delay(DELAY_IN_MILLIS);
    digitalWrite(PIN_LED, LOW);
    delay(DELAY_IN_MILLIS);
}
