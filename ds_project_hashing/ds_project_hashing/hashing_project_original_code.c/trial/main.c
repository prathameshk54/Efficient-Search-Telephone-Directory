#include<stdio.h>
#include<string.h>
void fun(char*);
void fun1(char*);
int main() {
	
	char str[10];
	gets(str);
	fun(str);
	printf("%s\n", str);
	return 0;
}
