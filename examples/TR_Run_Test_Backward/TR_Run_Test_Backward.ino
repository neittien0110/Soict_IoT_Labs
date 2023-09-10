/*************************************** 
Waveshare AlphaBot Car Run Test

CN: www.waveshare.net/wiki/AlphaBot
EN: www.waveshare.com/wiki/AlphaBot
****************************************/
#include "AlphaBot.h" // khai bao thu vien Aphabot

AlphaBot Car1 = AlphaBot(); // Khai bao 1 robot AlphaBot

void setup()
{
  Car1.SetSpeed(100);       //Speed:0 - 255 thiet lap toc do cho xe
}

void loop()
{  
  //delay(1000);
  Car1.Backward(1000);     //Car run forward for 1s
}
