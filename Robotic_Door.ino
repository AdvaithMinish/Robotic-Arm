// DOOR AUTOMATION USING ROBOTIC ARM
#include <Servo.h>

const int ProxSensor1 = A4; // IR SENSOR INPUT FROM OUTSIDE THE DOOR
const int ProxSensor2 = A5; // IR SENSOR INPUT FROM INSIDE THE HALL

int inputVal1 = 0; 
int inputVal2 = 0;
int value_joint1;

Servo servo_joint1; // SERVO INITIALISING

void setup() 
{
  
  pinMode(ProxSensor1,INPUT);  // CONFIGURING THE INPUT PORTS
  pinMode(ProxSensor2,INPUT);  // CONFIGURING THE INPUT PORTS
  pinMode(13, OUTPUT);
  servo_joint1.attach(4); //CONFIGURING THE OUTPUT PORTS
  Serial.begin(9600);
  
}

void loop()
{
  
  int x = 0; // VALUE INITIALISING FOR THE DOOR OPEING AND CLOSING
  inputVal1 = analogRead(ProxSensor1);
  inputVal2 = analogRead(ProxSensor2);
  
  
  if(((digitalRead(ProxSensor1)==HIGH) && (digitalRead(ProxSensor2) == LOW)) || ((digitalRead(ProxSensor2)==HIGH) &&(digitalRead(ProxSensor1) == LOW)) || ((digitalRead(ProxSensor2)==HIGH) &&(digitalRead(ProxSensor1) == HIGH)))
  {
    
   delay(2000);
   
   x = 1020; // OPENING THE DOOR
   value_joint1 = map(x, 1023, 600, 30, 160);
   servo_joint1.write(value_joint1);
   delay(6000);
   
   x = 0; // CLOSING THE  DOOR
   value_joint1 = map(x, 1023, 600, 30, 160);
   servo_joint1.write(value_joint1);
   delay(1000);
   
  }

  else
  {
    
  digitalWrite(13,LOW);
  
  }

}
