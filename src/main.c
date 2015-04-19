/* Copyright 2014, ACSE & CADIEEL
 *    ACSE   : http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *    CADIEEL: http://www.cadieel.org.ar
 * All rights reserved.
 *
 *    or
 *
 * Copyright 2014, Your Name <youremail@domain.com>
 * All rights reserved.
 *
 *    or
 *
 * Copyright 2014, ACSE & CADIEEL & Your Name <youremail@domain.com
 *    ACSE   : http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *    CADIEEL: http://www.cadieel.org.ar
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

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
#include "os.h"
#include "ciaak.h"
#include "leds.h"
#include "teclado.h"
#include "modbusSlave.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/
 uint8_t outputs;
 uint8_t veces;
uint8_t conta;
uint8_t registro;
uint8_t indice;

uint8_t  LEDS [6] = {0x01,0x02,0x04,0x08,0x10,0x20};

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/*
void ErrorHook(void)
{
 //  ciaaPOSIX_printf("ErrorHook was called\n");
   ciaaPOSIX_printf("Service: %d, P1: %d, P2: %d, P3: %d, RET: %d\n", OSErrorGetServiceId(), OSErrorGetParam1(), OSErrorGetParam2(), OSErrorGetParam3(), OSErrorGetRet());
   ShutdownOS(0);
}

*/



int main(void)
{

   registro = 0x01;
    veces =2;
    conta =0;
indice =2;

   /* Starts the operating system in the Application Mode 1 */
   /* This example has only one Application Mode */
   StartOS(AppMode1);

   /* StartOs shall never returns, but to avoid compiler warnings or errors
    *//* 0 is returned*/
   return 0;
}

TASK(InitTask)
{
   ciaak_start();
   teclado_init();
   leds_init();
  modbusSlave_init();

   TerminateTask();
}



TASK (flashLEDTask){

     conta++;

       if (conta >= veces) {  // Solo hace el toogle cuando pasa n ciclos

         leds_toggle (0x02);
          conta =0;

       }

       leds_on (registro);   //

   TerminateTask();

}



TASK(LecturaTecladoTask)
{
   uint8_t inputs;

   teclado_task ();
   inputs = teclado_getFlancos();


  if (TECLADO_TEC1_BIT & inputs){         /* si se oprime la tecla parpadea el led */

  /*   leds_off (registro);
     registro = registro>>1;
     leds_off (registro);
     leds_on (registro);
*/
     indice ++;

    registro =  LEDS [indice];
    leds_on (indice);
     }

     if (TECLADO_TEC2_BIT & inputs){          /* si se oprime la tecla parpadea el led */
     /*   registro = registro<<1;
        leds_off (registro);
        leds_on (registro);*/

        indice --;

            registro =  LEDS [indice];
            leds_on (indice);
     }

     // COntrol de COntador de Veces

     if (TECLADO_TEC3_BIT & inputs){         /* si se oprime la tecla parpadea el led */
        veces ++;   // leds_on (0x04);
     }

     if (TECLADO_TEC4_BIT & inputs){          /* si se oprime la tecla parpadea el led */
        veces --;  // leds_on (0x08);
     }


   TerminateTask();
}















/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
