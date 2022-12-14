/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPIO.h"
#include "sys_tick.h"




void led_blink(uint32 on , uint32 off){

	gpio_wr_bit (BASE_F , 1 , 1);              /* led on */
	_delay(on);
	gpio_wr_bit (BASE_F , 1 , 0);              /* led off */
	_delay(off);


}





int32_t main(void)
{
	/* enable clock for port F */
	volatile uint32 delay = 0;
	    SYSCTL_REGCGC2_REG |= 0x00000020;
	    delay = SYSCTL_REGCGC2_REG;

	    SysTick_Init();      /* init SysTick */

	    init_gpio_pin (BASE_F , 1 , 1) ;           /* config PF1 as digital output pin */
	while(1){
		
		led_blink(2,2);
		
	}
	return 0;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
