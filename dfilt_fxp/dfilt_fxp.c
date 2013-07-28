#include "dfilt_fxp.h"

typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#define ALPHA       0.23906 /*0.75855 /*0.38587*/
#define FXP_ALPHA   (ALPHA*(uint16_t)(1<<15))
int dfilt_single_pole(int argc, char * argv[])
{
  const uint16_t alpha = FXP_ALPHA;
  
  int ii;
  uint32_t a1 = ((1<<15)-alpha);
  uint32_t b0 = alpha;
}

