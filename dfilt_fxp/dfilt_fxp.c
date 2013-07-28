#include <stdint.h>
#include "dfilt_fxp.h"

/* dfilt_single_pole
 *  Parameters:
 *    input - current input to the filter
 *    output - previous time step output of the filter
 *    alpha - cutoff frequency parameter, scaled by left shifted 15
 *  returns:
 *    current time step output of the filter
 *  Calculates the current output of the digital filter for a two byte
 *  unsigned signal.
 */
uint16_t
dfilt_single_pole_u16(uint16_t input, uint16_t prev_output, uint16_t alpha)
{
  uint16_t output;                  /* current time step output */
  uint32_t beta = ((1<<15)-alpha);  /* coefficient of previous output */
  /* calculate the previous output term and scale to output scaling */
  uint32_t y1 = (beta*prev_output) >> 15;
  /* calculate the input term and scale to output scaling */
  uint32_t u1 = (alpha*input) >> 15;
	/* calculate current filter output */
  output = y1 + u1;
	return output;
}

