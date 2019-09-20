#define ldr A0 // Define o pino do sensor como sendo a entrada A0

int led = 13;
int ldrValor = 0;

void setup() {
  pinMode(led,OUTPUT); //define a porta 7 como saída
  pinMode(ldr,OUTPUT);
  Serial.begin(9600); //Inicia a comunicação serial
}

void loop() {
   ldrValor = analogRead(ldr); //O valor lido será entre 0 e 1023
   
   //se o valor lido for maior que 500, liga o led
   if (ldrValor < 100) { 
      digitalWrite(led,HIGH);
   // senão, apaga o led
   } else {
      digitalWrite(led,LOW);
   }
   
   //imprime o valor lido do LDR no monitor serial
  Serial.println(ldrValor);
  delay(2000);
}
