#ifndef __L298N_H__
#define __L298N_H__


#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "stm32f1xx_hal_gpio.h"

#define L298N_EN_PORT GPIOA
#define L298N_EN1_PIN GPIO_PIN_0
#define L298N_EN2_PIN GPIO_PIN_1
#define L298N_EN3_PIN GPIO_PIN_2
#define L298N_EN4_PIN GPIO_PIN_3

#define L298N_IN_PORT GPIOB
#define L298N_IN1_PIN GPIO_PIN_0
#define L298N_IN2_PIN GPIO_PIN_1
#define L298N_IN3_PIN GPIO_PIN_10
#define L298N_IN4_PIN GPIO_PIN_11
#define L298N_IN5_PIN GPIO_PIN_12
#define L298N_IN6_PIN GPIO_PIN_13
#define L298N_IN7_PIN GPIO_PIN_14
#define L298N_IN8_PIN GPIO_PIN_15

void setspeed(int speed, char dict);
void setdict(char dict);

#endif