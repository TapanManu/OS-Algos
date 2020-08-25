#include<stdio.h>
#include<stdlib.h>

int dist(int a,int b){
	return abs(a-b);
}
int is_completed(int arr[],int n){
	for(int i=0;i<n;i++){
		if(arr[i]!=1)
			return 0;
	}
	return 1;
}



void main(){
	int seek=0,head=0,min=99999;		//disk seeking
	int n;
	printf("enter no of request:");
	scanf("%d",&n);
	int request[n];
	int flag[n];
	int index_min=-1;
	printf("current head position is at:");
	scanf("%d",&head);
	for(int i=0;i<n;i++){
		printf("enter the request %d:",i+1);
		scanf("%d",&request[i]);
		flag[i]=0; 				//completed process or not
	}
	while(1){
		min=99999;
		index_min=-1;
	for(int i=0;i<n;i++){
		if(flag[i]==0){
			if(dist(head,request[i])< min){
				index_min=i;
				min=dist(head,request[i]);
				
			}
		}		
	}
	if(index_min!=-1 && flag[index_min]==0){
		flag[index_min]=1;
		seek+=min;
		head=request[index_min];  //new head
	}
	if(is_completed(flag,n)){
		break;
	}
	}
	printf("\ntotal seek time in sstf:%d",seek);
}
/*
enter no of request:7
current head position is at:50
enter the request 1:82
enter the request 2:170
enter the request 3:43
enter the request 4:140
enter the request 5:24
enter the request 6:16
enter the request 7:190

total seek time in sstf:208
*/
