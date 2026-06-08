// Where is the led connected?
//Port: A
//Pin:	5
#include <stdint.h>
#define PERIPH_BASE				(0x40000000UL)
#define AHB1PERIPH_OFFSET		(0x20000000UL)
#define AHB1PERIPH_BASE			(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET			(0x0000U)

#define GPIOA_BASE				(AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET				(0x3800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET			(0x30UL)
#define RCC_AHB1EN_R			(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET			(0x00UL)
#define GPIOA_MODE_R			(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET				(0x14UL)
#define GPIOA_OD_R				(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

#define GPIOAEN					(1U<<0) // 0b 0000 0000 0000 0000 0000 0000 0000 0001

#define PIN5					(1U<<5)
#define LED_PIN					 PIN5

#define __IO	volatile

typedef struct
{
	volatile uint32_t MODER;	/*!< GPIO port mode register,				Address offset: 0x00		*/
//	__IO uint32_t OTYDER;	/*!< GPIO port output type register,		Address offset: 0x04		*/
//	__IO uint32_t OSPEEDR;	/*!< GPIO port output speed register,		Address offset: 0x08		*/
//	__IO uint32_t PUPDR;	/*!< GPIO port pull-up/pull-down register,	Address offset: 0x0C		*/
//	__IO uint32_t IDR;		/*!< GPIO port input data register,			Address offset: 0x10		*/
	volatile uint32_t DUMMY[4];
	__IO uint32_t ODR;		/*!< GPIO port output data register,		Address offset: 0x14		*/
//	__IO uint32_t BSRR;		/*!< GPIO port bit set/reset register,		Address offset: 0x18		*/
//	__IO uint32_t LCKR;		/*!< GPIO port configuration lock register,	Address offset: 0x1C		*/
//	__IO uint32_t AFR[2];	/*!< GPIO alternate function registers,		Address offset: 0x20-0x24	*/
} GPIO_TypeDef;


typedef struct
{
	volatile uint32_t	DUMMY[12];
	volatile uint32_t	AHB1ENR; /*!<RCC AHB1 peripheral clock register,	Address offset:0x30 */
} RCC_TypeDef;

#define RCC		((RCC_TypeDef*)RCC_BASE)
#define GPIOA	((GPIO_TypeDef*)GPIOA_BASE)
/*
 * (1U<<10) // Set bit 10 to  1
 * &=~(1U<<11) // Set bit 11 to 0*/


int main(void)
{
	/*1. Enable clock access to GPIOA*/
	//	RCC_AHB1EN_R |= GPIOAEN;
	RCC->AHB1ENR |= GPIOAEN;

	/*2. Set PA5 as output pin*/
	//	GPIOA_MODE_R |= (1U<<10);
	//	GPIOA_MODE_R &=~(1U<<11);
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);

	while(1)
	{
		/*3. Set PA5 high*/
		//GPIOA_OD_R |= LED_PIN;
		/*4: Experiment 2: toggle PA5*/
		//		GPIOA_OD_R ^= LED_PIN;
		GPIOA->ODR ^= LED_PIN;
		for(int i = 0; i < 100000; i++) {}
	}
}
