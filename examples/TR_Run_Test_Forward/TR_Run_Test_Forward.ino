/*************************************** 
Waveshare AlphaBot Car Run Test

CN: www.waveshare.net/wiki/AlphaBot
EN: www.waveshare.com/wiki/AlphaBot
****************************************/
#include "AlphaBot.h" 

AlphaBot Car1 = AlphaBot(); 

void setup()
{
  Car1.SetSpeed(100); 
}

void loop()
{  

  Car1.Forward(1000);  
}
