#include <Time.h>
#include <TimeLib.h>
#include <TimeAlarms.h>

void setup() {
  Serial.begin(9600);
  // set time: HH, mm, ss, dd, MM, YY
  setTime(17,03,0,10,2,17); 
  // create the alarms 
  // 8:30am every day
  Alarm.alarmRepeat(17, 04, 0, alarm1);
  // 5:45pm every day 
  Alarm.alarmRepeat(17, 05, 0, alarm2);
  // 8:30:30 every Saturday 
  Alarm.alarmRepeat(dowFriday, 8, 30, 30, alarm3);

 // timer for every 15 seconds  
  Alarm.timerRepeat(15, Repeats);
  // called once after 10 seconds 
  Alarm.timerOnce(10, OnceOnly);
}

void loop() {
  digitalClockDisplay();
  // wait one second between clock display
  Alarm.delay(1000);
}

void digitalClockDisplay() {
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println(); 
}

void printDigits(int digits) {
  Serial.print(":");
  if(digits < 10) {
    Serial.print('0');
  }
  Serial.print(digits);
}

void alarm1(){
  Serial.println("Alarm: 1");
}

void alarm2(){
  Serial.println("Alarm: 2");
}

void alarm3(){
  Serial.println("Alarm: 3");
}

void Repeats() {
  Serial.println("15 second timer");         
}

void OnceOnly() {
  Serial.println("This timer only triggers once");  
}

