#include "type.h"

void Run(int num) {
	int temp;
	int i, j;
	
	for (i = 0; i<num; i++) {
		if (i > num / 2) temp = num - i - 1;
		else temp = i;

		for (j = 0; temp>j; j++) printf(" ");
		for (j = num - (temp * 2); j>0; j--) printf("*");
		printf("\n");
	}
	
	return ;
}