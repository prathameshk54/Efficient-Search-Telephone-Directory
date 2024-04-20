#include<string.h>

void fun1(char s[]) {
	int i;
	for(i = 0; s[i] != '\0'; i++) {
		s[i] = 'a';
	}
}
void fun(char d1[]) {
	fun1(d1);
}
