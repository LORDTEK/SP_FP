#include "SP_FP.h"
#include "mbed.h"

SP_FP::SP_FP() {
    result = 0.0f;
    value_Temp = 0;
}

float SP_FP::decoder(uint32_t VALUE) {
    (VALUE >> 31) ? result = -1.0f : result = 1.0f;  // Determine sign
    value_Temp = VALUE << 1;  // Delete sign bit
    value_Temp = value_Temp >> 24;  // Make it alone only exponent
    result *= pow(2.0f, ((float) ((int) value_Temp - 127)));  // E (will be pow of 2) = X - 127
    value_Temp = VALUE << 9;  // Delete after 23rd bit
    value_Temp = value_Temp >> 9;  // Make it alone only mantissa (fraction, significand)
    result *= 1.0f + (float) value_Temp / 8388608.0f;  // pow(2.0, 23.0) thanks to http://softelectro.ru
    return result;
}
