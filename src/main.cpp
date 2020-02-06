#include <Arduino.h>

#define BUZZER_PIN 12
#define LED_PIN 11
#define LDR_PIN A0

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
}

void loop()
{
  int ldr_status = analogRead(LDR_PIN);

  if (ldr_status >= 400)
  {
    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);
  }
  else
  {
    tone(BUZZER_PIN, 2500);
    digitalWrite(LED_PIN, HIGH);
    delay(100);

    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
}