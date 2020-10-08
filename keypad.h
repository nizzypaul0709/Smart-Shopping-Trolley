void Keypad_Init()
   {
   PINSEL1 =0x0000; 
   IODIR0 = (0x00780000); // P0.[22:19] - Kp-i/p (MU-o/p), P0.[18:16] - Kp-o/p (MU-i/p)
   }


   char Keypad()
 {
   while(1)
   {
   IOPIN0 = (0x8<<19);	  // P0.22 - High
   if(IOPIN0&(1<<22))
   {
    if(IOPIN0&(1<<18)){ while(IOPIN0&(1<<18)); return'1';}
    if(IOPIN0&(1<<17)){ while(IOPIN0&(1<<17)); return'2';}
    if(IOPIN0&(1<<16)){ while(IOPIN0&(1<<16)); return'3';}
		display("haaii");
   }
 
   IOPIN0 = (0x4<<19);   // P0.21 - High
   if(IOPIN0&(1<<21))
   {
     if(IOPIN0&(1<<18)){ while(IOPIN0&(1<<18)); return'4';}
     if(IOPIN0&(1<<17)){ while(IOPIN0&(1<<17)); return'5';}
	   if(IOPIN0&(1<<16)){ while(IOPIN0&(1<<16)); return'6';}
   }

   IOPIN0 = (0x2<<19);  // P0.20 - High
   if((IOPIN0&(1<<20)))
   {
    if(IOPIN0&(1<<18)){ while(IOPIN0&(1<<18)); return'7';}
    if(IOPIN0&(1<<17)){ while(IOPIN0&(1<<17)); return'8';}
	  if(IOPIN0&(1<<16)){ while(IOPIN0&(1<<16)); return'9';}
   }   

   IOPIN0 = (0x1<<19);  // P0.19 - High
   if((IOPIN0&(1<<19)))
   {
  	if(IOPIN0&(1<<18)){ while(IOPIN0&(1<<18)); return'*';}
    if(IOPIN0&(1<<17)){ while(IOPIN0&(1<<17)); return'0';}
	  if(IOPIN0&(1<<16)){ while(IOPIN0&(1<<16)); return'#';}
   }
  }
}
