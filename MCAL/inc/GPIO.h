/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Configuration File To ENABLE/DISABLE Interrupts And Configure Priorities >     
 *  
 *********************************************************************************************************************/
#ifndef GPIO_H_
#define GPIO_H_


#include "common_types.h"




void init_gpio_port(uint32 port_base , uint32 val);
void init_gpio_pin (uint32 port_base , uint32 bit , uint32 val);
void gpio_wr_port (uint32 port_base , uint32 val);
void gpio_wr_bit (uint32 port_base , uint32 bit , uint32 val);
uint32 gpio_r_port (uint32 port_base);
uint32 gpio_r_bit (uint32 port_base , uint32 bit);


#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
