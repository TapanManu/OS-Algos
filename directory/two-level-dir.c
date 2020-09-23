# include<stdio.h>
# include<stdlib.h>
#include<string.h>

const int USER = 1;
const int MASTER = 0;

struct Directory{ 
	int tag;
	struct Directory* user[3];
	char filename[3][25] ;
};

struct Directory *master;


void removefile(char *file,int count){
	int flag=0;
	for(int i=0;i<count;i++){
		for(int j=0;j<count;j++){
			if(!strcmp(master->user[i]->filename[j],file)){
				printf("deleted file:%s\t",master->user[i]->filename[j]);
				
				strcpy(master->user[i]->filename[j],"");
				flag=1;
			}
		}
	}
	if(flag==0)
		printf("no such file");

}

void main(){
	master = (struct Directory *)malloc(sizeof(struct Directory));
	
	int count=2;
	char file[25];
	master->tag=MASTER;
	int fileCount=0;
	int c=1;
	for(int i=0;i<count;i++){
		master->user[i] = (struct Directory *)malloc (sizeof(struct Directory));
		master->user[i]->tag=USER;
		for(int j=0;j<count;j++){
			printf("user:%d,files:%d",i+1,j+1);			
			scanf("%s",(master->user[i])->filename[j]);
			
		}
	}
	printf(" master \n");
	printf("\n");
	for(int i=0;i<count;i++){
		printf("user:%d\t",i);
	}
	printf("\n");
	for(int i=0;i<count;i++) {	
		printf("user:%d\n\n",i+1);
		for(int j=0;j<count;j++){
		printf("%s\t",master->user[i]->filename[j]);
		}
		printf("\n");
	}

	printf("enter the filename to remove");
	scanf("%s",file);
	removefile(file,count);

	printf("\n");
	for(int i=0;i<count;i++) {	
		printf("user:%d\n\n",i+1);
		for(int j=0;j<count;j++){
		printf("%s\t",master->user[i]->filename[j]);
		}
		printf("\n");
	}
	

}
/*
user:1,files:1t1
user:1,files:2t2
user:2,files:1t3 
user:2,files:2t4
 master 

user:0	user:1	
user:1

t1	t2	
user:2

t3	t4	
enter the filename to removet3
deleted file:t3	

user:1

t1	t2	
user:2

	t4	

*/


}
