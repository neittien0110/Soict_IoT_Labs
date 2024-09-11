#ifndef AlphaBot_h
#define AlphaBot_h

#include "AlphaBot.h"
#include "Arduino.h"

class AlphaBot
{
  public:
  /////////////////////////////////////////////////////////////////
  AlphaBot();
  AlphaBot(int LSpeedPin,int L1,int L2,int RSpeedPin,int R1,int R2);
  bool MotorRun(int LS,int RS); 
  void Forward();
  void Forward(unsigned int DelayMS);
  void Backward();
  void Backward(unsigned int DelayMS);
  void Left();
  void Left(unsigned int DelayMS);
  void Right();
  void Right(unsigned int DelayMS);
  void RightCircle();
  void RightCircle(unsigned int DelayMS);
  void LeftCircle();
  void LeftCircle(unsigned int DelayMS);
  void Brake();
  void SetSpeed(char Speed);
  void SetSpeed(char LSpeed,char RSpeed);
  void SetRSpeed(char Speed);
  void SetLSpeed(char Speed);
  /////////////////////////////////////////////////////////////////
  
  private:
  /////////////////////////////////////////////////////////////////
  int RMotorSpeedPin;            //Right Motor Speed pin (ENA)
  int RMotorBackward;           //Motor-R backward (IN1)
  int RMotorForward;           //Motor-R forward (IN2).
  int LMotorSpeedPin;             //Left Motor Speed pin (ENB)
  int LMotorForward;            //Motor-L forward (IN3)
  int LMotorBackward;           //Motor-L backward (IN4)
  /////////////////////////////////////////////////////////////////
  static char LSpeed,RSpeed;
//  char RSpeed;

  /////////////////////////////////////////////////////////////////
  void LeftMotorForward(char inLSpeed);
  void LeftMotorBackward(char inLSpeed);
  void LeftMotorStop();
  void RightMotorForward(char inRSpeed);
  void RightMotorBackward(char inRSpeed);
  void RightMotorStop();

};
#endif
