// RF433 Transmitter
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
// Transmitter data pin
const int PIN_TX = 12;
const int RF_BITS_PER_SECOND = 4000;
const int DELAY_IN_MILLIS = 125;

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);
    pinMode(PIN_LED, OUTPUT);
   
    vw_set_tx_pin(PIN_TX);
    vw_set_ptt_inverted(true);
    vw_setup(RF_BITS_PER_SECOND);
    Serial.println("Transmitter started");
}

void loop()
{
    digitalWrite(PIN_LED, HIGH);
    char msg[] = "Hello World!";
    
    // Send message
    vw_send((uint8_t *)msg, strlen(msg));
    // Wait until message has been sent
    vw_wait_tx();
    Serial.println("Sending message...");
    
    // Turn led off to show that it is working
    delay(DELAY_IN_MILLIS);
    digitalWrite(PIN_LED, LOW);
    delay(DELAY_IN_MILLIS);
} 
