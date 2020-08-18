
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
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 
void process_queue(int queue[],int ct[],int bt[],int at[],int size){
	for(int i=0;i<size;i++){
		int j = queue[i];
		if((i==0 && at[j-1]!=0)||(i!=0 && at[j-1]>total)){
			printf("\ninvalid input given!!\n");
			exit(0);
		}

		ct[j-1]=total+bt[j-1];
		total=ct[j-1];
	}
}
int search_queue(int value,int size){
	if(size==0)
		return size;
	for(int i=0;i<size;i++)
		if(value==queue[i] && queue[i]!=0)
			return 1;
	return 0;
}
void main(){
	//FCFS is a non-preemptive algorithm     
	//considering 5 process in the beginning
	int n,count=0;
	int k=0,prev;
	printf("enter the number of processes");
	scanf("%d",&n);
	int process[n];  //process id
	int wt[n];		//waiting time
	int bt[n];		//burst time
	int at[n],at_dummy[n];		//arrival time
	int ct[n];		//completion time
	int tat[n];	
	int totaltat=0,totalwt=0;	//turn around time

	//getting the arrival and burst time for each process

	for(int i=0;i<n;i++){
		process[i]=i+1;
		printf("enter the arrival time for the process %d:",i+1);
		scanf("%d",&at[i]);
		at_dummy[i]=at[i];
		printf("enter the burst time for the process %d:",i+1);
		scanf("%d",&bt[i]);
	}
	selectionSort(at_dummy,n);	
	k=0;
	
	//gangtt chart for FCFS
	while(k<n){
	for(int i=0;i<n;i++){
		if(at[i]==at_dummy[k]){
			//printf("%d\n",process[i]);
			if(!search_queue(process[i],n)){ //avoid same process to be enqueued again!!
				enqueue(process[i]);
				k++;						
			}
			else{
				printf("value is already there:%d\n",process[i]);				
				if(++count>max){
					k=n-1;  //getting out of loop
					break;
				}
			}
		}
	}
	
}
	//displaying gangtt chart order
	for(int i=0;i<n;i++){
		printf("%d\t",queue[i]);
	}
	
	process_queue(queue,ct,bt,at,n);
	printf("\n");
	for(int i=0;i<n;i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		printf("waiting time : %d and turnaround time :%d of process %d\n",wt[i],tat[i],i+1);
		totaltat+=tat[i];
		totalwt+=wt[i];
	}
	//avg waiting and turnaround time
	printf("\n");
	printf("avg waiting time:%.2f",(float)totalwt/n);
	printf("\n");
	printf("avg turnaround time:%.2f\n",(float)totaltat/n);

}
