# include<stdio.h>
# include<stdlib.h>
# include<string.h>

static int fileCount=10;
typedef struct {
	char* filename ;
}Directory;

Directory *root ; 

void main(){
	root = ( Directory* ) malloc(fileCount*sizeof(Directory));
	char files[20][25];
	char key[25];
	int fileCount=0;
	int c=1,flag=0;
	while(c==1){
		printf("enter each filenames");
		scanf("%s",files[fileCount++]);
		printf("do you want to continue?(1/0)");
		scanf("%d",&c);
	}
	
	for(int i=0;i<fileCount;i++) {
		root->filename = files[i];
		printf("%s\n",(root)->filename);	
	}

	printf("enter the file you want to delete:");
	scanf("%s",key);

	for(int i=0;i<fileCount;i++){
		if(!strcmp(key,files[i])){
			
			printf("the item is deleted :%s",files[i]);
			strcpy(files[i],"");
			flag=1;		//flag
			break;
		}
	}
	if(flag==0){
		printf("\nno file detected\n");
	}
	printf("\n");
	//display files
	for(int i=0;i<fileCount;i++) {
		if(strcmp(files[i],""))
		printf("%s\n",files[i]);	
	}

}
/*
enter each filenamesf1
do you want to continue?(1/0)1
enter each filenamesf2
do you want to continue?(1/0)1
enter each filenamesf3
do you want to continue?(1/0)1
enter each filenamesf4
do you want to continue?(1/0)0
f1
f2
f3
f4
enter the file you want to delete:f3
the item is deleted :f3
f1
f2
f4
*/
