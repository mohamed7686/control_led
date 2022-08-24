



#include "sys_tick.h"

uint32 sysTick_counter =0;


void SysTick_Handler (){

	sysTick_counter ++ ;

}



void SysTick_Init(void)
{
    SYSTICK_CTRL_REG    = 0;                   /* Disable the SysTick Timer by Clear the ENABLE Bit */
    SYSTICK_RELOAD_REG  =0x00FFFFFF ;         /* Set the Reload value with 0x00FFFFFF to count One second */
    SYSTICK_CURRENT_REG = 0;                   /* Clear the Current Register value */
    /* Configure the SysTick Control Register
     * Enable the SysTick Timer (ENABLE = 1)
     * Enable SysTick Interrupt (INTEN = 1)
     * Choose the clock source to be System Clock (CLK_SRC = 1) */
    SYSTICK_CTRL_REG   |= 0x07;
    NVIC_SYSTEM_PRI3_REG =  (NVIC_SYSTEM_PRI3_REG & SYSTICK_PRIORITY_MASK) | (SYSTICK_INTERRUPT_PRIORITY << SYSTICK_PRIORITY_BITS_POS);
}



/* delay function to polling the system x miliseconds */
void _delay(int seconds){

	sysTick_counter =0 ;                    /* clear the counter */
	Enable_Interrupts();
	Enable_Exceptions();
    while( sysTick_counter<seconds );
    Disable_Interrupts();
    Disable_Exceptions();

}
