// Made By Apoorv Tomar
// This sketch is used to establish communication between various 
// peripheral devices connected to Arduino
// Devices connected : SIM800, HC-05 (in Master mode), MQ-135, 
// Please refer to the bluetooth_master.ino file to operate HC-05 in master mode


#include<SoftwareSerial.h>
void setup() {
// Serial Monitor started at 9600 baud rate
  Serial.begin(9600);
// Hardware Serial communication started at Pins RX1 and TX1
  Serial1.begin(9600);
  delay(1000);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int flag=0;
  // Code to configure SIM800 for first time
  if(flag==0)
  {
  Serial1.write("at\r\n");
  if(Serial1.available())
  Serial.write(Serial1.read());
  delay(1000);
  // Write your appropriate APN instead of "airtel"
  Serial1.write("at+sapbr=3,1,\"APN\",\"airtel\"\r\n");
  if(Serial1.available())
  Serial.write(Serial1.read());
  delay(1000);
  Serial1.write("at+sapbr=1,1\r\n");
  if(Serial1.available())
  Serial.write(Serial1.read());
  delay(1000);
  Serial1.write("at+httpinit\r\n");
  if(Serial1.available())
  Serial.write(Serial1.read());
  delay(1000);
  Serial1.write("at+httppara=\"CID\",1\r\n");
  if(Serial1.available())
  Serial.write(Serial1.read());
  delay(1000);
  // Give URL inplace of ENDPOINT_URL field;
  Serial1.write("at+httppara=\"URL\",\"ENDPOINT_URL");
  if(Serial1.available())
  Serial.write(Serial1.read());
  delay(1000);
  flag=1;
  Serial1.write("at+httpaction=0\r\n");
  if(Serial1.available())
  Serial.write(Serial1.read());
  }
  else
  Serial1.write("at+httpaction=0\r\n");
  if(Serial1.available())
  Serial.write(Serial1.read());

}
