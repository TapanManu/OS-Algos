#include <stdio.h>

static int total=0;
static int count=0;

//NON PREEMPTIVE PRIORITY SCHEDULING

int is_arrived(int at,int total){
	return at<=total;
}
int get_priority(int process[],int index){
	return process[index];
}

void main(){
	//considering 3 processes initially
	//if priority is same then follow fcfs
	int n;
	printf("get the no of processes");
	scanf("%d",&n);
	int process[n],at[n],bt[n],ct[n],wt[n],tat[n],flag[n];
	int min_priority=999;
	int priority_prev=0,sumtat=0,sumwt=0;   //storing priority of prev iteration if prev priority is minimum
	int setIndex=-1;
	int prevtime=-1;
	for(int i=0;i<n;i++){
		ct[i]=-1;
		flag[i]=0;				//not completed
		printf("enter the priority of the process %d:",i+1);
		scanf("%d",&process[i]);
		if(process[i]==0){
			printf("priority should be natural number\n");
			i--;
			continue;
		}
		printf("enter the arrival time of the process %d:",i+1);
		scanf("%d",&at[i]);
		printf("enter the burst time of the process %d:",i+1);
		scanf("%d",&bt[i]);
	}
	while(count<n){
		min_priority=999;
	for(int i=0;i<n;i++){
		if(is_arrived(at[i],total)){
			/*  debugging
			printf("arrived process:%d\n",i);
			printf("priority process %d :%d  comparing min_priority:%d\n",i,get_priority(process,i),min_priority);		
			printf("priority process %d :%d  comparing priority_prev:%d\n",i,get_priority(process,i),priority_prev);
			*/
			if(get_priority(process,i)<min_priority && get_priority(process,i)>priority_prev && flag[i]!=1){
				prevtime=at[i];
				//printf("%d process\n",i);
				min_priority=process[i]; //assigning minimum priority
				setIndex=i;  
				
			}
		}
	}
	if(flag[setIndex]==0){
	flag[setIndex]=1;   //that process is completed no execution again
	//printf("set index:%d\n",setIndex);
	ct[setIndex]=total+bt[setIndex];
	total=ct[setIndex];
	if(at[setIndex]!=0)
		priority_prev=process[setIndex];  //ignoring this check if arrival time is zero
	}
	count++;
	}
	printf("\ncompletion order\n");  //getting completion order
	for(int i=0;i<n;i++){
		if(ct[i]==-1){
			ct[i]=total+bt[i];
			total=ct[i];
		}
		printf("%d\t",ct[i]);
	}
	for(int i=0;i<n;i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		printf("\n waiting time : %d",wt[i]);
		printf("\nturnaround time : %d",tat[i]);
		sumtat+=tat[i];
		sumwt+=wt[i];
	}
	printf("\naverage waiting time %.2f s",(float)sumwt/n);
	printf("\naverage turnaround time %.2f s",(float)sumtat/n);
}

/*TEST CASES
1
enter the priority of the process 1:1
enter the arrival time of the process 1:0
enter the burst time of the process 1:5
enter the priority of the process 2:3
enter the arrival time of the process 2:2
enter the burst time of the process 2:2
enter the priority of the process 3:2
enter the arrival time of the process 3:4
enter the burst time of the process 3:1
//ans given 5 7 8  (completion order)

//ans correct 5 6 8

2
enter the priority of the process 1:1
enter the arrival time of the process 1:0
enter the burst time of the process 1:4
enter the priority of the process 2:1
enter the arrival time of the process 2:5
enter the burst time of the process 2:2
enter the priority of the process 3:1
enter the arrival time of the process 3:3
enter the burst time of the process 3:2
ans given 4 8 6
ans correct 4 8 6 

3
enter the priority of the process 1:1
enter the arrival time of the process 1:0
enter the burst time of the process 1:24
enter the priority of the process 2:1
enter the arrival time of the process 2:0
enter the burst time of the process 2:3
enter the priority of the process 3:1
enter the arrival time of the process 3:0
enter the burst time of the process 3:3
ans given 24 27 30
ans correct 24 27 30     //here no further check on shorter burst time only fcfs rule is followed as such 
//but here arrival also same hence proceeded in the order of execution

4
get the no of processes7
enter the priority of the process 1:2
enter the arrival time of the process 1:0
enter the burst time of the process 1:3
enter the priority of the process 2:6
enter the arrival time of the process 2:2
enter the burst time of the process 2:5
enter the priority of the process 3:3
enter the arrival time of the process 3:1
enter the burst time of the process 3:4
enter the priority of the process 4:5
enter the arrival time of the process 4:4
enter the burst time of the process 4:2
enter the priority of the process 5:7
enter the arrival time of the process 5:6
enter the burst time of the process 5:9
enter the priority of the process 6:4
enter the arrival time of the process 6:5
enter the burst time of the process 6:4
enter the priority of the process 7:10
enter the arrival time of the process 7:7
enter the burst time of the process 7:10

completion order
3	18	7	13	27	11	37	
 waiting time : 0
turnaround time : 3
 waiting time : 11
turnaround time : 16
 waiting time : 2
turnaround time : 6
 waiting time : 7
turnaround time : 9
 waiting time : 12
turnaround time : 21
 waiting time : 2
turnaround time : 6
 waiting time : 20
turnaround time : 30
average waiting time 7.71 s
average turnaround time 13.00 s
*/




