/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  common_macros.h
 *       Module:  -
 *
 *  Description:  <common used macros to set,clear , Toggle and rotate bit>     
 *  
 *********************************************************************************************************************/
#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 #include <stdint.h>

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 /* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/* access a specific address */
#define ACCESS_ADDRESS(address)  (*(volatile uint32 *)(address))

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
