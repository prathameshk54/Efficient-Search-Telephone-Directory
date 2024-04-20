#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
typedef struct person {
        char name[50];
        char number[20];
        struct person* next;
} person;
typedef struct hash {
        struct person *head;
        int count;
} hash;
person* getData(char*);
int getKey(char*);
hash* init_hash();
void insert_hash(person*, hash*);
void hashing(person*, hash*);
person* chain(person*, person*);
person* init(person*, person*);
person* createnode(person*);

//Function Definations

person* getData(char file[]) {
        int fd, i = 0, j = 0, k = 0, flag = 0;
        char ch;
        person *p = (person*)malloc(sizeof(person)*10005);
        fd = open(file, O_RDONLY);
        if(fd == -1) {
                perror("Failed to open the file\n");
                return NULL;
        }
        while(read(fd, &ch, 1)) {
                if(ch == '\n') {
                        flag = 0;
			p[i].number[k] = '\0';
                        i++;
                        j = 0;
                        k = 0;
                        continue;
                }

                if(ch == ',') {
                        flag = 1;
			p[i].name[j] = '\0';
                        continue;
                }
                if(flag == 0)
                        p[i].name[j++] = ch;
                else
                        p[i].number[k++] = ch;

        }
        close(fd);
        return p;
 }
//key is sum of the ascii characters in the name of the person
int getKey(char* name) {
        int i, key = 0;
        for(i = 0; name[i] != '\0'; i++) {
                key = key + name[i];
                key = key % 256;
        }
        return key;
}
void hashing(person* p, hash* hasht) {
        int i;
        for(i = 0; i < 10; i++) {
                insert_hash(p + i, hasht);
        }
}
hash* init_hash() {
        hash* hasht;
        hasht = (hash*)calloc(256, sizeof(hash));
        return hasht;
}
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
      //  newnode->next = NULL;
        head = newnode;
        return head;
}
void insert_hash(person* p, hash *hasht) {
        int hashIndex;
        hashIndex = getKey(p->name);
		//printf("hash index is %d\n", hashIndex);
        if(hasht[hashIndex].count == 0) {
                 person* newnode;
		 newnode =  (person*)malloc(sizeof(person));
        	*newnode = *p;
	        newnode->next = NULL;

	      //  newnode->next = NULL;
        	hasht->head = newnode;
        
                hasht[hashIndex].count = 1;
        }
        else {
                chain(p, hasht[hashIndex].head);
                hasht[hashIndex].count++;
        }
}
int main(int argc, char* argv[]) {
        person *p, *newnode;
        hash* hasht;
	  hasht = (hash*)calloc(256, sizeof(hash));

        int i, hashIndex;
        p = getData(argv[1]);
        for(i = 0; i < 10; i++) {
                printf("%s, ", p[i].name);
                printf("%s\n", p[i].number);
        }
//        hasht = (hash*)calloc(256, sizeof(hash));
//	printf("After init-hash\n");
        i = 0;
	while(i < 10 ) {
	 hashIndex = getKey((p + i)->name);
                //printf("hash index is %d\n", hashIndex);
        if(hasht[hashIndex].count == 0) {
                 
                 newnode =  (person*)malloc(sizeof(person));
                *newnode = *(p + i);
                newnode->next = NULL;

              //  newnode->next = NULL;
                (hasht + hashIndex)->head = newnode;

                hasht[hashIndex].count = 1;
        }
        else {
 //               chain((p + i), hasht[hashIndex].head);
		 
	 
        newnode =  (person*)malloc(sizeof(person));
        *newnode = *(p + i);
        

        newnode->next = (hasht + hashIndex)->head;
        (hasht + hashIndex)->head = newnode;
                hasht[hashIndex].count++;
        }
	i++;
}

//	printf("After hashing\n");
        i = 230;
	if(hasht[i].head->next == NULL) {
		printf("Success\n");
	}
 //     for(i = 0; i < 10; i++) 
        printf("%s, %s\n", hasht[i].head->name, hasht[i].head->number);
        return 0;
}


