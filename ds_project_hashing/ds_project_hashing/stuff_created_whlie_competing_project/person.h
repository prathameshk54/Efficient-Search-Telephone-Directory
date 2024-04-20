typedef struct person {
	char name[50];
	char number[20];
	struct person* next;
} person;
person* getData(char* );
