int x; // x axis variable
int y; // y axis variable
int z; // z axis variable
void setup()
{ 
   Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}


float val2g(int val)
{
  // Raw ADC Value in +/- 1.5g Mode is converted to mV, mV is divided by sensitivity(800) to return a value in g
  return ((((val/1023.0)*5000.0)/800.0)-2.0625);  
}

void loop()
{
  x = analogRead(5); // read A5 input pin
  y = analogRead(4); // read A4 input pin
  z = analogRead(3); // read A3 input pin
  Serial.print("X = "); // print x adc value
  //Serial.println(val2g(x));
  Serial.println(x);
  Serial.print("Y = "); // print y adc value
  //Serial.println(val2g(y));
  Serial.println(y);
  Serial.print("Z = "); // print z adc value
  //Serial.println(val2g(z));
  Serial.println(z);
  delay(100);
}
