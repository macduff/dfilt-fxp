#ifndef DFILT_FXP_H_
#define DFILT_FXP_H_

#include <stdint.h>
/* dfilt_single_pole
 *  Parameters:
 *    input - current input to the filter
 *    output - previous time step output of the filter
 *    alpha - cutoff frequency parameter, scaled by left shifted 15
 *  returns:
 *    current time step output of the filter
 */
uint16_t
dfilt_single_pole(uint16_t input, uint16_t prev_output, uint16_t alpha);

#endif
