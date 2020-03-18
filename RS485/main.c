/* 
 * File:   main.c
 * Author: Orkun OKUR
 *
 * Created on 12 Subat 2020 Çarsamba, 10:58
 */
#include 	<16F1788.h>
#device     PIC16F1788


#device 	adc=8
#FUSES      INTRC_IO, NOWDT, PUT, MCLR, PROTECT, CPD, BROWNOUT, NOCLKOUT, NOIESO, NOFCMEN, NOVCAP, BORV19  		
#use 		delay(clock=16000000)
//#use rs232  (baud=9600, xmit=PIN_C6, rcv=PIN_C7, ENABLE=PIN_A3, PARITY=E, STOP=1,FORCE_SW)
#use fast_io(c)
#use fast_io(a)
#ZERO_RAM

#include <stdio.h>	
#include	"Definition.h"
#include	"DisplayDrive.h"
#include	"LookUpTable.h"
#include    <rs485.c>


/*#######################################################################*/
#int_TIMER0
void  TIMER0_isr(void) 				//8.192ms
{
	++TIME_MAKER;
    set_timer0(timer0_value);
    DisplayDrive();
}
/*#######################################################################*/

void ConvertDECtoBCD(int16 decimal)
{
    BCD_100=(decimal/100);
    BCD_10=((decimal-(BCD_100*100))/10);
    BCD_1=((decimal-(BCD_100*100)-(BCD_10*10)));
}
/*#######################################################################*/
/*#######################################################################*/
void AssignDigits(int16 value)
   {
       ConvertDECToBCD(value);
       Convert7Segment(BCD_100);
       DIGIT_1=DIGIT_TEMP;
       Convert7Segment(BCD_10);
       DIGIT_2=DIGIT_TEMP;
       Convert7Segment(BCD_1);
       DIGIT_3=DIGIT_TEMP;
   }

void main ()
{
	setup_oscillator(OSC_16MHZ);
	setup_timer_0(T0_INTERNAL|T0_DIV_16|T0_8_BIT);      //500us overflow

    
    setup_adc (ADC_OFF);

    setup_ccp1(CCP_OFF);
	setup_ccp2(CCP_OFF);
    setup_ccp3(CCP_OFF);    
    setup_dac(DAC_OFF);
    setup_comparator_1(NC_NC);
    setup_comparator_2(NC_NC);
    setup_comparator_3(NC_NC);
    setup_comparator_4(NC_NC);
	enable_interrupts(INT_TIMER0);
	disable_interrupts(GLOBAL);
 

  	SET_TRIS_A(0b00000010);
	SET_TRIS_B(0b00000000);
	SET_TRIS_C(0b10000000);
	SET_TRIS_E(0b00001000);

    
    port_c_pullups(0b11000000);
    
    rs485_init();

    enable_interrupts(GLOBAL);
    
 //   data=0b10000111;
    
   int ahmet[]={99};
   int  veli,old_veli;
   unsigned int8 reflected_msg[3];
    
	while(1)
		{
            restart_wdt();

			if	(TIME_MAKER>=2)		//1msn lik i?ler
			{
                restart_wdt();
				TIME_MAKER=0;
				++REG_10ms;
				///////
                

                
  
			}	

			if	(REG_10ms>=10)		//10msn lik i?ler
			{
				REG_10ms=0;
				++REG_50ms;
				///////
                
                veli=rs485_buffer[6];
                reflected_msg[0] = rs485_buffer[4];
                reflected_msg[1] = rs485_buffer[5];
                reflected_msg[2] = rs485_buffer[6];
                AssignDigits(veli);
                    rs485_ni=0;
                
                if(veli!=old_veli)
                {
//                    
//                    memset(&rs485_buffer, 0, sizeof(rs485_buffer));
//                    AssignDigits(veli);
//                    rs485_ni=0;
                    delay_ms(5);
                    rs485_send_message(RS485_DEST_ID,sizeof(reflected_msg),&reflected_msg);
                }
                old_veli=veli; 

			}	

			if	(REG_50ms>=5)		//50msn lik i?ler
			{
				REG_50ms=0;
				++REG_100ms;
				///////
//                 output_toggle(LED);

     		}	
			
			if	(REG_100ms>=2)		//100msn lik i?ler
			{
				REG_100ms=0;
				++REG_500ms;
				///////
//                to*=12;
                

                

			}		
		 
			if	(REG_500ms>=5)		//500msn lik i?ler
			{
				REG_500ms=0;
				++REG_1s;
				///////

			}	
		 	
		 	if	(REG_1s>=2)		//1000msn lik i?ler
			{
				REG_1s=0;
				///////
//                data=0b10000111;
//                ++data;
//                data=0x38;
//                rs485_wait_for_bus(TRUE);
//                rs485_send_message(RS485_DEST_ID,1,&ahmet,);
//                AssignDigits(ahmet[0]);

            }
        
            if	(REG_10s>=10)		//10 saniye lik isler
			{
                REG_10s=0;
				///////
   
            }
            
		}
		
}


