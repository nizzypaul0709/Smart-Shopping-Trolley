void at_start()
{
	send_str("AT\n\r");
	delay_ms(200);
	send_str("AT+RST\n\r");
	delay_ms(200);
	send_str("AT+CWMODE=1\n\r");
	delay_ms(200);
	send_str("AT+CIPMUX=0\n\r");
	delay_ms(200);
	send_str("AT+CWJAP=\"lenovo\",\"9567583318\"\n\r");
	delay_ms(200);
	nxt_line();
	display("hello");
	send_str("AT+CIPSTART=\"TCP\",\"183.106.153.149\",80\n\r");
	delay_ms(200);
 }
 
 void at_send(char *p)
 {
	send_str("AT+CIPSEND=1000\n\r");
	delay_ms(200);	
	sprintf(str,"GET/update?api_key=DUM7QTL76K03E65L&filed1=%s",p);
	 send_str(str);
// 	send_str("GET/update?");
// 	send_str("api_key=       \n\r ");
  delay_ms(200);	 
	 
 }
 
 void at_close()
 {
	send_str("AT+CIPCLOSE");
	 delay_ms(200);
 }

