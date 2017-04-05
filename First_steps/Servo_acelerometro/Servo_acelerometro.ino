
// Incluímos la librería para poder controlar el servo
#include <Servo.h>
// Declaramos la variable para controlar el servo
Servo servoMotor;
int x; // x axis variable
int y; // y axis variable
int z; // z axis variable
int xant,yant,zant;

void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(9);

  //Inicializamos el acelerometro
  x = analogRead(5); // read A5 input pin
  y = analogRead(4); // read A4 input pin
  z = analogRead(3); // read A3 input pin
  xant=x;
  yant=y;
  zant=z;
  
}

void loop() {
  
  x = analogRead(5); // read A5 input pin
  y = analogRead(4); // read A4 input pin
  z = analogRead(3); // read A3 input pin
  
   
  /*// Desplazamos a la posición 0º
  servoMotor.write(0);
  // Esperamos 1 segundo
  delay(1000);
  // Desplazamos a la posición 90º
  servoMotor.write(-90);
  // Esperamos 1 segundo
  delay(1000);
  // Desplazamos a la posición 180º
  servoMotor.write(180);
  // Esperamos 1 segundo
  delay(1000);*/
  
  if(xant - 100 > x){
    Serial.println("Entra");
     servoMotor.write(0);
     // Esperamos 1 segundo
    delay(1000);
    servoMotor.write(180);
    delay(1000);
  }
  //servoMotor.write(0);
  //delay(1000);

  Serial.print("X = "); // print x adc value
  Serial.println(x);
  Serial.print("Y = "); // print y adc value
  Serial.println(y);
  Serial.print("Z = "); // print z adc value
  Serial.println(z);
  delay(100);
  
  xant=x;
  yant=y;
  zant=z;
  
}
