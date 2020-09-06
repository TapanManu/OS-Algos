#include<stdio.h>
#include<stdlib.h>

static int disk_size=200;
const int FORWARD = 1;
const int BACKWARD = -1;

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
int direction(int head,int prev){
	if(prev<=head){
		return 1;		//scan towards right
	}
	else
		return -1;		//scan towards left
}
void bubblesort(int arr[],int size){
	int temp;
	int flag=0;
	for(int i=0;i<size;i++){
		flag=0;
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				flag=1;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		if(flag==0)
			break;
	}
}



void main(){
	int seek=0,prev=0,head=0,min=99999;		//disk seeking
	int n,dir;
	printf("enter no of request:");
	scanf("%d",&n);
	int request[n];
	int flag[n];
	int index_min=-1;
	int index_max=-1;
	printf("current head position is at:");
	scanf("%d",&head);
	printf("previous head position is at:");
	scanf("%d",&prev);
	//prev is ignored from computation
	for(int i=0;i<n;i++){
		printf("enter the request %d:",i+1);
		scanf("%d",&request[i]);
		flag[i]=0; 				//completed process or not
	}
	dir = direction(head,prev);
	bubblesort(request,n);		//sorting requests in ascending order
	for(int i=0;i<n;i++){
		printf("%d\t",request[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		if(dir==FORWARD){
			if(request[i]>head){
				index_min=i;
				break;
			}
		}
		else{
			if(request[i]<head){
				index_max=i;
			}
		}
	}
	if(dir==FORWARD){
		for(int i=index_min;i<n;i++){
				seek+=dist(request[i],head);
				head=request[i];
				printf("%d\t",request[i]);
				printf("\nseek:%d\t",seek);
		}
		seek+=dist(head,disk_size-1);
		head=0;
		seek+=dist(head,disk_size-1);
		for(int i=0;i<index_min;i++){
				seek+=dist(request[i],head);
				head=request[i];
				//printf("%d\t",request[i]);
				//printf("\nseek:%d\t",seek);
		}
	}
	if(dir==BACKWARD){
		for(int i=index_max;i>=0;i--){
				seek+=dist(request[i],head);
				head=request[i];
				/*printf("%d\t",request[i]);
				printf("\nseek:%d\t",seek);*/
		}
		seek+=dist(head,0);
		//printf("xxxx%d\t",seek);
		head=0;
		seek+=dist(head,disk_size-1);
		//printf("%d\t",seek);
		head=disk_size-1;
		for(int i=n-1;i>index_max;i--){
				seek+=dist(request[i],head);
				head=request[i];
				/*printf("%d\t",request[i]);
				printf("\nseek:%d\t",seek);*/
		}
	}
	//printf("index max:%d",index_max);
	printf("\ntotal seek time in scan:%d",seek);
}
/*
enter no of request:8
current head position is at:50
previous head position is at:54
enter the request 1:176
enter the request 2:79
enter the request 3:34
enter the request 4:60
enter the request 5:92
enter the request 6:11
enter the request 7:14
enter the request 8:114
11	14	34	60	79	92	114	176	
34	
seek:16	14	
seek:36	11	
seek:39	xxxx50	249	176	
seek:272	114	
seek:334	92	
seek:356	79	
seek:369	60	
seek:388	
total seek time in scan:388

enter no of request:8
current head position is at:50
previous head position is at:46
enter the request 1:176
enter the request 2:79
enter the request 3:34
enter the request 4:60
enter the request 5:92
enter the request 6:11
enter the request 7:41
enter the request 8:114
11	34	41	60	79	92	114	176	
60	
seek:10	79	
seek:29	92	
seek:42	114	
seek:64	176	
seek:126	11	
seek:359	34	
seek:382	41	
seek:389	
total seek time in scan:389
*/
