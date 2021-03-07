/** 
 * @file Dio_Cfg.c
 * @author Mohamed Hassanin
 * @brief This module contains the implementation for the digital
 * input/output peripheral configuration
 * @version 0.1
 * @date 2021-01-12
 */
/**********************************************************************
* Includes
**********************************************************************/
#include "dio_cfg.h" /**< For this modules definitions */
/*********************************************************************
* Module Variable Definitions
**********************************************************************/
/**
* The following array contains the configuration data for each
* digital input/output peripheral channel (pin). Each row represents a 
* single pin. Each column is representing a member of the DioConfig_t
* structure. This table is read in by Dio_Init, where each channel is then
* set up based on this table.
*/
static const DioConfig_t DioConfig[] =
{
  { PORTA_0, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTA_1, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTA_2, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTA_3, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTA_4, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTA_5, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTA_6, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTA_7, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTB_0, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTB_1, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTB_2, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTB_3, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTB_4, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTB_5, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTB_6, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTB_7, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTC_0, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTC_1, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTC_2, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTC_3, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTC_4, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTC_5, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTC_6, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTC_7, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTD_0, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTD_1, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTD_2, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTD_3, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTD_4, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTD_5, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTD_6, DIO_DIR_OUTPUT, DIO_STATE_LOW },
  { PORTD_7, DIO_DIR_OUTPUT, DIO_STATE_LOW }
};
/**********************************************************************
* Function Definitions
**********************************************************************/
/**********************************************************************
* Function : Dio_ConfigGet()
*//**
* \b Description:
* This function is used to get the cofiguration handle of the Dio <br>
* POST-CONDITION: A constant pointer to the first member of the
* configuration table will be returned. <br>
* \b Example Example:
* @code
* const Dio_ConfigType *DioConfig = Dio_GetConfig();
* Dio_Init(DioConfig);
* @endcode
* @see Dio_Init
* @return A pointer to the configuration table.
**********************************************************************/
const DioConfig_t * 
Dio_ConfigGet(void)
{
  /*
  * The cast is performed to ensure that the address of the first element
  * of configuration table is returned as a constant pointer and NOT a
  * pointer that can be modified.
  */
  return (const DioConfig_t *)DioConfig;
}
/************************ END OF FILE ********************************/
