#include <REG52.H>
#include "Delay.h"


void main(){
    P2_0 = 0;
    Delay(500);
    P2_0 = 1;
    Delay(500);
}