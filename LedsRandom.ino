int led = 0;

void setup() {

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}


void loop() {
  
  led = random(8, 13);
  digitalWrite(led, HIGH);
  delay(300);
  digitalWrite(led, LOW);
  delay(500);

}
