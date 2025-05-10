#include <LPC214x.h>

#define LCD 0x000000FF
#define RS (1<<16)
#define EN (1<<17)

void delay(unsigned int time) {
	unsigned int i, j;
	for(i = 0; i < time; i++) {
		for(j = 0; j < 1275; j++);
	}
}
void LCD_cmd(unsigned char cmd){
	IOCLR0=LCD;
	IOSET0=cmd;
	IOCLR1=RS;
	IOSET1=EN;
	delay(10);
	IOCLR1=EN;
}
void LCD_str(unsigned char data){
	IOCLR0=LCD;
	IOSET0=data;
	IOSET1=RS;
	IOSET1=EN;
	delay(10);
	IOCLR1=EN;
}
void LCD_init(){
	LCD_cmd(0x38);
	delay(20);
	LCD_cmd(0x01);
	delay(20);
	LCD_cmd(0x0E);
	delay(20);
	LCD_cmd(0x80);
	delay(20);
}
int main() {
	unsigned char txt[]="OMKAR";
	unsigned int i;
	IODIR0 |= LCD;
	IODIR1 |= RS;
	IODIR1 |= EN;
	LCD_init();
		for(i=0;i<5;i++){
			LCD_str(txt[i]);
			delay(10);
		}
}

