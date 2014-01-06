#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpmbdos.h"
#include "cprintf.h"
#include "cbm_sysfunc.h"

void sys_init(void) {
}

/*
static __sfr __at 0x63 IoPPICtrl;
*/

int main() {
	// Prepare a command to send the BEL character
	BDOSCALL bellcall = { C_WRITE, {(unsigned int)7} };
	int idx;

	sys_init();
	
	printf("HELLO WORLD!\n");

	for (idx = 0; idx < 20; idx++) {
		printf("%d\n", idx);
		cpmbdos(&bellcall); // Make the console beep a bit!
	}

	cbm_putchar(0x1B);
	cbm_putchar('<');

	cbm_putchar(0x1B);
	cbm_putchar('[');
	cbm_putchar('2');
	cbm_putchar('J');

	return (EXIT_SUCCESS);
}

void delay(unsigned char d) {
	d;

	__asm
		; Save used registers
		nop
		; Read parameters from stack
		nop
		; Do the work
		nop
		; Restore saved registers
		nop
	__endasm;
}

