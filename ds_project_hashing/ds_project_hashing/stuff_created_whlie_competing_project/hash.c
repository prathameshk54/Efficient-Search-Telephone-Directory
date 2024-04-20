#include<stdio.h>
#include"person.h"
#include<string.h>
#include<stdlib.h>
int hashing(person* p) {
	person *ph = (person*)malloc(sizeof(person)*2048);
	for(i = 0; i < ) {
		key = getKey((p+i)->name);
		strcpy(ph[key].name, p[i].name);
		strcpy(ph[key].number, p[i].number);
	}
}
