/*  QTRSensors.h - Library for using Pololu QTR reflectance
	sensors and reflectance sensor arrays
 * Copyright (c) 2008-2012 waveshare Corporation. For more information, see
 *
 *   http://www.waveshare.com
 *
 * You may freely modify and share this code, as long as you keep this
 * notice intact.  
 *
 * Disclaimer: To the extent permitted by law, waveshare provides this work
 * without any warranty.  It might be defective, in which case you agree
 * to be responsible for all resulting costs and damages.
 */

#include <Arduino.h>
#include "TRSensors.h"

#define Clock     13
#define Address   12
#define DataOut   11
#define CS        10

#define NUMSENSORS 5
// Base class data member initialization (called by derived class init())
TRSensors::TRSensors()
{
	pinMode(Clock, OUTPUT);
	pinMode(Address, OUTPUT);
	pinMode(DataOut, INPUT);
  pinMode(CS, OUTPUT);  

	_numSensors = NUMSENSORS;
	
	calibratedMin = (unsigned int*)malloc(sizeof(unsigned int) * _numSensors);
	calibratedMax = (unsigned int*)malloc(sizeof(unsigned int) * _numSensors);
	
	for(int i=0;i<_numSensors;i++)
	{
		calibratedMin[i] = 4095;
		calibratedMax[i] = 0;
	}
}


// Reads the sensor values using TLC1543 or TLC2543 ADC chip into an array. 
// The values returned are a measure of the reflectance in abstract units,
// with higher values corresponding to lower reflectance (e.g. a black
// surface or a void).
//-TLC1543 Old ver Alphabot
// void TRSensors::AnalogRead(unsigned int *sensor_values)
// {
// 	char i,j;
// 	unsigned int channel = 0;
// 	unsigned int values[] = {0,0,0,0,0,0};

// 	for(j = 0;j < _numSensors + 1;j++)
// 	{
// 		digitalWrite(CS,LOW);
// 		for(i = 0;i < 10;i++) 
// 		{
// 			//0 to 4 clock transfer channel address
// 			if((i < 4) && (j >> (3 - i) & 0x01)) 
// 			digitalWrite(Address,HIGH);
// 			else
// 			digitalWrite(Address,LOW);

// 			//0 to 10 clock receives the previous conversion result
// 			values[j] <<= 1;
// 			if(digitalRead(DataOut)) 
// 			values[j] |= 0x01;
// 			digitalWrite(Clock,HIGH);
// 			digitalWrite(Clock,LOW);
// 		}
// 		//sent 11 to 16 clock 
// 		for(i = 0;i < 6;i++)
// 		{
// 			digitalWrite(Clock,HIGH);
// 			digitalWrite(Clock,LOW);
// 		}

// 		digitalWrite(CS,HIGH);
// 	}

// 	for(i = 0;i < _numSensors;i++)
// 	{
// 		sensor_values[i] = values[i+1];
// 	}
// }

//TLC2543C New Alphabot
void TRSensors::AnalogRead(unsigned int *sensor_values)
{
	char i,j;
	unsigned int channel = 0;
	unsigned int values[] = {0,0,0,0,0,0};

	for(j = 0;j < _numSensors + 1;j++)
	{
    digitalWrite(CS,HIGH);
    delayMicroseconds(3);
		digitalWrite(CS,LOW);
		for(i = 0;i < 12;i++) 
		{
			//0 to 4 clock transfer channel address
			if((i < 4) && (j >> (3 - i) & 0x01)) 
			digitalWrite(Address,HIGH);
			else
			digitalWrite(Address,LOW);

			//0 to 10 clock receives the previous conversion result
			values[j] <<= 1;
			if(digitalRead(DataOut)) 
			values[j] |= 0x01;
			digitalWrite(Clock,HIGH);
			digitalWrite(Clock,LOW);
		}
		//sent 11 to 16 clock 
		// for(i = 0;i < 6;i++)
		// {
		// 	digitalWrite(Clock,HIGH);
		// 	digitalWrite(Clock,LOW);
		// }

    // wait for conversion time
    delayMicroseconds(10);

		digitalWrite(CS,HIGH);
	}

	for(i = 0;i < _numSensors;i++)
	{
		sensor_values[i] = values[i+1];
	}
}


