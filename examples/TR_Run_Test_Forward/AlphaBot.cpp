#include "AlphaBot.h"

#define DefaultSpeed 255

char AlphaBot::LSpeed = DefaultSpeed;
char AlphaBot::RSpeed = DefaultSpeed;

//  Default Arduino Car pin define
AlphaBot::AlphaBot()
{  
  LMotorSpeedPin = 5;             //Left Motor Speed pin (ENA)
  LMotorForward = A1;             //Motor-L forward (IN1).
  LMotorBackward = A0;            //Motor-L backward (IN2)
  
  RMotorSpeedPin = 6;             //Right Motor Speed pin (ENB)
  RMotorForward = A2;             //Motor-R forward (IN4)
  RMotorBackward = A3;            //Motor-R backward (IN3)
  
  pinMode(LMotorSpeedPin,OUTPUT);                     
  pinMode(LMotorForward,OUTPUT);      
  pinMode(LMotorBackward,OUTPUT);
  
  pinMode(RMotorSpeedPin,OUTPUT);       
  pinMode(RMotorForward,OUTPUT);     
  pinMode(RMotorBackward,OUTPUT);  

}

//AlphaBot::AlphaBot(int LSpeedPin = 5,int L1 = A0,int L2 = A1 ,int RSpeedPin = 6,int R1 = A3,int R2 = A2)
AlphaBot::AlphaBot(int LSpeedPin,int L1,int L2,int RSpeedPin,int R1,int R2)
{
  this->LMotorSpeedPin = LSpeedPin;             
  this->LMotorForward = L1;            
  this->LMotorBackward = L2;
  
  this->RMotorSpeedPin = RSpeedPin;       
  this->RMotorForward = R1;           
  this->RMotorBackward = R2;       
  
  pinMode(LMotorSpeedPin,OUTPUT);                     
  pinMode(LMotorForward,OUTPUT);      
  pinMode(LMotorBackward,OUTPUT);
  
  pinMode(RMotorSpeedPin,OUTPUT);       
  pinMode(RMotorForward,OUTPUT);     
  pinMode(RMotorBackward,OUTPUT); 
}


//drive the left motor run forward
void AlphaBot::LeftMotorForward(char inLSpeed = LSpeed)
{
  analogWrite(LMotorSpeedPin,inLSpeed);                
  digitalWrite(LMotorForward,HIGH);  					
  digitalWrite(LMotorBackward,LOW); 
}

//drive the left motor run backward
void AlphaBot::LeftMotorBackward(char inLSpeed = LSpeed)
{
  analogWrite(LMotorSpeedPin,inLSpeed);                
  digitalWrite(LMotorForward,LOW);  					
  digitalWrite(LMotorBackward,HIGH); 
}

//drive the left motor stop
void AlphaBot::LeftMotorStop()
{
  digitalWrite(LMotorSpeedPin,LOW);               
}

//drive the right motor run forward
void AlphaBot::RightMotorForward(char inRSpeed = RSpeed)
{
  analogWrite(RMotorSpeedPin,inRSpeed);               
  digitalWrite(RMotorForward,HIGH);   				  
  digitalWrite(RMotorBackward,LOW);
}

//drive the right motor run backward
void AlphaBot::RightMotorBackward(char inRSpeed = RSpeed)
{
  analogWrite(RMotorSpeedPin,inRSpeed);               
  digitalWrite(RMotorForward,LOW);   				   
  digitalWrite(RMotorBackward,HIGH);
}

bool AlphaBot::MotorRun(int LS,int RS)
{ 
  if(LS >= 0 && LS <= 255)
  {
    LeftMotorForward(LS);
  }
  if(LS < 0 && LS >= -255)
  {
    LeftMotorBackward(abs(LS));
  }
  
  if(RS >= 0 && RS <= 255)
  {
    RightMotorForward(RS);
  }
  if(RS < 0 && RS >= -255)
  {
    RightMotorBackward(abs(RS));
  }
  if (RS > 255 || RS < -255 || LS > 255 || LS < -255)
  {
    return false;
  }
  
  return true;
}

//drive the right motor stop
void AlphaBot::RightMotorStop()
{
  digitalWrite(RMotorSpeedPin,LOW);             
}

//drive the car run forward
void AlphaBot::Forward()
{
  LeftMotorForward();
  RightMotorForward();
}

//drive the car run forward
void AlphaBot::Forward(unsigned int DelayMS)
{
  Forward();  
  delay(DelayMS);
  Brake();
}

//drive the car run backward
void AlphaBot::Backward()
{
  LeftMotorBackward();
  RightMotorBackward();
}

void AlphaBot::Backward(unsigned int DelayMS)
{
  Backward();  
  delay(DelayMS);
  Brake();
}

//drive the car turn left
void AlphaBot::Left()
{
  LeftMotorStop();
  RightMotorForward();
}

void AlphaBot::Left(unsigned int DelayMS)
{
  Left();  
  delay(DelayMS);
  Brake();
}

//drive the car turn right
void AlphaBot::Right()
{
  RightMotorStop();
  LeftMotorForward();
}

void AlphaBot::Right(unsigned int DelayMS)
{
  Right();  
  delay(DelayMS);
  Brake();
}

//drive the car left circle
void AlphaBot::LeftCircle()
{
  LeftMotorBackward();
  RightMotorForward();
}

void AlphaBot::LeftCircle(unsigned int DelayMS)
{
  LeftCircle();  
  delay(DelayMS);
  Brake();
}

//drive the car Right circle
void AlphaBot::RightCircle()
{
  LeftMotorForward();
  RightMotorBackward();
}

void AlphaBot::RightCircle(unsigned int DelayMS)
{
  RightCircle();  
  delay(DelayMS);
  Brake();
}

//drive the car brake
void AlphaBot::Brake()
{
   LeftMotorStop();
   RightMotorStop();
}

//reset the speed of the car
void AlphaBot::SetSpeed(char LSpeed,char RSpeed)
{
  this->LSpeed = LSpeed;
  this->RSpeed = RSpeed;
  analogWrite(RMotorSpeedPin,RSpeed);  
  analogWrite(LMotorSpeedPin,LSpeed);   
}

//reset the speed of the car
void AlphaBot::SetSpeed(char Speed)
{
  this->LSpeed = Speed;
  this->RSpeed = Speed;
  analogWrite(RMotorSpeedPin,RSpeed);  
  analogWrite(LMotorSpeedPin,LSpeed); 
}

void AlphaBot::SetRSpeed(char Speed)
{
  this->RSpeed = Speed;
  analogWrite(RMotorSpeedPin,RSpeed);                
}

void AlphaBot::SetLSpeed(char Speed)
{
  this->LSpeed = Speed;
  analogWrite(LMotorSpeedPin,LSpeed);                  
}




