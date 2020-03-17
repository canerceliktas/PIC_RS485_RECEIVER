//       0b bfaeddpcg
void Convert7Segment(ref)
{
	switch (ref)
	{
		case 0:
		DIGIT_TEMP=(0b11111010);
		break;

		case 1:
		DIGIT_TEMP=(0b10000010);
		break;

		case 2:
		DIGIT_TEMP=(0b10111001);
		break;

		case 3:
		DIGIT_TEMP=(0b10101011);
		break;

		case 4:
		DIGIT_TEMP=(0b11000011);
		break;

		case 5:
		DIGIT_TEMP=(0b01101011);
		break;

		case 6:
		DIGIT_TEMP=(0b01111011);
		break;

		case 7:
		DIGIT_TEMP=(0b10100010);
		break;

		case 8:
		DIGIT_TEMP=(0b11111011);
		break;

		case 9:
		DIGIT_TEMP=(0b11101011);
		break;
	}


}