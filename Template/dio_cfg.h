/** 
 * @file dio_cfg.h
 * @author Mohamed Hassanin
 * @brief This module contains interface definitions for the
 * Dio configuration. This is the header file for the definition of the
 * interface for retrieving the digital input/output configuration table.
 * @version 0.1
 * @date 2021-01-12
*/
#ifndef DIO_CFG_H_
#define DIO_CFG_H_
/**********************************************************************
* Preprocessor Constants
**********************************************************************/
/**
* Defines the number of pins on each processor port.
*/
#define DIO_CHANNELS_PER_PORT 8U
/**
* Defines the number of ports on the processor.
*/
#define DIO_NUMBER_OF_PORTS 3U
/**********************************************************************
* Typedefs
**********************************************************************/
/**
* Defines the possible states for a digital output pin.
*/
typedef enum
{
	LOW, /**< Defines digital state ground */
	HIGH /**< Defines digital state power */
}DioPinState_t;

/**
 * Defines the possible directions of the pin
 */
typedef enum 
{
	INPUT, 
	OUTPUT
}DioDirection_t;

/**
* Defines an enumerated list of all the channels (pins) on the MCU
* device. The last element is used to specify the maximum number of
* enumerated labels.
*/
typedef enum
{
	/* TODO: Populate this list based on available MCU pins */
	PORTB_0,
	PORTB_1,
	DIO_MAX_PIN_NUMBER 
}DioChannel_t;

/**
* Defines the digital input/output configuration table’s elements that are used
* by Dio_Init to configure the Dio peripheral.
*/
typedef struct
{
	DioChannel_t Channel; /**< The I/O pin */
	DioDirection_t Direction; /**< OUTPUT or INPUT */
	DioPinState_t Data; /**< HIGH or LOW */
}DioConfig_t;

/**********************************************************************
* Function Prototypes
**********************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

const DioConfig_t* Dio_ConfigGet(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* DIO_CFG_H_*/
/************************* END OF FILE ********************************/
