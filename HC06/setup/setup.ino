// Basic Bluetooth sketch HC-06_01
// Connect the Hc-06 module and communicate using the serial monitor
//
// The HC-06 defaults to AT mode when first powered on.
// The default baud rate is 9600
// The Hc-06 requires all AT commands to be in uppercase. NL+CR should not be added to the command string
//
 
 
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the HC-06 TX to the Arduino RX on pin 2. 
// Connect the HC-06 RX to the Arduino TX on pin 3 through a voltage divider.
// 
 
String command = ""; 
void setup() 
{
  pinMode(0, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
 
  // HC-06 default serial speed is 9600
  BTserial.begin(9600);

  delay(1000);
  Serial.println("AT+BAUD4 ->");
  BTserial.print("AT+BAUD4");
  delay(2000);
  Serial.println("AT ->");
  BTserial.print("AT");
  delay(2000);
  Serial.println("ATVERSION ->");
  BTserial.print("ATVERSION");
}
 
void loop()
{
    if (BTserial.available())
    { 
      while(BTserial.available()) { 
        command += (char)BTserial.read();
        delay(10);
      }
      Serial.println(command);
      command = "";
    }
    if (Serial.available())
    {
      delay(20); 
      BTserial.write(Serial.read());
    }
}
