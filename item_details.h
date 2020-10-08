int balance(int r1)																					//To calculate the balance budget amount
{
int flag=0;
x=x-r1;
if(x<=0)
{
flag=1;
}
if(flag==1)
{
	clear();
display("No Balance.........");
while(1);
}
else
return x;
}


int total(int t1)																						//To calculate the total amount 
{
amt=amt+t1;
return amt;
}


void item1()																								//Details of item 1
{
char a[10]="150";
clear();
display("surf excel");
nxt_line();
y=atoi(a);
sprintf(v,"%d",y);
display("price:");
display(v);

//at_send("\t\tsurf excel\t\t");
//at_send(v);
	send_str("\t\tsurf excel\t\t");
	send_str(v);
delay();
clear();

display("Balance:");
bal1=balance(y);
sprintf(m,"%d",bal1);
display(m);
nxt_line();

display("total:");
tot1=total(y);
sprintf(tr,"%d",tot1);
display(tr);
 send_str("\n\r");
//at_send("\n\r");
delay();
}

void item2()																						//Details of item 2
{
char a[10]="50";
display("lux");

nxt_line();
z=atoi(a);
sprintf(e,"%d",z);
display("price:");
display(e);
 send_str("\t\tlux\t\t\t");
 send_str(e);
//at_send("\t\tlux\t\t\t");
//at_send(e);
delay();
clear();

display("Balance:");
bal2=balance(z);
sprintf(h,"%d",bal2);
display(h);
nxt_line();

display("total:");
tot2=total(z);
sprintf(tr1,"%d",tot2);
display(tr1);
 send_str("\n\r");
//at_send("\n\r");
delay();
}

void item3()																					//Details of item 3
{
char a[10]="250";
display("carpet");

nxt_line();
p=atoi(a);
sprintf(g,"%d",p);
display("price:");
display(g);
 send_str("\t\tcarpet\t\t\t");
 send_str(g);
//at_send("\t\tcarpet\t\t\t");
//at_send(g);
delay();
clear();

display("Balance:");
bal3=balance(p);
sprintf(s,"%d",bal3);
display(s);
nxt_line();

display("total:");
tot3=total(p);
sprintf(tr2,"%d",tot3);
display(tr2);
send_str("\n\r");
//at_send("\n\r");
delay();
}


void add_items()																								//To add the product to the list
{
int i;
count++;
sprintf(Q,"%d",count);
display("scan id:");
send_str(Q);
//at_send(Q);
for(i=0;i<10;i++)
 {
	id[i]=rx_id();
	 }
id[8]='\0'; 
delay();
clear();
if(strcmp(id,i1)==0)
{
 item1();
delay_ms(20);
command(0x01);
}

else if(strcmp(id,i2)==0)
{
  item2();
  delay_ms(20);
clear();
}

else if(strcmp(id,i3)==0)
{
   item3();
  delay_ms(20);
clear();
}
 else 
{
	clear();
display("wrong entry..........");
}
}


void deducing()																				//To deduce the product from the list
{
	int i;
count++;
sprintf(Q,"%d",count);
display("scan id:");
send_str(Q);
//at_send(Q);
for(i=0;i<10;i++)
 {
	id[i]=rx_id();
	 }
id[8]='\0'; 
display(id);
delay();
clear();
if(strcmp(id,i1)==0)
{
 char a[10]="150";
display("surf excel");

nxt_line();
y=atoi(a);
sprintf(v,"%d",y);
display("price:");
display(v);
 send_str("\t\tsurf excel\t\t");
 send_str(v);
//at_send("\t\tsurf excel\t\t");
//at_send(v);
delay();
clear();
display("item deduced........");
 send_str("\t\titem deduced");
//at_send("\t\titem deduced");
delay();
clear();

display("new Balance:");
x=x+y;
sprintf(m,"%d",x);
display(m);
nxt_line();

display("total:");
amt=amt-y;
sprintf(tr,"%d",amt);
display(tr);
 send_str("\n\r");
//at_send("\n\r");
delay();
}
else if(strcmp(id,i2)==0)
{
  char a[10]="50";
display("lux");

nxt_line();
z=atoi(a);
sprintf(e,"%d",z);
display("price:");
display(e);
 	send_str("\t\tlux\t\t\t");
 send_str(e);
//at_send("\t\tlux\t\t\t");
//at_send(e);
delay();
clear();
	display("item deduced........");
send_str("\t\titem deduced");
//	at_send("\t\titem deduced");
delay();
clear();

display("Balance:");
x=z+x;
sprintf(h,"%d",x);
display(h);
nxt_line();

display("total:");
amt=amt-z;
sprintf(tr1,"%d",amt);
display(tr1);
//at_send("\n\r");
 send_str("\n\r");
delay();
  delay_ms(20);
clear();
}

else if(strcmp(id,i3)==0)
{
   
  char a[10]="250";
display("carpet");

nxt_line();
p=atoi(a);
sprintf(g,"%d",p);
display("price:");
display(g);
 	send_str("\t\tcarpet\t\t\t");
 send_str(g);
//at_send("\t\tcarpet\t\t\t");
//at_send(g);
delay();
clear();
	display("item deduced........");
 send_str("\t\titem deduced");
//at_send("\t\titem deduced");
delay();
clear();

display("Balance:");
x=p+x;
sprintf(s,"%d",x);
display(s);
nxt_line();

display("total:");
amt=amt-p;
sprintf(tr2,"%d",amt);
display(tr2);
 send_str("\n\r");
//at_send("\n\r");
delay();
clear();
}
 else 
{
	clear();
display("wrong entry..........");
}
}

void stop()																										//To stop the purchase
{
clear();
tot=total(0);
sprintf(t,"%d",tot);
 send_str("\n\r...................................................\n\r");
 send_str("\t\t\tGrand Total:\t");
 send_str(t);
 send_str("\n\r...................................................\n\r");
 send_str("\n\r\t***Thank You...Come Again...***");
//at_send("\n\r...................................................\n\r");
//at_send("\t\t\tGrand Total:\t");
//at_send(t);
//at_send("\n\r...................................................\n\r");
//at_send("\n\r\t***Thank You...Come Again...***");
display("End Purchase.........");
clear();
display("Thank You...");
nxt_line();
display("Come Again...");
while(1);
}

