#pragma config(Motor,  port1,           BtmIntake,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           LeftDrive,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           LBtmL,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LMidL,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RMidL,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RBtmL,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RUpL,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LUpL,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           RightDrive,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          UpIntake,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
void drive (int speed, int time)
{
	motor[LeftDrive] = speed;
	motor[RightDrive] = speed;
	wait1Msec(time);
	motor[LeftDrive] = 0;
	motor[RightDrive] = 0;


}
void flywheelSpeed (int flyspeed)
{
	motor[LBtmL] = flyspeed;
	motor[LMidL] = flyspeed;
	motor[LUpL]  = flyspeed;
	motor[RBtmL] = flyspeed;
	motor[RMidL] = flyspeed;
	motor[RUpL]  = flyspeed;

	motor[LBtmL] = 0;
	motor[LMidL] = 0;
	motor[LUpL]  = 0;
	motor[RBtmL] = 0;
	motor[RMidL] = 0;
	motor[RUpL]  = 0;
}


void stopfly()
{
	flywheelSpeed(70);
	wait1Msec(500);
	flywheelSpeed(50);
	wait1Msec(500);
	flywheelSpeed(0);
}
void startfly()
{
	if(vexRT(Btn7D) == 1)
	{
	flywheelSpeed(50);
	wait1Msec(500);
	flywheelSpeed(60);
	wait1Msec(500);
	flywheelSpeed(70);
	}
	if(vexRT(Btn7R) == 1)
	{
		stopfly();
	}

}
void stopDrive()
{
	motor[LeftDrive]	= 0;
	motor[RightDrive] = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
 	drive(127, 100);
 	stopDrive();
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		motor[LeftDrive]= vexRT[Ch3];
		motor[RightDrive] = vexRT[Ch2];

	}
}