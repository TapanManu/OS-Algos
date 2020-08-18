#include <stdio.h>
#include <stdlib.h>
# define max 25
int queue[max],front=-1,rear=-1;
static int total=0;
void enqueue(int ele)
{
	if(rear==max-1)
	{
		printf("overflow");
	}
	else
	{
		rear=rear+1;
		queue[rear]=ele;
	}
}
int dequeue()
{
	int x;
	if(front==rear)
	{
		printf("underflow");
		front=rear=-1;
	}
	else
	{
		front=front+1;
		x=queue[front];
		return x;
	}
}

void gangtt_chart(int at[],int process[],int size){
	//return the position of first process whose arrival time is zero
	int j=0,count=0;
	int min=0;  //minimum arrival time
	while(count<size){
		for(j=0;j<size;j++){
			if(at[j]==min){
				enqueue(process[j]);
				count++;
				if(count==size-1)
					break;
			}
		}
		min++;
	}
}
void process_queue(int queue[],int ct[],int bt[],int size){
	for(int i=0;i<size;i++){
		int j = queue[i];
		ct[j-1]=total+bt[j-1];
		total=ct[j-1];
	}
}

void main(){
	//FCFS is a non-preemptive algorithm     
	//considering 5 process in the beginning
	int n;
	printf("enter the number of processes");
	scanf("%d",&n);
	int process[n];  //process id
	int wt[n];		//waiting time
	int bt[n];		//burst time
	int at[n];		//arrival time
	int ct[n];		//completion time
	int tat[n];	
	int totaltat=0,totalwt=0;	//turn around time

	//getting the arrival and burst time for each process

	for(int i=0;i<5;i++){
		process[i]=i+1;
		printf("enter the arrival time for the process %d:",i+1);
		scanf("%d",&at[i]);
		printf("enter the burst time for the process %d:",i+1);
		scanf("%d",&bt[i]);
	}
	gangtt_chart(at,process,5);
	//displaying gangtt chart order
	for(int i=0;i<5;i++){
		printf("%d\t",queue[i]);
	}
	process_queue(queue,ct,bt,5);
	printf("\n");
	for(int i=0;i<5;i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		printf("waiting time : %d and turnaround time :%d of process %d\n",wt[i],tat[i],i+1);
		totaltat+=tat[i];
		totalwt+=wt[i];
	}
	//avg waiting and turnaround time
	printf("\n");
	printf("avg waiting time:%.2f",(float)totalwt/5);
	printf("\n");
	printf("avg turnaround time:%.2f",(float)totaltat/5);
}
