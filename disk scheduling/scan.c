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
			if(i==n-1){
				seek+=dist(request[i],head);
				head=disk_size-1;
				printf("%d\t",seek);
				seek+=dist(request[i],head);
				printf("%d\t",seek);
			}
			else{
				seek+=dist(request[i],head);
				head=request[i];
				printf("%d\t",seek);
			}
			//flag[i]=1;
		}
		head=disk_size-1;
		for(int i=index_min-1;i>=0;i--){
			if(i==0){
				//seek+=(disk_size-1);
				seek+=dist(request[i],head);
				printf("%d\t",seek);			//if disk size is 200,then seek is added with (199-0)
			}
			else{
				seek+=dist(request[i],head);
				printf("%d\t",seek);
				head=request[i];
			}
			//flag[i]=1;
		}
	}
	if(dir==BACKWARD){
		for(int i=index_max;i>=0;i--){
			if(i==0){
				seek+=dist(request[i],head);
				seek+=request[i];
				printf("%d\t",seek);
				head=0;
			}
			else{
				seek+=dist(request[i],head);
				head=request[i];
				printf("%d\t",seek);
			}
			//flag[i]=1;
		}
		head=0;
		for(int i=index_max+1;i<n;i++){
			if(i==0){
				seek+=dist(request[i],head);
				printf("%d\t",seek);
				head=request[i];
			}
			else{
				seek+=dist(request[i],head);
				head=request[i];
				printf("%d\t",seek);
			}
			//flag[i]=1;
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
enter the request 7:41
enter the request 8:114
11	34	41	60	79	92	114	176	
9	16	50	110	129	142	164	226	
total seek time in scan:226

enter no of request:7
current head position is at:50
previous head position is at:45
enter the request 1:82
enter the request 2:170
enter the request 3:43
enter the request 4:140
enter the request 5:24
enter the request 6:16
enter the request 7:190
16	24	43	82	140	170	190	
32	90	120	140	149	305	324	332	
total seek time in scan:332
*/
