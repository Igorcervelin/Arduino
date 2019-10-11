#include <Ultrasonic.h>
#include <AFMotor.h>

#define pino_trigger A8
#define pino_echo A9

// Igor Fabri Cervelin
// Controle remoto de motores

AF_DCMotor motor1(1); // motor 1 conectado na M1 do Shield
AF_DCMotor motor2(4); // motor 2 conectado na M4 do Shield

char bt = 's'; // bt (Botão associado) inicia como s (stop) por padrão
int vel = 60; //Seta as velocidades padrões como 60
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup(){
  
  Serial.begin(9600);
  pinMode(pino_echo, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
  pinMode(pino_trigger, OUTPUT); //DEFINE O PINO COMO SAIDA (ENVIA)
  Serial.println("Lendo dados do sensor...");

  motor1.setSpeed(60);
  motor2.setSpeed(61);

  motor1.run(RELEASE); //Inicia com os motores desligados
  motor2.run(RELEASE);
}


void loop() {

  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  delay(1000);

  bt = Serial.read();
  
  if(bt == 'f'){
    delay(400);
    if(cmMsec >= 11.0){
     motor1.run(FORWARD);
     motor2.run(FORWARD); 
    }
  }
  
  if(bt == 'b'){
    delay(400);
    if(cmMsec >= 11.0){
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
    }
    
  }
  
  if(bt == 'l'){
    delay(400);
    if(cmMsec >= 11.0){
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
    }  
  }
  
  if(bt == 'r'){
    delay(400);
    if(cmMsec >= 11.0){
      motor1.run(FORWARD);
      motor2.run(BACKWARD); 
    }
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