//TLC2543C New Alphabot
// void TRSensors::AnalogRead(unsigned int *sensor_values){
//   char i,j;
//   unsigned int channel = 0;
//   unsigned int value[] = {0,0,0,0,0,0};

//   for(j = 0; j < _numSensors + 1;j++){
//     // sent chip select
//     digitalWrite(CS,HIGH);
//     delayMicroseconds(3);
//     digitalWrite(CS,LOW);


//   }
// }

// Reads the sensors 10 times and uses the results for
// calibration.  The sensor values are not returned; instead, the
// maximum and minimum values found over time are stored internally
// and used for the readCalibrated() method.
void TRSensors::calibrate()
{
	int i;
	unsigned int sensor_values[_numSensors];
	unsigned int max_sensor_values[_numSensors];
	unsigned int min_sensor_values[_numSensors];

	int j;
	for(j=0;j<10;j++)
	{
		AnalogRead(sensor_values);
		for(i=0;i<_numSensors;i++)
		{
			// set the max we found THIS time
			if(j == 0 || max_sensor_values[i] < sensor_values[i])
				max_sensor_values[i] = sensor_values[i];

			// set the min we found THIS time
			if(j == 0 || min_sensor_values[i] > sensor_values[i])
				min_sensor_values[i] = sensor_values[i];
		}
	}
  
  // record the min and max calibration values
  for(i=0;i<_numSensors;i++)
  {
    if(min_sensor_values[i] > calibratedMax[i])
      calibratedMax[i] = min_sensor_values[i];
    if(max_sensor_values[i] < calibratedMin[i])
      calibratedMin[i] = max_sensor_values[i];
  }
}


// Returns values calibrated to a value between 0 and 1000, where
// 0 corresponds to the minimum value read by calibrate() and 1000
// corresponds to the maximum value.  Calibration values are
// stored separately for each sensor, so that differences in the
// sensors are accounted for automatically.
void TRSensors::readCalibrated(unsigned int *sensor_values)
{
	int i;

	// read the needed values
	AnalogRead(sensor_values);

	for(i=0;i<_numSensors;i++)
	{
		unsigned int calmin,calmax;
		unsigned int denominator;

		denominator = calibratedMax[i] - calibratedMin[i];

		signed int x = 0;
		if(denominator != 0)
			x = (((signed long)sensor_values[i]) - calibratedMin[i])
				* 1000 / denominator;
		if(x < 0)
			x = 0;
		else if(x > 1000)
			x = 1000;
		sensor_values[i] = x;
	}

}


// Operates the same as read calibrated, but also returns an
// estimated position of the robot with respect to a line. The
// estimate is made using a weighted average of the sensor indices
// multiplied by 1000, so that a return value of 0 indicates that
// the line is directly below sensor 0, a return value of 1000
// indicates that the line is directly below sensor 1, 2000
// indicates that it's below sensor 2000, etc.  Intermediate
// values indicate that the line is between two sensors.  The
// formula is:
// 
//    0*value0 + 1000*value1 + 2000*value2 + ...
//   --------------------------------------------
//         value0  +  value1  +  value2 + ...
//
// By default, this function assumes a dark line (high values)
// surrounded by white (low values).  If your line is light on
// black, set the optional second argument white_line to true.  In
// this case, each sensor value will be replaced by (1000-value)
// before the averaging.
int TRSensors::readLine(unsigned int *sensor_values, unsigned char white_line)
{
	unsigned char i, on_line = 0;
	unsigned long avg; // this is for the weighted total, which is long
	                   // before division
	unsigned int sum; // this is for the denominator which is <= 64000
	static int last_value=0; // assume initially that the line is left.

	readCalibrated(sensor_values);

	avg = 0;
	sum = 0;
  
	for(i=0;i<_numSensors;i++) {
		int value = sensor_values[i];

		if(!white_line)
			value = 1000-value;
		sensor_values[i] = value;
		// keep track of whether we see the line at all
		if(value > 300) {
			on_line = 1;
		}
		
		// only average in values that are above a noise threshold
		if(value > 50) {
			avg += (long)(value) * (i * 1000);
			sum += value;
		}
	}

	if(!on_line)
	{
		// If it last read to the left of center, return 0.
		 if(last_value < (_numSensors-1)*1000/2)
			 return 0;
		
		// If it last read to the right of center, return the max.
		 else
			 return (_numSensors-1)*1000;
	}

	last_value = avg/sum;

	return last_value;
}
