#include <LPC214x.h>

#define LED 0x000000FF
#define switch (1<<16)
void delay(unsigned int time) {
	unsigned int i, j;
	for(i = 0; i < time; i++) {
		for(j = 0; j < 1275; j++);
	}
}

int main() {
	unsigned char pattern = 0x01;
	int a; // Move declaration outside for loop
	IODIR0 |= LED;
	IODIR1 &= ~switch;
	while(1) {
		IOCLR0 = LED;
		if(!(IOPIN1 & switch)){
		for(a = 0; a < 8; a++) {
			IOSET0 = pattern << a; // Shift by 'a'
			delay(200);
			IOCLR0 = LED; // Turn off LED before next
		}
	}
	}
}
