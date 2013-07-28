#include <stdint.h>
#include "dfilt_fxp.h"

#define ALPHA       0.23906 /*0.75855 /*0.38587*/
#define FXP_ALPHA   (ALPHA*(uint16_t)(1<<15))

uint16_t
dfilt_single_pole(uint16_t input, uint16_t prev_output, uint16_t alpha)
{
  uint16_t output;
  uint32_t a1 = ((1<<15)-alpha);
  uint32_t b0 = alpha;
  uint32_t y1 = (a1*prev_output) >> 15;
  uint32_t u1 = (b0*input) >> 15;
  output = y1 + u1;
	return output;
}

