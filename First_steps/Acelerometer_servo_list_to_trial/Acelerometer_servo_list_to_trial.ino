#include <AcceleroMMA7361.h>
#include <Servo.h>

AcceleroMMA7361 accelero;
Servo miServo;
int x;
int y;
int z;
int angulo=90;

void setup()
{
  Serial.begin(9600);
  miServo.attach(9);
  accelero.begin(13, 12, 11, 10, A0, A1, A2);
  accelero.setARefVoltage(3.3);                   //sets the AREF voltage to 3.3V
  accelero.setSensitivity(LOW);                   //sets the sensitivity to +/-6G
  accelero.calibrate();
  
}

void loop()
{
  x = accelero.getXAccel();
  y = accelero.getYAccel();
  z = accelero.getZAccel();
  Serial.print("\nx: ");
  Serial.print(x);
  Serial.print(" \ty: ");
  Serial.print(y);
  Serial.print(" \tz: ");
  Serial.print(z);
  Serial.print("\tG*10^-2");
  angulo=constrain(angulo,0,180);
  miServo.write((angulo+y*0.5));
  delay(100);                                     //make it readable
}
