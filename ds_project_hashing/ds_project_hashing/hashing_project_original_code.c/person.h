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
