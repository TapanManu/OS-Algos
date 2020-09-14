# include<stdio.h>
# include<stdlib.h>
#include<string.h>

const int USER = 1;
const int MASTER = 0;

struct Directory{ 
	int tag;
	struct Directory* user[3];
	char filename[3][10] ;
};

struct Directory *master;

void main(){
	master = (struct Directory *)malloc(sizeof(struct Directory));
	//int fileCount[10];
	int count=3;
	master->tag=MASTER;
	//master->filename=NULL;
	char name[10];
	int fileCount=0;
	for(int i=0;i<count;i++){
		for(int j=0;j<count;j++){
			printf("user:%d,files:%d",i+1,j+1);
			scanf("%s",name);
			strcpy(master->user[i]->filename[j],name);	//error locate seg core error !!!
		}
	}
	for(int i=0;i<count;i++) {	
		printf("user:%d",i+1);	
		master->user[i]->tag=USER;
		for(int j=0;j<count;j++){
			printf("%s\n",master->user[i]->filename[j]);
		}	
	}

}
