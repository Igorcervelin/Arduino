#include <AFMotor.h>

// Igor Fabri Cervelin
// Controle remoto de motores

AF_DCMotor motor1(1); // motor 1 conectado na M1 do Shield
AF_DCMotor motor2(4); // motor 2 conectado na M4 do Shield

int vel = 40; //Seta as velocidades padrões como 60
int S1 = 8;
int Valor_S1 = 0; 
int S2 = 9; 
int Valor_S2 = 0;

void setup(){
  
  Serial.begin(9600);

  motor1.setSpeed(50);
  motor2.setSpeed(55);

  motor1.run(RELEASE); //Inicia com os motores desligados
  motor2.run(RELEASE);
}


void loop() {

  Valor_S1 = analogRead(S1);
  Valor_S2 = analogRead(S2); 
  bt = Serial.read();
  
    if((Valor_S1 < 600) && (Valor_S2 > 600)){
      motor2.setSpeed(60);
      motor2.run(BACKWARD);
      motor1.setSpeed(20); 
      motor1.run(BACKWARD);
    }
    
    if((Valor_S1 > 600) && (Valor_S2 < 600)){
      motor1.setSpeed(50);
      motor2.setSpeed(20);
      motor2.run(RELEASE); 
      motor1.run(BACKWARD);
    }

    if((Valor_S1 < 600) && (Valor_S2 < 600)){
      motor1.setSpeed(50);
      motor2.setSpeed(55);
      motor1.run(BACKWARD); 
      motor2.run(BACKWARD);
    }

    if((Valor_S1 > 600) && (Valor_S2 > 600)){
      motor1.setSpeed(50);
      motor2.setSpeed(55);
      motor1.run(BACKWARD); 
      motor2.run(BACKWARD);
    }
 }
