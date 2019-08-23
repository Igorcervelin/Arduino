// Igor Cervelin
// Exemplo piscar Led

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  analogWrite(13, HIGH);
  delay(1000);
  analogWrite(13, LOW);
  delay(1000);
}
