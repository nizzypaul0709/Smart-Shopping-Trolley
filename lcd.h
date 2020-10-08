#define RS (1<<24)
#define RW (1<<23)
#define EN (1<<22)
void delay()
{
 int i;
 for(i=0;i<12000000;i++);
}
 void delay_ms(int a)
{

T0PC=0;
T0PR=14999;
T0MCR=2;
T0MR0=a;
T0TCR=1;
while(T0TC!=T0MCR);
T0TC=0;
}



void command(char a)
{
char b;
IOCLR0=0XFFFF;
IOCLR1=RS;
IOCLR1=RW;

b=a&0xF0;
IOSET0|=b<<6;
IOSET1=EN;
delay_ms(20);
IOCLR1=EN;

IOCLR0=0XFFFF;
IOCLR1=RS;
IOCLR1=RW;

b=a&0X0F;
IOSET0|=b<<10;
IOSET1=EN;
delay_ms(20);
IOCLR1=EN;
}

int data(char a)
{
char b;
IOCLR0=0XFFFF;
IOSET1=RS;
IOCLR1=RW;

b=a&0xF0;
IOSET0|=b<<6;
IOSET1=EN;
delay_ms(20);
IOCLR1=EN;

IOCLR0=0XFFFF;
IOSET1=RS;
IOCLR1=RW;

b=a&0X0F;
IOSET0|=b<<10;
IOSET1=EN;
delay_ms(20);
IOCLR1=EN;
return 0;
}

  void lcd_init()
{
IODIR0|=0X3C00;
IODIR1|=0X01C00000;
command(0x33);
command(0x32);
command(0x28);
command(0x0C);
command(0x01);
}

void display(char b[])
{
int i;
for(i=0;b[i]!='\0';i++)
{
data(b[i]);
}
} 

void clear()
{
	command(0x01);				//clear display
	command(0x02);				//return home
}

void nxt_line()
{
	command(0xc0);
}
void returns()
{
	command(0x02);
}
void backspace()
{
	command(0x10);
}
