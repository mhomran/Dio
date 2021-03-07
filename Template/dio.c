/** 
 * @file dio.c
 * @author Mohamed Hassanin
 * @brief The implementation for the dio.
 * @version 0.1
 * @date 2021-01-12
 */
/**********************************************************************
* Includes
**********************************************************************/
#include <inttypes.h>
#include "dio.h" /* For this modules definitions */
#include "dio_memmap.h" /* For Hardware definitions */
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
/**
* Defines a table of pointers to the peripheral input register on the
* microcontroller.
*/
static const volatile TYPE* const Dio_PortsIn[DIO_NUMBER_OF_PORTS] =
{ 
  (const volatile TYPE*)PINB,
};
/**
* Defines a table of pointers to the peripheral data direction register
on
* the microcontroller.
*/
static volatile TYPE* const Dio_PortsDir[DIO_NUMBER_OF_PORTS] =
{
  (volatile TYPE*)DDRB,
};

/**
* Defines a table of pointers to the Port Data Output Register
*/
static volatile TYPE* const Dio_PortsOut[DIO_NUMBER_OF_PORTS] =
{
  (volatile TYPE*)PORTB,
};
/**********************************************************************
* Function Definitions
**********************************************************************/
/*********************************************************************
* Function : Dio_Init()
*//**
* \b Description:
* This function is used to initialize the Dio based on the configuration
* table defined in dio_cfg module. <br>
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: NUMBER_OF_CHANNELS_PER_PORT > 0 <br>
* PRE-CONDITION: NUMBER_OF_PORTS > 0 <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled. <br>
* POST-CONDITION: The DIO peripheral is set up with the configuration settings.<br>
* @param Config is a pointer to the configuration table that
* contains the initialization for the peripheral.
* @return void
*
* \b Example:
* @code
* const DioConfig_t *DioConfig = Dio_ConfigGet();
* Dio_Init(DioConfig);
* @endcode
* @see Dio_ConfigGet
**********************************************************************/
void 
Dio_Init(const DioConfig_t * Config)
{
/* TODO: Define implementation */
  uint16_t PortNumber = 0; // Port Number
  uint16_t Position = 0; // Pin Number

  // Loop through all pins, set the data register bit and the data-direction
  // register bit according to the dio configuration table values
  for (uint16_t Channel = 0; Channel < DIO_CHANNEL_MAX; Channel++)
    {
      PortNumber = Config[Channel].Channel / DIO_CHANNELS_PER_PORT;
      Position = Config[Channel].Channel % DIO_CHANNELS_PER_PORT;

      if(Config[Channel].Direction == DIO_DIR_OUTPUT)
        {
          *Dio_PortsDir[PortNumber] |= 1UL << Position;

          if(Config[Channel].Data == DIO_STATE_HIGH)
            {
              *Dio_PortsOut[PortNumber] |= (1UL << Position);
            }
          else
            {
              *Dio_PortsOut[PortNumber] &= ~(1UL << Position);
            }
        }
      else
        {
          *Dio_PortsDir[PortNumber] &= ~(1UL << Position);
        }
    }
}

/**********************************************************************
* Function : Dio_ChannelRead()
*//**
* \b Description:
* This function is used to read the state of a dio channel (pin) <br>
* PRE-CONDITION: The channel is configured as INPUT <br>
* PRE-CONDITION: The channel is configured as GPIO <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition <br>
* POST-CONDITION: The channel state is returned.<br>
* @param Channel is the DioChannel_t that represents a pin
* @return The state of the channel as HIGH or LOW
*
* \b Example:
* @code
* uint8_t_t pin = Dio_ReadChannel(PORT1_0);
* @endcode
* @see Dio_Init
**********************************************************************/
DioState_t
Dio_ChannelRead(DioChannel_t Channel)
{
  /* Read the port associated with the desired pin */
  DioState_t PortState = (DioState_t)*Dio_PortsIn[Channel / DIO_CHANNELS_PER_PORT];
  /* Determine the port bit associated with this channel */
  DioState_t PinMask = (DioState_t)(1UL << (Channel % DIO_CHANNELS_PER_PORT));
  /* Mask the port state with the pin and return the DioPinState */
  return ((PortState & PinMask) ? DIO_STATE_HIGH : DIO_STATE_LOW);
}

