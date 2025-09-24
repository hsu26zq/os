#include "io.h"
#include "utils.h"
//#include "printf.h"
#include "timer.h"
#include "entry.h"

#define SYSTEM_TIMER_IRQ_0	(1 << 0)
#define SYSTEM_TIMER_IRQ_1	(1 << 1)
#define SYSTEM_TIMER_IRQ_2	(1 << 2)
#define SYSTEM_TIMER_IRQ_3	(1 << 3)

enum
{
    IRQ_BASIC_PENDING = PERIPHERAL_BASE + 0x0000B200,
    IRQ_PENDING_1     = PERIPHERAL_BASE + 0x0000B204,
    IRQ_PENDING_2     = PERIPHERAL_BASE + 0x0000B208,
    FIQ_CONTROL       = PERIPHERAL_BASE + 0x0000B20C,
    ENABLE_IRQS_1     = PERIPHERAL_BASE + 0x0000B210,
    ENABLE_IRQS_2     = PERIPHERAL_BASE + 0x0000B214,
    ENABLE_BASIC_IRQS = PERIPHERAL_BASE + 0x0000B218,
    DISABLE_IRQS_1    = PERIPHERAL_BASE + 0x0000B21C,
    DISABLE_IRQS_2    = PERIPHERAL_BASE + 0x0000B220,
    DISABLE_BASIC_IRQS= PERIPHERAL_BASE + 0x0000B224
};

const char *entry_error_messages[] = {
	"SYNC_INVALID_EL1t",
	"IRQ_INVALID_EL1t",		
	"FIQ_INVALID_EL1t",		
	"ERROR_INVALID_EL1T",		

	"SYNC_INVALID_EL1h",		
	"IRQ_INVALID_EL1h",		
	"FIQ_INVALID_EL1h",		
	"ERROR_INVALID_EL1h",		

	"SYNC_INVALID_EL0_64",		
	"IRQ_INVALID_EL0_64",		
	"FIQ_INVALID_EL0_64",		
	"ERROR_INVALID_EL0_64",	

	"SYNC_INVALID_EL0_32",		
	"IRQ_INVALID_EL0_32",		
	"FIQ_INVALID_EL0_32",		
	"ERROR_INVALID_EL0_32"	
};

void enable_interrupt_controller()
{
	put32(ENABLE_IRQS_1, SYSTEM_TIMER_IRQ_1);
}

void show_invalid_entry_message(int type, unsigned long esr, unsigned long address)
{
	//printf("%s, ESR: %x, address: %x\r\n", entry_error_messages[type], esr, address);
}

void handle_irq(void)
{
	unsigned int irq = get32(IRQ_PENDING_1);
	switch (irq) {
		case (SYSTEM_TIMER_IRQ_1):
			handle_timer_irq();
			break;
		//default:
			//printf("Unknown pending irq: %x\r\n", irq);
	}
}