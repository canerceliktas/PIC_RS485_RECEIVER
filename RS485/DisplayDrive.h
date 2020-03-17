

void DisplayDrive()
{
	output_low(DIGIT1_COM);
	output_low(DIGIT2_COM);
	output_low(DIGIT3_COM);


    switch (DigitOrder)
    {
        case 0:
        OUTPUT_B(DIGIT_1);
        output_high(DIGIT1_COM);
        ++DigitOrder;
        break;

        case 1:
        OUTPUT_B(DIGIT_2);
        output_high(DIGIT2_COM);
        ++DigitOrder;
        break;

        case 2:
        OUTPUT_B(DIGIT_3);
        output_high(DIGIT3_COM);
        DigitOrder=0;
        break;

     }
	
}	