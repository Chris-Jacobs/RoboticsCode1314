#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IR1,            sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     IR2,            sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     left,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     arm,           tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     susan,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     flag,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an TETRIX robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//   1. Have the robot follow a line on the game field until it reaches one of the puck storage
//      areas.
//   2. Load pucks into the robot from the storage bin.
//   3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  //initializeRobot();

  waitForStart(); // Wait for the beginning of autonomous phase.
	sleep(15000);
  	ClearTimer(T1);
	int threshold = 0;
	while(threshold == 0)
	{
		//nxtDisplayTextLine(0,"IR1 %d",SensorValue[IR1]);
		//nxtDisplayTextLine(3,"IR2 %d",SensorValue[IR2]);


		if(SensorValue[IR1] == 5 && SensorValue[IR2] ==5 )
		{

			motor[left] = 0;
			motor[right] = 0;
			wait1Msec(500);

				if(time1[T1] > 2500 && threshold == 0  )
				{
					//nxtDisplayTextLine(0,"time %d", time1[T1]);
					// if the time is bigger than 2s meaning beacon is at spot 3 or 4
					motor[left] = 70;
					motor[right] = 70;
					wait1Msec(200);
					ClearTimer(T1);
					motor[left] = 0;
					motor[right] = 0;

				}


					wait1Msec(500);
					//servo[servo1] =	-300; //for hanging
				motor[left]=-70;
				motor[right]=-70;
				wait1Msec(400);
				motor[left]=0;
				motor[right]=0;
				motor[arm] = -40;
			Sleep(750);
			motor[arm] = 0;
			Sleep(750);
			motor[arm] = 60;
			Sleep(500);
			motor[arm] = 0;
					threshold = 5;

		}
//	motor[leftMotor] = -75;
//	motor[rightMotor] = -75;


		else
		{
			motor[left] = -55;
			motor[right] = -75;

		}
	}


//	while(threshold == 5)//go back
//	{
//	if(SensorValue[Touch] == 1)
//			{
//			motor[leftMotor] = 0;
//			motor[rightMotor] = 0;

//			wait1Msec(200);

//			threshold = 2;
//			}

//	else
//			{
//				//wait1Msec(1000);
//				//servo[Cubes] = 0;
//				motor[leftMotor] = -75;
//				motor[rightMotor] = -100;
//			}
//	}

//	while(threshold == 2)//go to bridge.
//	{
//			motor[leftMotor] = 100;
//			motor[rightMotor] = -100;
//			wait1Msec(600);

//			motor[leftMotor] = -75;
//			motor[rightMotor] = -100;
//			wait1Msec(2000);

//			motor[leftMotor] = 100;
//			motor[rightMotor] = -100;
//			wait1Msec(600);

//			motor[leftMotor] = -75;
//			motor[rightMotor] = -100;
//			wait1Msec(2800);

//			threshold = 3;
//	}
}
