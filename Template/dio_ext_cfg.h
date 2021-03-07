/**
 * @file dio_ext_cfg.h
 * @author Mohamed Hassanin
 * @brief An extension for the dio module for specific features in MCUs.
 * @version 0.1
 * @date 2021-03-07
 */

#ifndef DIO_EXT_CFG_H_
#define DIO_EXT_CFG_H_
/**********************************************************************
* Preprocessor Constants
**********************************************************************/
/**
 * The feature is supported
 */
#define STD_ON 1
/**
 * The feature is not supported
 */
#define STD_OFF 0

/**
 * Does this target support toggling.
 */
#define DIO_TOGGLE STD_OFF
/**
 * Does this target support pullup resistors.
 */
#define DIO_SET_PULLUP STD_OFF
/**
 * Does this target support pulldown resistors.
 */
#define DIO_SET_PULLDOWN STD_OFF
/**
 * Does this target support output speed change
 */
#define DIO_SET_SPEED STD_OFF
/**
 * Does this target support mode change
 */
#define DIO_SET_MODE STD_OFF 

#if DIO_MODE_CHANGE == STD_ON
/**
* Defines the possible DIO pin multiplexing values. The datasheet
* should be reviewed for proper muxing options.
*/
typedef enum
{
	/* TODO: Populate with possible mode options */
	DIO_MAX_MODE
}DioMode_t;
#endif

#if DIO_SET_PULLUP == STD_ON || DIO_SET_PULLDOWN == STD_ON
/**
* Defines the possible states of the channel pull-up/down resistors
*/
typedef enum
{
	DISABLED, /**< Used to disable the internal pull-up/down resistors */
	ENABLED, /**< Used to enable the internal pull-up/down resistors */
	MAX_RESISTOR /**< Resistor states should be below this value */
}DioResistor_t;
#endif

#if DIO_SET_SPEED == STD_ON
/**
* The speed of the output changing state.
*/
typedef enum
{
  /* TODO: populate */
}DioSpeed_t;
#endif

#if DIO_SET_MODE == STD_ON
/**
* The mode of the channel.
*/
typedef enum
{
  /* TODO: populate */
}DioMode_t;
#endif

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
