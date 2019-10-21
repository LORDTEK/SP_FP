#ifndef SP_FP_H
#define SP_FP_H
#include "mbed.h"

class SP_FP {
public:
    SP_FP();
    float decoder(uint32_t VALUE);

private:
    float result;
    uint32_t value_Temp;  // Needed because of bitwise operations
};

#endif
