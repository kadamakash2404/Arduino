#include <Wire.h>

void setup() {
  Wire.begin(10);     // Join I2C bus at address 10
  Serial.begin(9600);  // begin serial at baud rate of 9600
  // put your setup code here, to run once:
}

void loop() {
  Wire.requestFrom(10,11);  // Wire.requestFrom(address, quantity)
  while(Wire.available())     // returns the number of bytes available for read
  {
    char c = Wire.read();     // The next byte received.
    Serial.print(c);
  }
  // put your main code here, to run repeatedly:
  delay(50);
}
