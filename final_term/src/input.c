#include "type.h"


int Input(void) {
	char *a;
	int num = 0;
	int size = 5;
	int i = 0;
	
	if (!(a = (char*)calloc(size, sizeof(char)))) return MNULLERR;

	printf("Input Number(Odd Number,0~49) : ");

	while ((a[i] = getc(stdin)) != '\n') {
		if (num < 0);
		else if ((a[i] >= '0') && (a[i] <= '9')) {
			if (num == 2)	num = BLANKERR;
			else if (num == 0) num++;
			i++;
		}
		else if (a[i] == ' ' || a[i] == '\t') {
			if (num == 1) num++;
			i++;
		}
		else
			num = CHARERR;

		if (i == (size - 1)) {
			size += 5;
			if (!(a = (char*)realloc(a, sizeof(char)*(size)))) num = MNULLERR;
			a[size - 1] = '\0';
		}
	}
	
	if (num >= 0){
		num = atoi(a);
		if (num <0 || num >= 50) num = RANGEERR;
		if (num % 2 == 0) num = EVENERR;
	}

	free(a);

	return num;
}
