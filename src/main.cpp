#include <Arduino.h>
#include <button.h>

#define BUTTON_PIN 3
#define PWM_PIN LED_BUILTIN

Button button(BUTTON_PIN);

void setup() 
{
  Serial.begin(115200);

  button.init();
  pinMode(PWM_PIN, OUTPUT);
}

int motorSpeed = 0;

void loop() 
{
  if(button.checkButtonPress())
  {
    motorSpeed = 255 - motorSpeed;
    analogWrite(PWM_PIN, motorSpeed);
    Serial.println(motorSpeed);
  }
}
