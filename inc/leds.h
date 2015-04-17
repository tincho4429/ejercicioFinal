
/* IMPORTANTE: Este es un archivo para manejo de de los leds utilizado
 * para hacer pruebas rápidas.
 */


#ifndef LEDS_H
#define LEDS_H
/** \brief Short description of this file
 **
 ** Long description of this file
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Template Template to start a new module
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "ciaaPOSIX_stdint.h"

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
#define EDU_CIAA_NXP_LED3_VERDE     0x20
#define EDU_CIAA_NXP_LED2_ROJO      0x10
#define EDU_CIAA_NXP_LED1_AMARILLO  0x08

#define EDU_CIAA_NXP_RGB_VERDE      0x02
#define EDU_CIAA_NXP_RGB_AZUL       0x04
#define EDU_CIAA_NXP_RGB_ROJO       0x01

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

extern void leds_init(void);

extern void leds_toggle(uint8_t mask);

extern void leds_on(uint8_t mask);

extern void leds_off(uint8_t mask);

extern uint8_t leds_get(void);

extern void leds_set(uint8_t value);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef LEDS_H */

