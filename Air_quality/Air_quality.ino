int sensorValue;

int digitalValue;

void setup()

{

  Serial.begin(9600);      // sets the serial port to 9600

  pinMode( 0, INPUT);      // Analog pin A0 is set for input mode

}



void loop()

{
  if(Serial.available())
  {
  sensorValue = analogRead(0);       // read analog input A0

  digitalValue = digitalRead(0);     // read digital input from D0

  Serial.println(sensorValue, DEC);  // prints the value read

  Serial.println(digitalValue, DEC);
  }
  delay(2000);                        // wait 100ms for next reading

}
