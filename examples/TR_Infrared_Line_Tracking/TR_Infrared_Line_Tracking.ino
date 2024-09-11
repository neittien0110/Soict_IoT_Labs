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
int time = 100;
int threshold = 3500;

void setup()
{
  Car1.SetSpeed(100);       //Speed:0 - 255 thiet lap toc do cho xe
  
  Serial.begin(115200); // xac dinh gia tri baudrate cho cong serial 115200
  Serial.println("TRSensor example");
  
  for (int i = 0; i < 400; i++)                  // make the calibration take about 10 seconds
  {
    trs.calibrate();                             // reads all sensors 10 times
  }
  Serial.println("calibrate done");
  
  // print the calibration minimum values measured when emitters were on
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print("calibratedMin: ");
    Serial.print(trs.calibratedMin[i]);
    Serial.println();
  }
  Serial.println();
  
  // print the calibration maximum values measured when emitters were on
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
  // Get the position of the line.  Note that we *must* provide
  // the "sensors" argument to read_line() here, even though we
  // are not interested in the individual sensor readings.
  //Car1.SetSpeed(100);       //Speed:0 - 255 thiet lap toc do cho xe
  // xac dinh vi tri cua robot
 //unsigned int position = trs.readLine(sensorValues);
  trs.AnalogRead(sensorValues);
  leftValue1 = sensorValues[0];
  leftValue2 = sensorValues[1];
  centerValue = sensorValues[2];
  rightValue1 = sensorValues[3];
  rightValue2 = sensorValues[4];
  //Car1.Right(time);
  //Car1.Left(time);
  
   for (unsigned char i = 0; i < NUM_SENSORS; i++)
   {
     Serial.print("sensorValues ");Serial.print(i); Serial.print('\t');
     Serial.print(sensorValues[i]);
     Serial.println();
   }
   delay(100);
   if (centerValue < threshold && rightValue1 > threshold && rightValue2 > threshold && leftValue1 > threshold && leftValue2 > threshold) { // nếu cảm biến ở giữa nhận được ánh sáng
      Car1.Forward(time);  // robot di chuyển thẳng
      Serial.println("Forward");
    }
    else if(centerValue < threshold && rightValue1 < threshold && rightValue2 < threshold && leftValue1 < threshold && leftValue2 < threshold){
     Car1.Forward(time);
      Serial.println("Forward");
    }
    else if (leftValue1 < threshold || leftValue2 < threshold) // nếu cả hai cảm biến bên trái nhận được ánh sáng
    { 
     Car1.Right(time);  // robot rẽ trái
      Serial.println("Turn Left");
    }
    else if (rightValue1 < threshold || rightValue2 < threshold) // nếu cả hai cảm biến bên phải nhận được ánh sáng
    { 
      Car1.Left(time); // robot rẽ phải
      Serial.println("Turn Right");
    }
    else if(centerValue > threshold && rightValue1 > threshold && rightValue2 > threshold && leftValue1 > threshold && leftValue2 > threshold)
    {
      Car1.Backward(time);
      Serial.println("Backward");
    }
}
