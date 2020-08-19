#include <stdio.h>
# define max 25

static int total=0;
int queue[max];			//ready queue of processes
int front=-1,rear=-1;

void enqueue(int ele){
	if(rear==max-1)
		printf("overflow");
	else{
		rear=rear+1;
		queue[rear]=ele;
	}
}
int dequeue(){
	if(front==rear+1){
		front=rear=-1;
		printf("underflow");
	}
	else{
		front=front+1;
		return queue[front];
	}
	return -1;  //null condition
}
int is_arrived(int at){
	return at<=total;
}
int is_completed_all(int flag[],int size){ 			//check whether entire loop is completed
	for(int i=0;i<size;i++)
		if(flag[i]==0)
			return 0;
	return 1;
}
void main(){
	int n,x=-1;
	printf("enter the number of processes:");
	scanf("%d",&n);
	int at[n],wt[n],bt[n],bt_dummy[n],ct[n],tat[n],q[n],empty=0;
	int flag[n];//whether process is completed or not
	int tq,sumtat=0,sumwt=0;
	printf("enter the time quantum:");
	scanf("%d",&tq);
	for(int i=0;i<n;i++){
		printf("enter the arrival time of process %d:",i+1);
		scanf("%d",&at[i]);
		printf("enter the burst time of process %d:",i+1);
		scanf("%d",&bt[i]);
		bt_dummy[i]=bt[i];
		flag[i]=0;  //incomplete processes
		ct[i]=-1;	
		q[i]=0;	//not entered the queue
	}
while(1){
	for(int i=0;i<n;i++){
		if(is_arrived(at[i])){
			if(q[i]==0){
				printf("xxx\n");
				enqueue(i);   //add new process to the queue(first time pass for each process)
				q[i]=1;			//entered the queue atleast once

				}
			}  
			}
			if( x!=-1 && flag[x]==0 ){		//adding previous incomplete executable process 
				enqueue(x);
			}
				x = dequeue();	
				if(x==-1)
					empty=1;
				if(flag[x]==0){ 	//if process is not completed
				if(tq<bt[x]){		//if time quantum is less than burst time
					bt[x]-=tq;
					total+=tq;
					
				}
				else{						//if burst time less than time quantum
					ct[x]=bt[x]+total;
					total=ct[x];
					flag[x]=1;
					}  
				}
			//for(int i=front+1;i<=rear;i++)   //displaying the queue at each pass
			//	printf("%d\t",queue[i]);
			printf("\n");	
			if(is_completed_all(flag,n)||empty) //completed all steps
			break;			
		}	
	printf("order\n");
	for(int i=0;i<n;i++){
		printf("%d\t",ct[i]);
	}
	for(int i=0;i<n;i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt_dummy[i];    //since bt[i] has changed we use bt_dummy[i] here!
		sumwt+=wt[i];
		sumtat+=tat[i];
	}
	printf("average waiting time :%.2f",(float)sumwt/n);
	printf("average turn around time :%.2f",(float)sumtat/n);
}
