#include "io.h"
#include "fb.h"
#include "timer.h"
#include "irq.h"
#include "fork.h"
#include "sched.h"
#include "utils.h"


void process1(char *array)
{
	while (1){
		for (int i = 0; i < 5; i++){
			uart_writeText("THis is process 1!\n");
			delay(100000);
		}
	}
}
void process2(char *array)
{
	while (1){
		for (int i = 0; i < 5; i++){
			uart_writeText("This si process 2!\n");
			delay(100000);
		}
	}
}
void process3(char *array)
{
	while (1){
		for (int i = 0; i < 5; i++){
			uart_writeText("This si process 3!\n");
			delay(100000);
		}
	}
}



void main()
{
    uart_init();
    //fb_init();
    irq_vector_init();
    timer_init();
    enable_interrupt_controller();
    enable_irq();

    copy_process((unsigned long)&process1, (unsigned long)"");
    copy_process((unsigned long)&process2, (unsigned long)"");
    copy_process((unsigned long)&process3, (unsigned long)"");


    while (1)
    {
		schedule();
	}

	//while (1){
		//schedule();
	//}
    
    //uart_writeText("Hello world!\n");
    //uart_readText();
    

    /*
    drawRect(150,150,400,400,0x03,0);
    drawRect(300,300,350,350,0x2e,1);

    drawCircle(960,540,250,0x0e,0);
    drawCircle(960,540,50,0x13,1);

    drawPixel(250,250,0x0e);

    drawChar('O',500,500,0x05);
    drawString(100,100,"Hello world!",0x0f);

    drawLine(100,500,350,700,0x0c);

    while (1);
    */
}