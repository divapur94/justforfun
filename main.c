//STM32 F746
//LD1: PB0 PA5
//LD2: PB7
//LD3: PB14

#include <stdint.h>

#define PERIPH_BASE 			(0x40000000UL)

#define AHB1PERIPH_OFFSET 		(0x00020000UL)
#define AHB1PERIPH_BASE 		(PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOB_OFFSET 			(0x400UL)
#define GPIOB_BASE				(AHB1PERIPH_BASE + GPIOB_OFFSET)

#define	RCC_OFFSET				(0x3800UL)
#define	RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)

#define RCC_AHBENR_OFFSET		(0x30UL)
#define RCC_AHBENR_R			(*(volatile unsigned int *)(RCC_BASE + RCC_AHBENR_OFFSET))

#define GPIOBEN					(1U<<1)

#define MODER_R_OFFSET			(0x0000UL)
#define GPIOB_MODER_R			(*(volatile unsigned int *)(GPIOB_BASE + MODER_R_OFFSET))


#define ODR_OFFSET	    		(0x14UL)
#define GPIOB_ODR_R				(*(volatile unsigned int *)(GPIOB_BASE + ODR_OFFSET))

#define PIN7					(1U<<7)
#define LD2						PIN7

/*
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
*/

int main(void)
{

	RCC_AHBENR_R |= GPIOBEN;

	GPIOB_MODER_R |= (1U<<14);
	GPIOB_MODER_R &=~ (1U<<15); //~ for binary 1s complement & for binary and

	while(1){
	GPIOB_ODR_R ^= LD2; //^ for bionary XOR
	for (int i= 0 ; i<160000; i++);
	}
}
