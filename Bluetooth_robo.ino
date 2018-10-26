#include "DualVNH5019MotorShield.h"

DualVNH5019MotorShield md;

int i=0;
int comando=0;
int flag=0;
int vel=150;//Velocidade (inicial 150)
char ultMov;

void stopIfFault()
{
  if (md.getM1Fault())
  {
    Serial.println("M1 fault");
    while(1);
  }
  if (md.getM2Fault())
  {
    Serial.println("M2 fault");
    while(1);
  }
}

void setup(){
  Serial.begin(9600);
  Serial.println("Dual VNH5019 Motor Shield");
  md.init();
}

char frente(int v){ md.setM1Speed(v); md.setM2Speed(v); stopIfFault(); return 'f';}
char re(int v){ md.setM1Speed(-v); md.setM2Speed(-v); stopIfFault(); return 'b';}
char esquerda(int v){ md.setM1Speed(-v); md.setM2Speed(v); stopIfFault(); return 'e';}
char direita(int v){ md.setM1Speed(v); md.setM2Speed(-v); stopIfFault(); return 'd';}

void parar(){
  if(ultMov=='f'){//para devagar
    int temp = vel; 
    while(temp>=0){
      temp-=5;
      frente(temp);
      delay(5);
    }
    frente(0);
  } else if(ultMov=='b'){
    int temp = vel; 
    while(temp>=0){
      temp-=5;
      re(temp);
      delay(5);
    }
    frente(0);
  } else if(ultMov=='e'){
    int temp = vel; 
    while(temp>=0){
      temp-=5;
      esquerda(temp);
      delay(5);
    }
    frente(0);
  } else if(ultMov=='d'){
    int temp = vel; 
    while(temp>=0){
      temp-=5;
      direita(temp);
      delay(5);
    }
    frente(0);
  }
  frente(0);
  ultMov='p';
}

void loop()
{
  //Serial.println("No Inicio do Loop");
  if(Serial.available()>0){
    comando = Serial.read();
    flag=0;
  }
  
  if(comando=='f'){
    if(ultMov=='f') 
      frente(vel);
    else{
      parar(); 
      int temp = 0; 
      while(temp<=vel){
        temp+=10;
        frente(temp);
        delay(50);
      }
      frente(vel);
      ultMov='f';
    }
    if(flag==0){
      Serial.println("Frente");
      flag=1;
    }
  } else if(comando=='b'){
    if(ultMov=='b') 
      re(vel);
    else{
      parar(); 
      int temp = 0; 
      while(temp<=vel){
        temp+=10;
        re(temp);
        delay(50);
      }
      re(vel);
      ultMov='b';
    }
    if(flag==0){
      Serial.println("Ré");
      flag=1;
    }
  }else if(comando=='e'){
    vel=100;
    if(ultMov=='e') 
      esquerda(vel);
    else{
      parar(); 
      int temp = 0; 
      while(temp<=vel){
        temp+=10;
        esquerda(temp);
        delay(10);
      }
      esquerda(vel);
      ultMov='e';
    }
    if(flag==0){
      Serial.println("Esquerda");
      flag=1;
    }
  } else if(comando=='d'){
    vel=100;
    if(ultMov=='d') 
      direita(vel);
    else{
      parar(); 
      int temp = 0; 
      while(temp<=vel){
        temp+=10;
        direita(temp);
        delay(50);
      }
      direita(vel);
      ultMov='d';
    }
    if(flag==0){
      Serial.println("Direita");
      flag=1;
    }
  } else if(comando=='+'){
    vel+=50;
    if(ultMov=='f'){
      frente(vel);
    }else if(ultMov=='b'){
      re(vel);
    }else if(ultMov=='e'){
      esquerda(vel);
    }else if(ultMov=='d'){
      direita(vel);
    }
    if(flag==0){
      Serial.print("Aumenta Velocidade: ");
      Serial.println(vel);
      Serial.print("Corrente M1: ");
      Serial.println(md.getM1CurrentMilliamps());
      Serial.print("Corrente M2: ");
      Serial.println(md.getM2CurrentMilliamps());
      flag=1;
    }
  } else if(comando=='-'){
    vel-=50;
    if(ultMov=='f'){
      frente(vel);
    }else if(ultMov=='b'){
      re(vel);
    }else if(ultMov=='e'){
      esquerda(vel);
    }else if(ultMov=='d'){
      direita(vel);
    }
    if(flag==0){
      Serial.print("Diminui Velocidade: ");
      Serial.println(vel);
      Serial.print("Corrente M1: ");
      Serial.println(md.getM1CurrentMilliamps());
      Serial.print("Corrente M2: ");
      Serial.println(md.getM2CurrentMilliamps());
      flag=1;
    }
  } else if(comando=='p'){
     parar(); 
  } else {
     //Serial.println("Comando não reconhecido.");
  }
}
