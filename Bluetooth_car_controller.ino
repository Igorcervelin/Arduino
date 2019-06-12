#include <AFMotor.h>

AF_DCMotor motor1(1); // motor 1 conectado na M1 do Shield
// Igor Fabri Cervelin
// Controle remoto de motores

AF_DCMotor motor2(4); // motor 2 conectado na M4 do Shield

char bt='s'; // bt (Botão associado) inicia como s (stop) por padrão
int vel = 60; //Seta as velocidades padrões como 60

void setup(){
  
  Serial.begin(9600);

  motor1.setSpeed(60);
  motor2.setSpeed(61);

  motor1.run(RELEASE); //Inicia com os motores desligados
  motor2.run(RELEASE);
}


void loop() {
 
bt = Serial.read();

if(bt == 'f'){
  delay(400);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

if(bt == 'b'){
  delay(400);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

if(bt == 'l'){
  delay(400);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}

if(bt == 'r'){
  delay(400);
  motor1.run(BACKWARD);
  motor2.run(FORWARD); 
}

if(bt == 's'){
  delay(400);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

if(bt == '+'){
  vel += 5;
  motor1.setSpeed(vel);
  motor2.setSpeed(vel);
}

if(bt == '-'){
  vel -= 5;
  motor1.setSpeed(vel);
  motor2.setSpeed(vel);
}

}
