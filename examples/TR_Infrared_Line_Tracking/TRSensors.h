/*
  QTRSensors.h - Library for using Pololu QTR reflectance
	sensors and reflectance sensor arrays: QTR-1A, QTR-8A, QTR-1RC, and 
	QTR-8RC.  The object used will determine the type of the sensor (either
	QTR-xA or QTR-xRC).  Then simply specify in the constructor which 
	Arduino I/O pins are connected to a QTR sensor, and the read() method
	will obtain reflectance measurements for those sensors.  Smaller sensor
	values correspond to higher reflectance (e.g. white) while larger
	sensor values correspond to lower reflectance (e.g. black or a void).
	
	* QTRSensorsRC should be used for QTR-1RC and QTR-8RC sensors.
	* QTRSensorsAnalog should be used for QTR-1A and QTR-8A sensors.
*/
	
/*
 * Written by Ben Schmidel et al., October 4, 2010
 * Copyright (c) 2008-2012 Pololu Corporation. For more information, see
 *
 *   http://www.pololu.com
 *   http://forum.pololu.com
 *   http://www.pololu.com/docs/0J19
 *
 * You may freely modify and share this code, as long as you keep this
 * notice intact (including the two links above).  Licensed under the
 * Creative Commons BY-SA 3.0 license:
 *
 *   http://creativecommons.org/licenses/by-sa/3.0/
 *
 * Disclaimer: To the extent permitted by law, Pololu provides this work
 * without any warranty.  It might be defective, in which case you agree
 * to be responsible for all resulting costs and damages.
 */

#ifndef TRSensors_h
#define TRSensors_h

#include "Arduino.h"

#define QTR_EMITTERS_OFF 0
#define QTR_EMITTERS_ON 1
#define QTR_EMITTERS_ON_AND_OFF 2

#define QTR_NO_EMITTER_PIN	255

#define QTR_MAX_SENSORS 16

// This class cannot be instantiated directly (it has no constructor).
// Instead, you should instantiate one of its two derived classes (either the
// QTR-A or QTR-RC version, depending on the type of your sensor).
class TRSensors
{
  public:
	
  TRSensors();
	// Reads the sensor values into an array. There *MUST* be space
	// for as many values as there were sensors specified in the constructor.
	// Example usage:
	// unsigned int sensor_values[8];
	// sensors.read(sensor_values);
	// The values returned are a measure of the reflectance in abstract units,
	// with higher values corresponding to lower reflectance (e.g. a black
	// surface or a void).
	// If measureOffAndOn is true, measures the values with the
	// emitters on AND off and returns on - (timeout - off).  If this
	// value is less than zero, it returns zero.
	// This method will call the appropriate derived class' readPrivate(), as
	// determined by the _type data member.  Making this method virtual
	// leads to compiler warnings, which is why this alternate approach was
	// taken.
 void AnalogRead(unsigned int *sensor_values);
  
	// Reads the sensors for calibration.  The sensor values are
	// not returned; instead, the maximum and minimum values found
	// over time are stored internally and used for the
	// readCalibrated() method.
	void calibrate();

	// Returns values calibrated to a value between 0 and 1000, where
	// 0 corresponds to the minimum value read by calibrate() and 1000
	// corresponds to the maximum value.  Calibration values are
	// stored separately for each sensor, so that differences in the
	// sensors are accounted for automatically.
	void readCalibrated(unsigned int *sensor_values);

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
	int readLine(unsigned int *sensor_values, unsigned char white_line = 0);

	// Calibrated minumum and maximum values. These start at 1000 and
	// 0, respectively, so that the very first sensor reading will
	// update both of them.
	//
	// The pointers are unallocated until calibrate() is called, and
	// then allocated to exactly the size required.  Depending on the
	// readMode argument to calibrate, only the On or Off values may
	// be allocated, as required.
	//
	// These variables are made public so that you can use them for
	// your own calculations and do things like saving the values to
	// EEPROM, performing sanity checking, etc.
  unsigned char _numSensors;
	unsigned int *calibratedMin;
	unsigned int *calibratedMax;

};

#endif
