/** 
 * @file dio_ext.h
 * @author Mohamed Hassanin
 * @brief An extension for the dio module for specific features in MCUs.
 * @version 0.1
 * @date 2021-03-07
*/

#ifndef DIO_EXT_H
#define DIO_EXT_H
//TODO: Add the required data members for the extended functions
//for DioConfig_t

#include "dio_ext_cfg.h" /**< For dio configuration */
#include "dio_cfg.h" /**< For dio configuration */

/**********************************************************************
* Function Prototypes
**********************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

#if DIO_TOGGLE == STD_ON
void Dio_ChannelToggle(DioChannel_t Channel);
#endif

#if DIO_PULLUP == STD_ON
void Dio_SetPullup(DioChannel_t Channel, DioResistor_t State);
#endif
#if DIO_PULLDOWN == STD_ON
void Dio_SetPulldown(DioChannel_t Channel, DioResistor_t State);
#endif

#if DIO_MODE_CHANGE == STD_ON
void Dio_SetMode(DioChannel_t Channel, DioMode_t Mode)
#endif

#if DIO_SPEED_CHANGE == STD_ON
void Dio_SetSpeed(DioChannel_t Channel, DioSpeed_t Speed)
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* DIO_H_*/
/*************** END OF FILE ********************************/