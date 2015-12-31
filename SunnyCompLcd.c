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
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

//Wait for Press--------------------------------------------------
void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

task main()
{
	//Declare count variable to keep track of our choice
	int count = 0;

	//------------- Beginning of User Interface Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Loop while center button is not pressed
	while(nLCDButtons != centerButton)
	{
		//Switch case that allows the user to choose from 4 different options
		switch(count){
		case 0:
			//Display first choice
			displayLCDCenteredString(0, "Autonomous 1");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 3;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 1:
			//Display second choice
			displayLCDCenteredString(0, "Autonomous 2");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 2:
			//Display third choice
			displayLCDCenteredString(0, "Autonomous 3");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 3:
			//Display fourth choice
			displayLCDCenteredString(0, "Autonomous 4");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 0;
			}
			break;
		default:
			count = 0;
			break;
		}
	}
	//------------- End of User Interface Code ---------------------

	//------------- Beginning of Robot Movement Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Switch Case that actually runs the user choice
	switch(count){
	case 0:
		//If count = 0, run the code correspoinding with choice 1
		displayLCDCenteredString(0, "Autonomous 1");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		// Move forward at full power for 3 seconds
		motor[LeftDrive] = 127;			// Motor on port2 is run at full (127) power forward
		motor[RightDrive]	= 127;			// Motor on port3 is run at full (127) power forward
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	case 1:
		//If count = 1, run the code correspoinding with choice 2
		displayLCDCenteredString(0, "Autonomous 2");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		// Move reverse at full power for 3 seconds
		motor[RightDrive] = -127;			// Motor on port2 is run at full (-127) power reverse
		motor[LeftDrive]	= -127;			// Motor on port3 is run at full (-127) power reverse
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	case 2:
		//If count = 2, run the code correspoinding with choice 3
		displayLCDCenteredString(0, "Autonomous 3");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		//Turn right for 3 seconds
		motor[RightDrive] = -63;			// Motor on port2 is run at half power reverse
		motor[LeftDrive]	= 63;				// Motor on port3 is run at half power forward
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	case 3:
		//If count = 3, run the code correspoinding with choice 4
		displayLCDCenteredString(0, "Autonomous 4");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		//Turn left for 3 seconds
		motor[RightDrive] = 63;				// Motor on port2 is run at half power forward
		motor[LeftDrive]	= -63;			// Motor on port3 is run at half power reverse
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	default:
		displayLCDCenteredString(0, "No valid choice");
		displayLCDCenteredString(1, "was made!");
		break;
	}
	//------------- End of Robot Movement Code -----------------------
}
