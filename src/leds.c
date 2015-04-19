
#include "os.h"
#include "ciaak.h"
#include "leds.h"




static int32_t fd_out;



/* open CIAA digital outputs */


extern void leds_init(void)
{

   fd_out = ciaaPOSIX_open("/dev/dio/out/0", O_RDWR);
}



extern void leds_toggle(uint8_t mask)
{
uint8 outputs;
ciaaPOSIX_read(fd_out,&outputs,1);
outputs^=mask;
ciaaPOSIX_write(fd_out,&outputs,1);
}



extern void leds_on(uint8_t mask)
{
   uint8 outputs;
   ciaaPOSIX_read(fd_out,&outputs,1);
   outputs|=mask;
   ciaaPOSIX_write(fd_out,&outputs,1);
}



extern void leds_off(uint8_t mask)
{
   uint8 outputs;
   ciaaPOSIX_read(fd_out,&outputs,1);
   outputs &=(~mask);
   ciaaPOSIX_write(fd_out,&outputs,1);
}



extern uint8_t leds_get(void)
{
   uint8 outputs;
   ciaaPOSIX_read(fd_out,&outputs,1);
   return outputs;
}



extern void leds_set(uint8_t value)
{
   ciaaPOSIX_write(fd_out,&value,1);
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
