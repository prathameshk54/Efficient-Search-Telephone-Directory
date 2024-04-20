//key is sum of the ascii characters in the name of the person
int getKey(char* name) {
	int i, key = 0;
	for(i = 0; name[i] != '\0'; i++) {
		key = key + name[i];
		key = key % 256;
	}
	return key;
}
