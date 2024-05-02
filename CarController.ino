#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Motor A
int motor1Pin1 = 27;
int motor1Pin2 = 26;
int enable1Pin = 25;
const int pwm1Channel = 0;

// Motor B
int motor2Pin1 = 14;
int motor2Pin2 = 12;
int enable2Pin = 13;
const int pwm2Channel = 1;

// Setting PWM properties
const int freq = 30000;
const int resolution = 8;

void setup()
{
  // sets the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  // configure LED PWM functionalitites
  ledcSetup(pwm1Channel, freq, resolution);
  ledcSetup(pwm2Channel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwm1Channel);
  ledcAttachPin(enable2Pin, pwm2Channel);

  Serial.begin(115200);
  Dabble.begin("Mit.thui-car");
  // testing
  Serial.print("Testing DC Motor...");
  ledcWrite(pwm1Channel, 255);
  ledcWrite(pwm2Channel, 255);
}

void loop()
{
  Dabble.processInput();
  if (GamePad.isUpPressed())
  {
    Serial.println("Moving Forward");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);

    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
  }
  else if (GamePad.isDownPressed())
  {
    Serial.println("Moving Backwards");
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);

    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
  }
  else if (GamePad.isLeftPressed())
  {
    Serial.println("Moving Left");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);

    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
  }
  else if (GamePad.isRightPressed())
  {
    Serial.println("Moving Right");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);

    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
  }
  else
  {
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);

    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
  }
  delay(100);
}