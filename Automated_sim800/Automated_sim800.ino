#include<SoftwareSerial.h>
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  delay(1000);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int flag=0;
  if(flag==0)
  {
  Serial1.write("at\r\n");
  if(Serial1.available())
  Serial.write(Serial1.read());
  delay(1000);
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
  Serial1.write("at+httppara=\"URL\",\"52.76.4.177/?v7&session=123&time=1141212312312312&kff1005=34&kff1006=345&kff1001=34\"\r\n");
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
