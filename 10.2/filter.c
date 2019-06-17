#include "filter.h"

extern int y;
int x[NUMBER_OF_SAMPLES];
unsigned int n;
unsigned int CurrentSample;
unsigned int CumulativeSum;

void AverageFilter()
{
    //Update CumulativeSum, keeping in mind previous values
    CumulativeSum += CurrentSample - x[n];

    // Update the sample array, x.
    x[n] = CurrentSample;

    // Generate the filter output
    y = CumulativeSum >> 6;

    //Circular buffer array index
    n = (n+1) & (NUMBER_OF_SAMPLES-1);
}

void NotchFilter() {

    //Update the sample array x
    x[n] = CurrentSample;

    //Generate the filter output
    unsigned int d = 32;

    int sum = 0;

    //y[n] = (x[n]+x[n-d])/2
    if(n < d) {

        //Shift n up 32 spots
        n += d;

        sum = x[n]+x[n-d];

        //Divide by 2
        y = sum >> 1;

        //Restore n to previous value
        n -= d;

    }
    else {

        sum = x[n]+x[n-d];

        y = sum >> 1;
    }

    //Circular buffer array index
    n = (n+1) & (NUMBER_OF_SAMPLES-1);
}

