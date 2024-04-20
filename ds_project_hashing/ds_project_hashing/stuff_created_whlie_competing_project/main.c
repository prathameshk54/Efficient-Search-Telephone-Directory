#include<stdio.h>
#include"person.h"
#include<string.h>
int main(int argc, char* argv[]) {
	person *p;
	int i;
	p = getData(argv[1]);
	for(i = 0; i < 10; i++) {
		printf("%s, ", p[i].name);
		printf("%s\n", p[i].number);
	}
	return 0;
}