/**********************************************************************
* Function : Dio_ChannelWrite()
*//**
* \b Description:
* This function is used to write the state of a channel (pin) as either<br>
* logic high or low through the use of the DioChannel_t enum to select<br>
* the channel and the DioState_t define the desired state.<br>
* PRE-CONDITION: The channel is configured as OUTPUT <br>
* PRE-CONDITION: The channel is configured as GPIO <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition <br>
* POST-CONDITION: The channel state will be State <br>
* @param Channel is the pin to write using the DioChannel_t enum definition <br>
* @param State is HIGH or LOW as defined in the DioState_tum <br>
* @return void
*
* \b Example:
* @code
* Dio_WriteChannel(PORT1_0, LOW); // Set the PORT1_0 pin low
* Dio_WriteChannel(PORT1_0, HIGH); // Set the PORT1_0 pin high
* @endcode
* @see Dio_Init
**********************************************************************/
void 
Dio_ChannelWrite(DioChannel_t Channel, DioState_t State)
{
  if (State == DIO_STATE_HIGH)
    {
      *Dio_PortsOut[Channel/DIO_CHANNELS_PER_PORT] |= (1UL<<(Channel % DIO_CHANNELS_PER_PORT));
    }
  else
    {
      *Dio_PortsOut[Channel/DIO_CHANNELS_PER_PORT] &= ~(1UL<<(Channel % DIO_CHANNELS_PER_PORT));
    }
}

/**************************************************************************
* Function : Dio_SetChannelDirection()
*//**
* \b Description:
* This function is used to set the direction of a channel.<br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition <br>
* POST-CONDITION: The direction of the channel is changed.<br>
* @param Channel is the pin from the DioChannel_t that is to be modified. <br>
* @return void
*
* \b Example:
* @code
* Dio_SetChannelDirection(PORTA_1, INPUT);
* @endcode
* @see Dio_Init
**********************************************************************/
void 
Dio_SetChannelDirection(DioChannel_t Channel, DioDirection_t Direction)
{
  uint16_t PortNumber = Channel / DIO_CHANNELS_PER_PORT;
  uint16_t Position = Channel % DIO_CHANNELS_PER_PORT;
  if(Direction == DIO_DIR_OUTPUT)
    {
      *Dio_PortsDir[PortNumber] |= (1UL << Position);
    }
  else
    {
      *Dio_PortsDir[PortNumber] &= ~(1UL << Position);
    }
}

/**************************************************************************
* Function : Dio_RegisterWrite()
*//**
* \b Description:
* This function is used to directly address and modify a Dio register. <br>
* The function should be used to access specialied functionality in the <br>
* Dio peripheral that is not exposed by any other function of the interface. <br>
* PRE-CONDITION: Address is within the boundaries of the Dio register 
* addresss space <br>
* POST-CONDITION: The register located at Address with be updated
* with Value <br>
* @param Address is a register address within the Dio
* peripheral map
* @param Value is the value to set the Dio register to
* @return void
*
* \b Example:
* @code
* Dio_RegisterWrite(VALID_DIO_ADDRESS, 0x15);
* @endcode
**********************************************************************/
void 
Dio_RegisterWrite(TYPE volatile * const Address, TYPE Value)
{
  //TODO: Assert that this address is in range of Dio addresses
  *Address = Value;
}
/**********************************************************************
* Function : Dio_RegisterRead()
*//**
* \b Description:
*
* This function is used to directly address a Dio register. The function <br>
* should be used to access specialied functionality in the Dio peripheral<br>
* that is not exposed by any other function of the interface.<br>
* PRE-CONDITION: Address is within the boundaries of the Dio register
* addresss space<br>
* POST-CONDITION: The value stored in the register is returned to the
* caller<br>
* @param Address is the address of the Dio register to read
* @return The current value of the Dio register.
*
* \b Example:
* @code
* DioValue = Dio_RegisterRead(VALID_DIO_ADDRESS);
* @endcode
**********************************************************************/
const volatile TYPE 
Dio_RegisterRead(const volatile TYPE * const Address)
{
  //TODO: Assert that this address is in range of Dio addresses
  return *Address;
}

/*************** END OF FUNCTIONS ********************************/
