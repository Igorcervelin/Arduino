#include <Ultrasonic.h>
 
#define pino_trigger 4
#define pino_echo 5
 
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Reading");
}
 
void loop()
{
  float cm, pol;
  long microsec = ultrasonic.timing();
  cm = ultrasonic.convert(microsec, Ultrasonic::CM);
  pol = ultrasonic.convert(microsec, Ultrasonic::IN);
  
  Serial.print("Distancia em cm: ");
  Serial.print(cm);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(pol);
  delay(350);
}
