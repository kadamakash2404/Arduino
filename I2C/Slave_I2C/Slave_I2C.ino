#include <Wire.h>
#include <stdio.h>
#include <string.h>

double sensorValue = 0;
char buff[12];
const int analogInPin = A0;

void setup() {
  Serial.begin(9600);
  Wire.begin(10);     /// Join I2C bus at address 10
  Wire.onRequest(requentevent);     //handler: the function to be called, takes no parameters and returns nothing.
}

void loop() {
  sensorValue = analogRead(analogInPin);
  sensorValue*=1.1854;
  dtostrf(sensorValue,8,4,buff);
  strcat(buff,"\n");
  Serial.println(buff);
  delay(50);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requentevent() {
  
  Wire.write(buff); // respond with message of 6 bytes
  // as expected by master
}
