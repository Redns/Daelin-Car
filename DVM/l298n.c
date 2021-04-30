#include "l298n.h"

/*
 * speed: 10 ~ 100
 * Left and Right: 10% (10) ~ 60% (100)		per = speed * 0.56 + 4
 *                 50% (10) ~ 100%(100)     per = speed * 0.56 + 44
 *                 
 * Forward and Backward:
 *				   10% (10) ~ 100% (100)    per = speed
 */
void setspeed(int speed, char dict)
{
	switch (dict)
	{
		//Left
	case 'L' :
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0.56 * speed + 4);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0.56 * speed + 44);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0.56 * speed + 4);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0.56 * speed + 44);
		break;
		
		//Right
	case 'R' :
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0.56 * speed + 44);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0.56 * speed + 4);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0.56 * speed + 44);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0.56 * speed + 4);
		break;
		
		//Backward and Forward and Cw and Aw
	default :
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, speed);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, speed);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, speed);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, speed);
		break;
	}
}

void setdict(char dict)
{
	switch (dict)
	{
		//Backward
	case 'B' :
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN4_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN5_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN6_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN7_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN8_PIN, GPIO_PIN_SET);
		break;
	
		//Stop
	case 'S' :
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN4_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN5_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN6_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN7_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN8_PIN, GPIO_PIN_RESET);
		break;
		
		//CW
	case 'C' :
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN4_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN5_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN6_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN7_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN8_PIN, GPIO_PIN_SET);
		break;
		
		//AW
	case 'A' :
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN2_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN4_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN5_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN6_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN7_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN8_PIN, GPIO_PIN_RESET);
		break;
		
		//Forward and Left and Right
	default :
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN4_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN5_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN6_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN7_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L298N_IN_PORT, L298N_IN8_PIN, GPIO_PIN_RESET);
		break;
	}
}