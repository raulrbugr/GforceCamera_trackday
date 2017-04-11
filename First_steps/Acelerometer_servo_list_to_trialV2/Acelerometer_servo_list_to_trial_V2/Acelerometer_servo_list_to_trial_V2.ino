#include <AcceleroMMA7361.h>
#include <Servo.h>

AcceleroMMA7361 accelero;
Servo miServo;
int x;
int y,yant,yant2;
int z;
int angulo=90,multiplicador=0;

void setup()
{
  Serial.begin(9600);
  miServo.attach(9);
  accelero.begin(13, 12, 11, 10, A0, A1, A2);
  accelero.setARefVoltage(3.3);                   //sets the AREF voltage to 3.3V
  accelero.setSensitivity(LOW);                   //sets the sensitivity to +/-6G
  accelero.calibrate();
  yant= accelero.getYAccel();
  yant2=yant;
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
  /*if((y > yant +25 ) && (y > yant2 +25)){
    //Que el multiplicador sea la diferencia de valores
    //multiplicador= y-
    angulo=constrain(angulo,0,180);
    miServo.write((angulo+y*0.25));
    delay(300);   
  } 
  else if((y < yant -25)&&(y < yant2 -25  )){
    angulo=constrain(angulo,0,180);
    miServo.write((angulo+y*0.25));
    delay(300);   
  }*/

  y=(y+yant+yant2)/3;

  if(y <= 10 &&  y >= -10){
    angulo=constrain(angulo,0,180);
    miServo.write(90);
    delay(300);
  }

  
  if((y > 10 && y <= 25) || (y < -10 && y >= -25)){
    if(y >0){
      miServo.write(110);
      delay(300);  
    }
    else{
      miServo.write(70);
      delay(300); 
    }
  }

  if((y > 25 && y <= 40) || (y < -25 && y >= -40)){
    if(y >0){
      miServo.write(130);
      delay(300);  
    }
    else{
      miServo.write(50);
      delay(300); 
    }
  }
  
 // delay(200);   
 //make it readable
 yant = y;
 yant2=yant;
}
