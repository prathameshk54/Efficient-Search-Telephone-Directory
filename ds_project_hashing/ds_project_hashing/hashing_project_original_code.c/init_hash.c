#include<stdlib.h>
#include"person.h"
hash* init_hash() {
	hash* hasht;
	hasht = (hash*)calloc(256, sizeof(hash));
	return hasht;
}
