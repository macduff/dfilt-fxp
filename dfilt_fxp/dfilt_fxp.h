#ifndef DFILT_FXP_H_
#define DFILT_FXP_H_

#include <stdint.h>

uint16_t
dfilt_single_pole(uint16_t input, uint16_t prev_output, uint16_t alpha);

#endif
