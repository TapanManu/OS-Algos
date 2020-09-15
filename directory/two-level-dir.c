# include<stdio.h>
# include<stdlib.h>
#include<string.h>

const int USER = 1;
const int MASTER = 0;
static int fcount=0;
static int j=0;

struct Directory { 
	char *file ;
};

struct Directory user[3];

void main(){
	int k;
	//master = ( struct Directory *)malloc(sizeof( struct Directory * ));
	//temp = ( struct Directory *)malloc(sizeof( struct Directory * ));
	//int fileCount[10];
	int count=3;
	int c=1;
	//master->tag=MASTER;
	int scount[3];
	char filename[10][10];
	char name[10];
	for(int i=0;i<count;i++){
		c=1;
		while(c==1){
			printf("user:%d,files:%d",i+1,fcount+1);
			scanf("%s",name);
			strcpy(filename[fcount++],name);	//error locate seg core error !!!
			printf("do you want to continue?(1/0)");
			scanf("%d",&c);
			if(c==0)
				scount[j++]=fcount-1;
		}
	}
	j=0;
	k=0;
	for(int i=0;i<count;i++) {	
		printf("user:%d\n",i+1);	
		for(;k<fcount;k++){
			user[i].file=filename[k];
			printf("%s\n",user[i].file);
			if(k==scount[j]){
				j++;
				k++;
				break;
			}
		}

	}

}
