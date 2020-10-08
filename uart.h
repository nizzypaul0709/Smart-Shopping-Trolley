void uart_init0()
{
PINSEL0|=0X05;
U0LCR=0x83;
U0DLL=97;
U0LCR=0x03;
}
void uart_init1()
{
PINSEL0|=(0x5<<16);
U1LCR=0x83;
U1DLL=97;
U1LCR=0x03;
}


void rx_char()
{
	while(!(U0LSR&(1<<0)));
	d=U0RBR;
       // delay_ms(50);
}


void recve_str()
{
int k;
   for(k=0;;k++)
    {
        while(!(U0LSR&(1<<0)));
        b[k]=U0RBR;
        if(b[k]=='\r')
        {
            break;
        }
    }
    b[k]='\0';
}


void send_str(char *p)
{
  while(*p!='\0')
   {	 
     U0THR=*p;
     while(!(U0LSR&(1<<6)));
	// delay_ms(10);
     p++;
    }
}

unsigned char rx_id()
{
	   while(!(U1LSR&(1<<0))); 
	   return U1RBR;
        
}

void tx_char(char q)
{
		U1THR=q;
     while(!(U1LSR&(1<<6)));
}

void send_str1(char *p)
{
  while(*p!='\0')
   {	 
     U1THR=*p;
     while(!(U1LSR&(1<<6)));
     p++;
    }
}

