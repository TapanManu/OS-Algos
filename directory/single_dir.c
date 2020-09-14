# include<stdio.h>
# include<stdlib.h>

static int fileCount=10;
typedef struct {
	char* filename ;
}Directory;

Directory *root ; 

void main(){
	root = ( Directory* ) malloc(fileCount*sizeof(Directory));
	char files[20][25];
	int fileCount=0;
	int c=1;
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

}
