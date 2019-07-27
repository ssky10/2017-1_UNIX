#include "type.h"

int main(void) {
	int num;

	do {
		num = Input();

		if (num < 0) 
			ErrPrint(num);					
		else
			Run(num);
		
	} while (num < 0);
	
	return 0;
}

int ErrPrint(int e) {
	switch (e)
	{
	case EVENERR:
		printf("Error 1 : Even Number\n");
		break;
	case CHARERR:
		printf("Error 2 : Including Character\n");
		break;
	case BLANKERR:
		printf("Error 3 : Including Blank\n");
		break;
	case RANGEERR:
		printf("Error 4 : Range Out\n");
		break;
	case MNULLERR:
		printf("Error 5 : Your Computer is low on memory\n");
		break;
	}
	return 0;
}
