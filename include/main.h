#ifndef __MAIN_H
#define __MAIN_H

// "Cable select" pin for SPI
#define CS_Pin GPIO_PIN_4
#define CS_GPIO_Port GPIOA

// "Clock" pin for SPI
#define CLK_Pin GPIO_PIN_5
#define CLK_GPIO_Port GPIOA

// "Master Out Slave In" pin for SPI
#define MOSI_Pin GPIO_PIN_7
#define MOSI_GPIO_Port GPIOA

// "Data Command" pin for SSD1306
#define DC_Pin GPIO_PIN_13
#define DC_GPIO_Port GPIOB

// "Reset" pin for SSD1306
#define RST_Pin GPIO_PIN_14
#define RST_GPIO_Port GPIOB

// "Encode Left" pin for encoding wheel
#define ENCOD_LEFT_Pin GPIO_PIN_10
#define ENCOD_LEFT_GPIO_Port GPIOB

// "Encode Right" pin for encoding wheel
#define ENCOD_RIGHT_Pin GPIO_PIN_1
#define ENCOD_RIGHT_GPIO_Port GPIOA

// Cbk for wheel interruptions
void onEncodeLeft(void);
void onEncodeRight(void);

extern int wheelCpt;

#endif
