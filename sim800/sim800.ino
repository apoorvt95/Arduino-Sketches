// Made By Apoorv Tomar
// Connect SIM800 RX - TX1 Pin and TX - RX1 Pin
// GND - GND Arduino Board
// Use 12V power supply adapter and connect to the jack
// When Serial communication is established
// Use AT commands to configure SIM800
// View the README file for resources on AT commands.

void setup() {
  //Begin serial comunication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  while(!Serial);
   
  //Being serial communication witj Arduino and SIM800
  Serial1.begin(9600);
  delay(1000);
   
  Serial.println("Setup Complete!");
}
 
void loop() {
  //Read SIM800 output (if available) and print it in Arduino IDE Serial Monitor
  if(Serial1.available()){
    Serial.write(Serial1.read());
  }
  //Read Arduino IDE Serial Monitor inputs (if available) and send them to SIM800
  if(Serial.available()){    
    Serial1.write(Serial.read());
  }
}
