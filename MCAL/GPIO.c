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
#include"GPIO.h"




void init_gpio_port(uint32 port_base , uint32 val){

	    ACCESS_ADDRESS(port_base + GPIO_LOCK_OFFSET)   = 0x4C4F434B;         /* Unlock the GPIO_PORTF_CR_REG */
	    ACCESS_ADDRESS(port_base + GPIO_COMMIT_OFFSET)&=0xFFFFFF00 | (val);
	    ACCESS_ADDRESS(port_base + GPIO_AM_OFFSET) &= ~(val);                /* Disable Analog on port pins */
	    ACCESS_ADDRESS(port_base + GPIO_PORT_CTR_OFFSET) = 0x00000000;       /* Clear PMCx bits for the selected port to use it as GPIO pin */
	    ACCESS_ADDRESS(port_base + GPIO_DIR_OFFSET)   &=0xFFFFFF00 | (val);  /* Configure selected port pins as output pin */
	    ACCESS_ADDRESS(port_base + GPIO_AF_SEL_OFFSET) &= ~(val);            /* Disable alternative function on selected port pins */
	    ACCESS_ADDRESS(port_base + GPIO_DIGITAL_EN_OFFSET) &=0xFFFFFF00 | (val); /* Enable Digital I/O on selected port pins */
	    ACCESS_ADDRESS(port_base + GPIO_DATA_OFFSET) &= ~(val);              /* Clear selected bits in Data regsiter to be low as default */


}


void init_gpio_pin (uint32 port_base , uint32 bit , uint32 val){

	        ACCESS_ADDRESS(port_base + GPIO_LOCK_OFFSET)   = 0x4C4F434B;            /* Unlock the GPIO_PORTF_CR_REG */
		    ACCESS_ADDRESS(port_base + GPIO_COMMIT_OFFSET)    |= (1<<bit);
		    ACCESS_ADDRESS(port_base + GPIO_AM_OFFSET) &= ~(1<<bit);                /* Disable Analog on port pins */
		    ACCESS_ADDRESS(port_base + GPIO_PORT_CTR_OFFSET)  &=~( 0x0000000F<<(4*bit));     /* Clear PMCx bits for the selected port to use it as GPIO pin */
		    switch(val){
		    case 0 :
		    ACCESS_ADDRESS(port_base + GPIO_DIR_OFFSET)   &= ~(1<<bit);              /* Configure selected port pins as input pin */
		    break;
		    case 1 :
		    	 ACCESS_ADDRESS(port_base + GPIO_DIR_OFFSET)   |= (1<<bit);         /* Configure selected port pins as output pin */
		    }
		    ACCESS_ADDRESS(port_base + GPIO_AF_SEL_OFFSET) &= ~(1<<bit);            /* Disable alternative function on selected port pins */
		    ACCESS_ADDRESS(port_base + GPIO_DIGITAL_EN_OFFSET)   |= (1<<bit);       /* Enable Digital I/O on selected port pins */
		    ACCESS_ADDRESS(port_base + GPIO_DATA_OFFSET) &= ~(1<<bit);              /* Clear selected bits in Data register to be low as default */

}




void gpio_wr_port (uint32 port_base , uint32 val){

	ACCESS_ADDRESS(port_base + GPIO_DATA_OFFSET) = val ;

}




void gpio_wr_bit (uint32 port_base , uint32 bit , uint32 val){

if(val==0){
	 ACCESS_ADDRESS(port_base + GPIO_DATA_OFFSET) &= ~(1<<bit);
}
else if(val==1){
	 ACCESS_ADDRESS(port_base + GPIO_DATA_OFFSET) |= (1<<bit);
}
}



uint32 gpio_r_port (uint32 port_base){

 return ACCESS_ADDRESS(port_base + GPIO_DATA_OFFSET);

}


uint32 gpio_r_bit (uint32 port_base , uint32 bit){

return (ACCESS_ADDRESS(port_base + GPIO_DATA_OFFSET)& (1<<bit));
}














/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
