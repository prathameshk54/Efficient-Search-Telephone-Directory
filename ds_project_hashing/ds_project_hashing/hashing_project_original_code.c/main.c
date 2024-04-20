#include<stdio.h>
//#include"person.h"
#include<stdlib.h>
#include<string.h>
typedef struct person {
	char name[50];
	char number[20];
	struct person* next;
} person;
typedef struct hash {
	person *head;
	int count;
} hash;
person* getData(char*);
int getKey(char*);
hash* init_hash();
void insert_hash(char*, char*, hash*);
void hashing(person*, hash*);
person* chain(char*, char*, person*);
person* init(char*, char*, person*);
person* createnode(char*, char*);

int main(int argc, char* argv[]) {
	person *p;
	hash* hasht;
	int i;
	p = getData(argv[1]);
	for(i = 0; i < 10; i++) {
		printf("%s, ", p[i].name);
		printf("%s\n", p[i].number);
	}
	hasht = init_hash();
	hashing(p, hasht);
	i = 130;
//	for(i = 0; i < 5; i++)
	printf("%s, %s\n", hasht[i].head->name, hasht[i].head->number);
	return 0;
}
