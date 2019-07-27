#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone{
	char name[20];
	char number[15];
} phone;

void Insert();
void Delete();
void Search();
void Print_All();

void f_read();
void f_write();

phone *people;
FILE *fp;
int max = 1;

int main(void){
	int select;

	f_read();
	while(1){
		printf("*****MENU*****\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Print All\n");
		printf("5. Exit\n");
		printf("Choose the item : ");
		scanf("%d",&select);
		getchar(); //\n버퍼 지우기
		
		switch(select){
		case 1:
			printf("[INSERT]\n");
			Insert();
			break;
		case 2:
			printf("[DELETE]\n");
			Delete();
			break;
		case 3:
			printf("[SEARCH]\n");
			Search();
			break;
		case 4:
			printf("[PRINT ALL]\n");
			Print_All();
			break;
		case 5:
			f_write();
			free(people);
			return 0;
		}
		printf("\n");
	}
}

void Insert(){
	people = (phone*)realloc(people,sizeof(phone)*max);

	printf("Input Name:");
	fgets(people[max-1].name,sizeof(people[max-1].name),stdin);
	people[max-1].name[strlen(people[max-1].name)-1] = '\0';
	printf("Input Number:");
	fgets(people[max-1].number,sizeof(people[max-1].number),stdin);
	people[max-1].number[strlen(people[max-1].number)-1] = '\0';

	max++;

	printf("Data Inserted :D\n");
}

void Delete(){
	char name[20];
	int i;

	printf("Input Name:");
	fgets(name,sizeof(name),stdin);
	name[strlen(name)-1] = '\0';

	for(i=0;i<(max-1);i++){
		if(!strcmp(name,people[i].name))
			break;
	}

	if(i<(max-1))
		for(;i<max-1;i++){
			strcpy(people[i].name,people[i+1].name);
			strcpy(people[i].number,people[i+1].number);
		}
	else
		if(!strcmp(name,people[i-1].name)){
			strcpy(people[i].name,NULL);
			strcpy(people[i].number,NULL);
		}
		else{
			printf("Not Find this Data :(\n");
			return;
		}
	max--;
	
	printf("Data Deleted :(\n");
}

void Search(){
	char name[20];
	int i;

	printf("Input Name:");
	fgets(name,sizeof(name),stdin);
	name[strlen(name)-1] = '\0';

	for(i=0;i<max-1;i++){
		if(!strcmp(name,people[i].name)){
			printf("Name : %s     Tel : %s\n",people[i].name,people[i].number);
			printf("Data Searched :)\n");
			return;
		}
	}
	printf("No Data Found :<\n");
	return;
}

void Print_All(){
	int i;

	for(i=0;i<max-1;i++){
		printf("Name : %s            tel : %s\n",people[i].name,people[i].number);
	}

	printf("Data printed all information :>\n");
}

void f_read(){
	int i;

	fp = fopen("phone.txt","a+");

	fseek(fp,0,SEEK_SET);
	
	//if(fp==NULL) f_write();

	fscanf(fp,"%d",&max);
	
	people = (phone*)realloc(people,sizeof(phone)*max);

	for(i=0; i<max-1; i++){
		fscanf(fp,"%s %s",people[i].name, people[i].number);
	}
	fclose(fp);
}

void f_write(){
	int i;

	fp = fopen("phone.txt","wt");

	fprintf(fp, "%d\n", max);


	for(i=0; i<max-1; i++){
		fprintf(fp,"%s %s\n",people[i].name, people[i].number);
	}
	fclose(fp);
}
