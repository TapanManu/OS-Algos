#include<stdio.h>

int is_there(int key,int arr[],int size){
	for(int i=0;i<size;i++){
		if(key==arr[i])
			return 1;
	}
	return 0;
}

int is_empty(int arr[],int size){
	for(int i=0;i<size;i++){
		if(arr[i]!=-1)
			return 0;
	}
	return 1;
}


void main(){
	int n=0,count=0;
	int ref[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	printf("enter frame size");
	scanf("%d",&n);
	int frames[n];
	for(int i=0;i<n;i++)
		frames[i]=-1;
	int j=0;
	for(int i=0;i<20;i++){
		if(is_empty(frames,n) || !is_there(ref[i],frames,n)){				//base condition
			frames[j%n]=ref[i];
			count++;
			j++;
		}		
	}
	printf("no of page frames:%d\n",count);
	printf("page frame last snapshot\n");
	for(int i=0;i<n;i++)
		printf("%d\n",frames[i]);
}
/*
enter frame size3
no of page frames:15
page frame last snapshot
7
0
1
*/
