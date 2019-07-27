#include <stdio.h>
#include <stdlib.h>

int ErrPrint(int e);

int main(void) {
	char *a;
	int num;
	int temp, size;
	int cheak;
	int i, j;

	do {
		temp = cheak = i = j = 0;
		size = 5;

		a = (char*)calloc(size, sizeof(char));
		if (a == NULL) ErrPrint(5);

		printf("Input Number(Odd Number,1~50) : ");

		while ((a[i] = getc(stdin)) != '\n') {
			if ((a[i] >= '0') && (a[i] <= '9')) {
				if (cheak == 2) return ErrPrint(3);
				else if (cheak == 0) cheak++;
				i++;
			}
			else if (a[i] == ' ') {
				if (cheak == 1) cheak++;
				i++;
			}
			else
				return ErrPrint(2);

			if (i == (size - 1)) {
				size++;
				a = (char*)realloc(a, sizeof(char)*(size));
				a[size - 1] = '\0';
			}
		}
	} while (cheak == 0);

	num = atoi(a);

	if (num<0||num>50) return ErrPrint(4);

	if (num % 2 == 0) return ErrPrint(1);

	for (i = 0; i<num; i++) {
		if (i > num / 2) temp = num - i - 1;
		else temp = i;

		for (j = 0; temp>j; j++) printf(" ");
		for (j = num - (temp * 2); j>0; j--) printf("*");
		printf("\n");
	}

	free(a);

	return 0;
}

int ErrPrint(int e) {
	switch (e)
	{
	case 1:
		printf("Error 1 : Even Number\n");
		break;
	case 2:
		printf("Error 2 : Including Character\n");
		break;
	case 3:
		printf("Error 3 : Including Blank\n");
		break;
	case 4:
		printf("Error 4 : Range Out\n");
		break;
	case 5:
		printf("Error 5 : Your Computer is low on memory\n");
		break;
	}
	return 0;
}
