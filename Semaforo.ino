int botaoinicio = 0;
    
void setup() {

  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {

  botaoinicio = digitalRead(2);
  if(botaoinicio == 0){
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH); 
  }else{
    delay(3000);
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    delay(3000);
    digitalWrite(9, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(8, LOW);
    delay(6000);     
  }
}
