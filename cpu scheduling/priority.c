#include <stdio.h>

static int total=0;
static int count=0;

int is_arrived(int at,int total){
	return at<=total;
}
int get_priority(int process[],int index){
	return process[index];
}

void main(){
	//considering 3 processes initially
	int process[3],at[3],bt[3],ct[3],wt[3],tat[3];
	int min_priority=999;
	int priority_prev=0;
	int setIndex=-1;
	for(int i=0;i<3;i++){
		ct[i]=-1;				//not completed
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
	while(count<3){
		min_priority=999;
	for(int i=0;i<3;i++){
		if(is_arrived(at[i],total)){
			if(get_priority(process,i)<min_priority && get_priority(process,i)>priority_prev){
				min_priority=process[i]; //assigning minimum priority
				setIndex=i;  
			}
		}
	}
	ct[setIndex]=total+bt[setIndex];
	total=ct[setIndex];
	priority_prev=process[setIndex];
	count++;
	}
	for(int i=0;i<3;i++){
		if(ct[i]==-1){
			ct[i]=total+bt[i];
			total=ct[i];
		}
		printf("%d\t",ct[i]);
	}
}

