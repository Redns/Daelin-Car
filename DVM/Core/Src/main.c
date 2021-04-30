/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "l298n.h"
#include "Gripper.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define R HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)
#define L HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

	//state variable
	uint8_t message[6] = "GG00GG";
	char Dstate = 'S';					
	char Gstate = 'L';
	char Mode = 'M';		//Manual driving
	int  speed = 0;



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART3)
	{
		//make sure the mode
		if(message[0] == 'M')
		{
			Mode = 'M';
		}
		
		if (message[0] == 'A')
		{
			Mode = 'A';
		}
		
		//set direction
		if(message[0] == 'D')
		{
			//Left
			if(message[2] == '0' && message[4] == '1')
			{
				Dstate = 'L';
			}
			
			//Right
			else if(message[2] == '2' && message[4] == '1')
			{
				Dstate = 'R';
			}
			
			//Forward
			else if(message[4] == '0')
			{
				Dstate = 'F';
			}
			
			//Backward
			else if(message[4] == '2')
			{
				Dstate = 'B';
			}
			
			//Stop
			else
			{
				Dstate = 'S';
			}
			
			setdict(Dstate);
			
		}
		
		
		//set speed 
		if(message[0] == '#')
		{
			speed = (message[2] - '0') * 100 + (message[3] - '0') * 10 + (message[4] - '0') * 1;
			speed = speed - 100;
			
			setspeed(speed, Dstate);
		}
		
		
		//set Gripper or direction
		if(message[0] == 'G')
		{
			//CW
			if(message[2] == '2')
			{
				Dstate = 'C';
			}
			
			//AW
			else if(message[2] == '0')
			{
				Dstate = 'A';
			}
			
			//Get
			else if(message[2] == '1' && message[4] == '0')
			{
				Gstate = 'G';
			}
			
			//Lose
			else if(message[2] == '1' && message[4] == '2')
			{
				Gstate = 'L';
			}
			
			//Stop
			else
			{
				Dstate = 'S';
				Gstate = 'S';
			}
			
			setdict(Dstate);
            setGripper(Gstate);
		}
	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */

	
	//open L298N Enable Port
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
	
	
	//open gripper
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  HAL_UART_Receive_IT(&huart3, message, 6);
	  //Auto driving
	  if (Mode == 'A')
	  {
		  //forward
		  if (R == GPIO_PIN_SET && L == GPIO_PIN_SET)
		  {
			  Dstate = 'F';
			  speed = 20;
			  
			  setdict(Dstate);
			  setspeed(speed, Dstate);
		  }
		  
		  else if(L == GPIO_PIN_SET && R == GPIO_PIN_RESET)
		  {
			  Dstate = 'L';
			  speed = 20;
			  
			  setdict(Dstate);
			  setspeed(speed, Dstate);
		  }
		  
		  else if(L == GPIO_PIN_RESET && R == GPIO_PIN_SET)
		  {
			  Dstate = 'R';
			  speed = 20;
			  
			  setdict(Dstate);
			  setspeed(speed, Dstate);
		  }
		  
		  else
		  {
			  Dstate = 'B';
			  speed = 20;
			  
			  setdict(Dstate);
			  setspeed(speed, Dstate);
		  }
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
