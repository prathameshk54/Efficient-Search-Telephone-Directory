#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
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
void searchInHash(char *, hash*);
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
        strcpy(newnode->name, p->name);
	strcpy(newnode->number, p->number);
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

        head = newnode;
        return head;
}
void insert_hash(person* p, hash *hasht) {
        int hashIndex;
	person* newnode; 
        hashIndex = getKey(p->name);

	//creating a new node
	newnode =  (person*)malloc(sizeof(person));
        strcpy(newnode->name, p->name);
	strcpy(newnode->number, p->number);
        newnode->next = NULL;

        if(hasht[hashIndex].count == 0) {
                  

        (hasht + hashIndex)->head = newnode;
                hasht[hashIndex].count = 1;
        }
        else {
             
        newnode->next = (hasht + hashIndex)->head;
        (hasht + hashIndex)->head = newnode;
                hasht[hashIndex].count++;
        }
	
}
void searchInHash(char* name, hash* hasht) {
        int hashIndex =getKey(name), flag = 0;
        person *myNode;
        myNode = hasht[hashIndex].head;
        if (!myNode) {
                printf("Search element unavailable in hash table\n");
                return;
        }
        while (myNode != NULL) {
                if (!strcmp(myNode->name, name)) {
                        printf("Name     : %s\n", myNode->name);
                        printf("Number      : %s\n", myNode->number);
                        flag = 1;
                        break;
                }
                myNode = myNode->next;
        }
        if (!flag)
                printf("Search element unavailable in hash table\n");
        return;
  }
void add(person* p, hash* hasht) {
	insert_hash(p, hasht);
}
int main(int argc, char* argv[]) {
        person *p;
	char ch;
	person new_per;
        hash* hasht;
        int i, n, j;
	char str[50], number[20];
        p = getData(argv[1]);
	hasht = (hash*)calloc(256, sizeof(hash));
	printf("Enter the number of contacts you want to add\n");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("Enter the details of the contact you want to add in the directory\n");
		printf("Name\n");
	//	scanf("%s", new_per.name);
		for(j = 0; ; j++) {
			ch = getchar();
			if(ch == '\n') {
				new_per.number[j] = '\0';
				break;
			}
			str[j] = ch;
		}

		printf("Number\n");
		for(j = 0; ; j++) {
			ch = getchar();
			if(ch == '\n') {
				new_per.number[j] = '\0';
				break;
			}
			str[j] = ch;
		}

		add(&new_per, hasht);
	}
      

        for(i = 0; i < 10000; i++) {
		insert_hash(p + i, hasht);
	}
	printf("Enter the name to be searched\n");
//	scanf("%s", str);
	gets(str);

	searchInHash(str, hasht);
	free(p);
	//free the malloced newnodes in the hashtable
	free(hasht);
        return 0;
}
