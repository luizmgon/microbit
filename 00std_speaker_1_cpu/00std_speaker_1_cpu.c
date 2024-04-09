#include "nrf52833.h"

void wait(int time) {
    volatile uint32_t a;
    for (a=0; a<time;a++);
}

int main(void) {
    
    // set speaker pin as output
    NRF_P0->PIN_CNF[0] = 0x00000003; // P0.00

    int time = 0;

    while(1) {

        time += 7;

        NRF_P0->OUTSET = (0x00000001 << 0); // speaker pin high
        wait(time);
        NRF_P0->OUTCLR = (0x00000001 << 0); // speaker pin low
        wait(time);

        time = time % 5000;
    }
}
