#include "Gripper.h"

void setGripper(char action)
{
	switch (action)
	{
		
		//Get
	case 'L' :
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 1500);
		break;
		
		//Lose
	case 'G' :
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 600);
		break;
		
		//StopS
	default :
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 5000);
		break;
	}
}