#include <LPC214X.H>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char i1[20]="12345678";												//RF ID Numbers
char i2[20]="23456789";
char i3[20]="34567891";
char bud[20]="2000";
char key,b[50],Q[50],id[20],v[20],e[20],m[20],h[40],g[20],s[20],tr[40],tr1[40],tr2[40],u[20],t[20],str[100];
int x,y,z,r1,r2,r3,k,bal1,bal2,bal3,b1,p,t1,amt=0,tot1,tot2,tot3,d,count=0,tot;
#include"lcd.h"
#include"keypad.h"
#include"uart.h"
#include"wifi.h"
#include"item_details.h"

int main()
{
PINSEL2=0x00000000;
Keypad_Init();
uart_init0();
uart_init1();
lcd_init();
IOPIN1=0x00000000;
display("WELCOME.....");
delay();
clear();
display("Give budget:");
display(bud);
nxt_line();
x=atoi(bud);
//at_start();
//at_send("\n\r\t\t***WELCOME***");
//at_send("\n\r*********************************************\n\r");	
//at_send("\t\tABC SHOPPING MALL");
//at_send("\n\r.............................................\n\r");	
//at_send("S.no\t\tProducts\t\tPrice\n\r");
//at_send(".............................................\n\r");	
//at_send();
 send_str("...................WELCOME........................");
 send_str("\n\r...............................................\n\r");	
 send_str("------------ABC SHOPPING MALL--------------");
 send_str("\n\r.............................................\n\r");	
 send_str("S.no---------Products-----------Price\n\r");
 send_str(".............................................\n\r");	

while(1)
{
  IOPIN0=0x0;
	if(IOPIN1&=(1<<25))

		{
		add_items();
		while(IOPIN1&=(1<<25));
	}
	if(IOPIN1&=(1<<26))
	{
		deducing();
		while(IOPIN1&=(1<<26));
	}
	if(IOPIN0&=(1<<2))
	{
		stop();
		while(IOPIN0&=(1<<2));
	}
//at_close();
}
}
