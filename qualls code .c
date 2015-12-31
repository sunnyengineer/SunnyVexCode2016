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

void flywheel (int speed)
{
	speed=0;
	motor[LBtmL]= speed;
	motor[LMidL]= speed;
	motor[LUpL] = speed;
	motor[RBtmL]= speed;
	motor[RUpL] = speed;
	motor[RUpL] = speed;
}



task main ()
{
	flywheel (60);
if(vexRT[Btn7U] == 1)
{
	{
		flywheel (+5);
	}
}


if(vexRT[Btn7R] == 1)
{
	{
		flywheel (-5);
	}
}

}
