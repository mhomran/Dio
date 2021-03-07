/**
 * @file dio_ext.c
 * @author Mohamed Hassanin
 * @brief An extension for the dio module for specific features in MCUs.
 * @version 0.1
 * @date 2021-03-07
 */

/**********************************************************************
* Includes
**********************************************************************/
#include <inttypes.h>
#include "dio_ext.h" /* For this modules definitions */
#include "xxx.h" /* For Hardware definitions */
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
#if DIO_TOGGLE == STD_ON
/**
* Defines a table of pointers to the Port Data Toggle Register
*/
static TYPE volatile * const Dio_PortsToggle[DIO_NUMBER_OF_PORTS] =
{
  (volatile TYPE*)&DDR_PTOR,
  (volatile TYPE*)&GPIOB_PTOR
};
#endif

#if DIO_MODE_CHANGE == STD_ON
/**
* Defines a table of pointers to the Port Data Toggle Register
*/
static TYPE volatile * const Dio_PortsMode[DIO_NUMBER_OF_PORTS] =
{
};
#endif
#if DIO_SPEED_CHANGE == STD_ON

/**
* Defines a table of pointers to the Port Data Toggle Register
*/
static TYPE volatile * const Dio_PortsSpeed[DIO_NUMBER_OF_PORTS] =
{
};
#endif

/**********************************************************************
* Functions Definitions
**********************************************************************/
#if DIO_TOGGLE == STD_ON
/**************************************************************************
* Function : Dio_ChannelToggle()
*//**
* \b Description:
* This function is used to toggle the current state of a channel (pin). <br>
* PRE-CONDITION: The channel is configured as OUTPUT <br>
* PRE-CONDITION: The channel is configured as GPIO <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition<br>
* @param Channel is the pin from the DioChannel_t that is
* to be modified.
* \b Example:
* @code
* Dio_ChannelToggle(PORTA_1);
* @endcode
* @see Dio_Init
* @return void
**********************************************************************/
void 
Dio_ChannelToggle(DioChannel_t Channel)
{
  *Dio_PortsToggle[Channel / NUMBER_OF_CHANNELS_PER_PORT] |= 
  (1UL <<(Channel % NUMBER_OF_CHANNELS_PER_PORT));
}
#endif

#if DIO_SET_PULLUP == STD_ON
/**********************************************************************
* Function : Dio_Pullup()
*//**
* \b Description:
* This function is used to enable/disable pull up resistor for a specific channel. <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition <br>
* POST-CONDITION: The pullup resistor is dattached/deattached to/from the channel <br>
* @param Channel is the channel to attach/deattach the resistor to/from.
* \b Example:
* @code
* Dio_Pullup(PORTA_0, ENABLED);
* @endcode
* @return void
**********************************************************************/
void 
Dio_SetPullup(DioChannel_t Channel, DioResistor_t State)
{
  //TODO
}

#endif
#if DIO_SET_PULLDOWN == STD_ON
/**********************************************************************
* Function : Dio_SetPulldown()
*//**
* \b Description:
* This function is used to enable/disable pull down resistor for a specific channel. <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition<br>
* POST-CONDITION: The pulldown resistor is dattached/deattached to/from the channel <br>
* @param Channel is the channel to attach/deattach the resistor to/from.
* \b Example:
* @code
* Dio_Pulldown(PORTA_0, ENABLED);
* @endcode
* @return void
**********************************************************************/
void 
Dio_SetPulldown(DioChannel_t Channel, DioResistor_t State)
{
  //TODO
}
#endif

#if DIO_SET_MODE == STD_ON
/**********************************************************************
* Function : Dio_SetMode()
*//**
* \b Description:
* This function is used to choose the mode of the channel (ADC, DIO, SPI, etc.) <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition. <br>
* POST-CONDITION: The mode of the channel changes to the desired mode. <br>
* @param Channel is the channel to attach/deattach the resistor to/from.
* @param Mode the mode of the channel (ADC, SPI, Dio, etc.)
* \b Example:
* @code
* //TODO
* @endcode
* @return void
**********************************************************************/
void 
Dio_SetMode(DioChannel_t Channel, DioMode_t Mode)
{
  //TODO
}
#endif
#if DIO_SET_SPEED == STD_ON
/**********************************************************************
* Function : Dio_SetSpeed()
*//**
* \b Description:
* This function is used to choose the Speed of the output channel <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition<br>
* POST-CONDITION: The channel output speed changes to the desired speed.<br>
* @param Channel is the channel to attach/deattach the resistor to/from.
* @param Speed the speed of the channel output.
* \b Example:
* @code
* //TODO
* @endcode
* @return void
**********************************************************************/
void 
Dio_SetSpeed(DioChannel_t Channel, DioSpeed_t Speed)
{
  //TODO
}
#endif
/*************** END OF FUNCTIONS ********************************/

