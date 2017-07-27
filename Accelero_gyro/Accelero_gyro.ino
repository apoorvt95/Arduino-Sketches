include
define X0 0x32
define X1 0x33
define Y0 0x34
define Y1 0x35
define Z0 0x36
define Z1 0x37
void setup()
{
Wire.begin(); // join i2c bus
Serial.begin(19200); // start serial for output
Wire.beginTransmission(0x1D); // transmit to ADXL345
Wire.send(0x2D);// POWER_CTL
Wire.send(0x09);// measurement mode, 4hz wakeup
Wire.endTransmission(); // stop transmitting
}
void loop()
{
Serial.print(getDir(‘x’), DEC); // print as an ASCII-encoded decimal
Serial.print(“\t”); // prints a tab
Serial.print(getDir(‘y’), DEC);
Serial.print(“\t”);
Serial.print(getDir(‘z’), DEC);
Serial.print(“\t”);
Serial.println(“”); // prints a newline
delay(300);
}
byte requestByte(char dir){
Wire.beginTransmission(0x1D); // transmit to ADXL345
Wire.send(dir);
Wire.endTransmission(); // stop transmitting
Wire.requestFrom(0x1D, 1); // request 1 byte from ADXL345
while(Wire.available()){
return(Wire.receive()); //
}
}
int getDir(char dir){
int var;
if(dir==‘x’){
var=requestByte(X0);
var=var+(requestByte(X1)<<8);
}else if(dir==‘y’){
var=requestByte(Y0);
var=var+(requestByte(Y1)<<8);
}else if(dir==‘z’){
var=requestByte(Z0);
var=var+(requestByte(Z1)<<8);
}
return(var);
}

