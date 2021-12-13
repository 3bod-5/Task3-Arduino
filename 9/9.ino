#define EN 10
#define IN1 9
#define IN2 8

int motor_speed = 0;
int pedal = A0;
const int buttonPin = 2;
void setup()
{
  pinMode(IN1, OUTPUT); // motor pin 1
  pinMode(IN2, OUTPUT); // motor pin 2
  pinMode(EN, OUTPUT); // motor PWM pin
  pinMode(pedal,INPUT); // potentiometer pin
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); 
}

void loop()
{
  int buttonState = 0;
  int pedalValue = analogRead(pedal);
  delay(1000);
  buttonState = digitalRead(buttonPin);
  
  motor_speed = map(pedalValue, 0, 1024, 0, 255);
 
  
  if (buttonState == HIGH){
    if(motor_speed >= 0 && motor_speed <= 255)
       {
       digitalWrite(IN1,LOW);
       digitalWrite(IN2, HIGH);
       analogWrite(EN,motor_speed);
        Serial.print("RPM: ");
        Serial.println(motor_speed);
       }
  }else{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    analogWrite(EN,motor_speed);
  }
}
