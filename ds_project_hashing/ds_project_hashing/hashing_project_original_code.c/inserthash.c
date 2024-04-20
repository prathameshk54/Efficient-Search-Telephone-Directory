#include<stdlib.h>
#include<string.h>
#include"person.h"
person* createnode(person *p) {
	person* newnode;
	newnode =  (person*)malloc(sizeof(person));
	*newnode = *p;
	newnode->next = NULL;
	return newnode;
}
person* chain(person* p, person* head) {
	person* newnode = createnode(p);
	newnode->next = head;
	head = newnode;
	return head;	
}
person* init(person* p, person* head) {
	person* newnode = createnode(p);
	newnode->next = NULL;
	head = newnode;
	return head;
}
void insert_hash(person* p, hash *hasht) {
	int hashIndex;
	hashIndex = getKey(p->name);
	if(hasht[hashIndex].count == 0) {
		init(p, hasht[hashIndex].head);
		hasht[hashIndex].count = 1;
	}	
	else {
		chain(p, hasht[hashIndex].head);
		hasht[hashIndex].count++;
	}
}

