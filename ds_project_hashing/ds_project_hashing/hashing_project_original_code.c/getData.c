#include"person.h"
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
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
	return p;
 }
