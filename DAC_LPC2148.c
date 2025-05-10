#include <LPC214x.h>

void delay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<720;j++);
}

int main(){
unsigned int value;
	IODIR0 |= (1<<25);
	DACR =0;
	while(1){
	for(value = 0; value <= 1023; value++) {
            DACR = value << 6;   // 10-bit data left-aligned at bit 6
            delay(1);            // Small delay for smooth rise
        }

	}
}