#include"person.h"
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main(int argc, char* argv[]) {
	int fd, i = 0, j = 0, k = 0, flag = 0;
	char ch;
	person *p = (person*)malloc(sizeof(person)*10005);
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		perror("Failed to open the file\n");
		return errno;
	}
	while(read(fd, &ch, 1)) {
		if(ch == '\n') {
			flag = 0;
			i++;
			j = 0;
			k = 0;
			continue;
		}
		
		if(ch == ',') {
			flag = 1;
			continue;
		}
		if(flag == 0)
			p[i].name[j++] = ch;		
		else
			p[i].number[k++] = ch;
		
	}
//	printf("H\n");
	close(fd);
	for(i = 0; i < 10; i++) {
		printf("%s, ",p[i].name);
		printf("%s\n", p[i].number);
	}
	free(p);
	return 0;
 }
