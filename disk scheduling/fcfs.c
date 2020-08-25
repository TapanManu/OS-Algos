#include<stdio.h>
#include<stdlib.h>



void main(){
	int seek=0,head=0;		//disk seeking
	int n;
	printf("enter no of request:");
	scanf("%d",&n);
	int request[n];
	printf("current head position is at:");
	scanf("%d",&head);
	for(int i=0;i<n;i++){
		printf("enter the request %d:",i+1);
		scanf("%d",&request[i]);
	}
	for(int i=0;i<n-1;i++){
		if(i==0){
			seek+=request[i]-head;
		}
		seek+=abs(request[i+1]-request[i]);
	}
	printf("\ntotal seek time in fcfs:%d",seek);
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

total seek time in fcfs:642
*/
