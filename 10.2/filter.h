#ifndef FILTER_H_
#define FILTER_H_

#include <msp430.h>

#define NUMBER_OF_SAMPLES 64

void AverageFilter(void);
void NotchFilter(void);

#endif /* FILTER_H_ */
