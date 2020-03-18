#define		timer1_value        61580
#define		timer0_value        132


//#define     LED         PIN_C6
#define     DIGIT1_COM  PIN_C1
#define     DIGIT2_COM  PIN_C0
#define     DIGIT3_COM  PIN_A5

#define RS485_ID    0x29 
#define RS485_DEST_ID    0x17
#define RS485_RX_BUFFER_SIZE    8

#define RS485_RX_PIN       PIN_C7   // Data receive pin
#define RS485_TX_PIN       PIN_C6   // Data transmit pin
#define RS485_ENABLE_PIN   PIN_A3   // Controls DE pin.  RX low, TX high.




int1    snd;
unsigned int8   TIME_MAKER,REG_10ms,REG_50ms,REG_100ms,REG_500ms,REG_1s,REG_10s;
unsigned int8   DigitOrder,DIGIT_1,DIGIT_2,DIGIT_3,DIGIT_TEMP;
unsigned int8   data;
unsigned int16  BCD_100,BCD_10,BCD_1;

