// Igor Cervelin
// Exemplo piscar Led com potênciomentro

int delayVar = 0;
int potenciometroVar = 0;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  analogWrite(13, HIGH);
  delay(delayVar);
  analogWrite(13, LOW);
  delay(delayVar);
}
