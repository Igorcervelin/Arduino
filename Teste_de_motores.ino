#include <AFMotor.h>

// Define o motor1 ligado a conexao 1
AF_DCMotor motor1(1); 
// Define o motor2 ligado a conexao 4
AF_DCMotor motor2(4); 
 
void setup()
{
  // Define a velocidade maxima para os motores 1 e 2
  motor1.setSpeed(64); 
  motor2.setSpeed(64); 

}
 
void loop()
{
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
 
  delay(500);

  // Desliga os 2 motores
  motor1.run(RELEASE); 
  motor2.run(RELEASE); 
  delay(1100);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD); 
 
  delay(500);
  
  // Desliga os 2 motores
  motor1.run(RELEASE); 
  motor2.run(RELEASE);

  delay(1100);
}
