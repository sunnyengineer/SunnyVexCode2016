#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  LeftDriveEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  RightDriveEncoder, sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  LauncherIME,    sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           BtmIntake,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           LeftDrive,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           LBtmL,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LMidL,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RMidL,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RBtmL,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RUpL,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LUpL,          tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port9,           RightDrive,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          UpIntake,      tmotorVex393_HBridge, openLoop)

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

//Variable that will carry between modes
int Program;

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

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
	//Leave this value alone
	int lcdScreenMin = 1;
	//This keeps track of which program you want to run
	int lcdScreen = 1;
	//Change this value to be the maximum number of programs you want on the robot
	int lcdScreenMax = 4;
	//Turns on the Backlight
	bLCDBacklight = true;

	//Copied from someone's sample code because the documentation for RobotC won't tell me anything useful
	//These should logically work, but I'm not 100% sure
	const short leftButton = 1;
	const short centerButton = 2;
	const short rightButton = 4;

	while (bIfiRobotDisabled == 1) { //Ensures this code will run ONLY when the robot is disabled
		if (nLCDButtons == leftButton) { //Scrolls to the left
			if (lcdScreenMin == lcdScreen) {
				lcdScreen = lcdScreenMax;
				wait1Msec(250);
			} else {
				lcdScreen --;
				wait1Msec(250);
			}
		}
		if (nLCDButtons == rightButton) { //Scrolls to the right
			if (lcdScreenMax == lcdScreen) {
				lcdScreen = lcdScreenMin;
				wait1Msec(250);
			} else {
				lcdScreen++;
				wait1Msec(250);
			}
		}
		if (lcdScreen == 1 && Program != 1) {
			displayLCDCenteredString (0, "Program"); //Name the first program here
			displayLCDCenteredString (1, "1"); //Name the first program here
			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
		} else if (lcdScreen == 1 && Program == 1) {
			displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[1]"); //So that while we're scrolling, we can have one marked
		} else if (lcdScreen == 2 && Program != 2) {
			displayLCDCenteredString (0, "Program"); //Name the second program here
			displayLCDCenteredString (1, "2"); //Name the second program here
			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
		} else if (lcdScreen == 2 && Program == 2) {
			displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[2]"); //So that while we're scrolling, we can have one marked
		} else if (lcdScreen == 3 && Program != 3) {
			displayLCDCenteredString (0, "Program"); //Name the third program here
			displayLCDCenteredString (1, "3"); //Name the third program here
			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
		} else if (lcdScreen == 3 && Program == 3) {
			displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[3]"); //So that while we're scrolling, we can have one marked
		} else if (lcdScreen == 4 && Program != 4) {
			displayLCDCenteredString (0, "Program"); //Name the fourth program here
			displayLCDCenteredString (1, "4"); //Name the fourth program here
			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
		} else if (lcdScreen == 4 && Program == 4) {
			displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[4]"); //So that while we're scrolling, we can have one marked
		}
	}

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
	if(Program == 1)
	{
		motor[LeftDrive] = -90;
		wait1Msec(3000);
		motor[LeftDrive] = 0;

		//Put your second program in here
	}
	else if(Program == 2)
	{
		motor[RightDrive] = 90;
		wait1Msec(3000);
		motor[RightDrive] = 0;
		//Put your second program in here
	}
	else if(Program == 3)
	{
		motor[RightDrive && LeftDrive] = 90;
		wait1Msec(3000);
		motor[RightDrive && LeftDrive] = 0;
		//Put your third program in here
	}
	else if(Program == 4)
	{
		motor[RightDrive] = 90;
		motor[LeftDrive]  = -90;
		wait1Msec(3000);
		motor[RightDrive] = 0;
		motor[LeftDrive]  = 0;

		//Pur your fourth program in here
	}
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................


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
		motor[LeftDrive] = vexRT(Ch3);
		motor[RightDrive]= vexRT(Ch2);
	   // Remove this function call once you have "real" code.
	}
}
