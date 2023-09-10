/*************************************** 
Waveshare AlphaBot Car Infrared Line Tracking

CN: www.waveshare.net/wiki/AlphaBot
EN: www.waveshare.com/wiki/AlphaBot
****************************************/
#include "TRSensors.h"
#include "AlphaBot.h" 

AlphaBot Car1 = AlphaBot(); 

#define NUM_SENSORS 5 
// sensors 0 through 5 are connected to analog inputs 0 through 5, respectively
TRSensors trs =   TRSensors(); 
unsigned int sensorValues[NUM_SENSORS]; 
int time = 50;
int threshold = 500;

void setup() 
{
  Car1.SetSpeed(100);   
  Serial.begin(115200); 
  Serial.println("TRSensor example");
  
  for (int i = 0; i < 400; i++)                  
  {
    trs.calibrate();                           
  }
  Serial.println("calibrate done");
  
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print("calibratedMin: ");
    Serial.print(trs.calibratedMin[i]);
    Serial.println();
  }
  Serial.println();
  
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print("calibratedMax: ");
    Serial.print(trs.calibratedMax[i]);
    Serial.print(' ');
  }
  Serial.println();
  delay(1000);
}
int centerValue =0;
int rightValue1=0;
int rightValue2=0;
int leftValue1=0;
int leftValue2=0;

void loop()
{
  trs.AnalogRead(sensorValues);
  leftValue1 = sensorValues[0];
  leftValue2 = sensorValues[1];
  centerValue = sensorValues[2];
  rightValue1 = sensorValues[3];
  rightValue2 = sensorValues[4];
   for (unsigned char i = 0; i < NUM_SENSORS; i++)
   {
     Serial.print("sensorValues ");Serial.print(i); Serial.print('\t');
     Serial.print(sensorValues[i]);
     Serial.println();
   }
  delay(1000);
}
