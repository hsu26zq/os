#include "io.h"
#include "utils.h"
//#include "printf.h"
#include "timer.h"
#include "sched.h"

#define TIMER_CS_M0	(1 << 0)
#define TIMER_CS_M1	(1 << 1)
#define TIMER_CS_M2	(1 << 2)
#define TIMER_CS_M3	(1 << 3)

enum {
    TIMER_CS       = PERIPHERAL_BASE + 0x00003000,
    TIMER_CLO      = PERIPHERAL_BASE + 0x00003004,
    TIMER_CHI      = PERIPHERAL_BASE + 0x00003008,
    TIMER_C0       = PERIPHERAL_BASE + 0x0000300C,
    TIMER_C1       = PERIPHERAL_BASE + 0x00003010,
    TIMER_C2       = PERIPHERAL_BASE + 0x00003014,
    TIMER_C3       = PERIPHERAL_BASE + 0x00003018,
};


const unsigned int interval = 200000;
unsigned int curVal = 0;

void timer_init ( void )
{
	curVal = get32(TIMER_CLO);
	curVal += interval;
	put32(TIMER_C1, curVal);
}

void handle_timer_irq( void ) 
{
	curVal += interval;
	put32(TIMER_C1, curVal);
	put32(TIMER_CS, TIMER_CS_M1);
	timer_tick();
}