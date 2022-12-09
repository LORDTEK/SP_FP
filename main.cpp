#include "mbed.h"
#include "SP_FP.h"

Serial pc(USBTX, USBRX);  // TX, RX
SP_FP sp_fp;

int main() {
    pc.baud(9600);
    printf("uint32_t=0x41460000 \t float=%f\n", sp_fp.decoder(0x41460000));
    return 0;
}
