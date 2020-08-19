#include <stdio.h>

static int total=0;

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
	int n;
	printf("enter the number of processes:");
	scanf("%d",&n);
	int at[n],wt[n],bt[n],bt_dummy[n],ct[n],tat[n];
	int flag[n];
	int tq;
	printf("enter the time quantum:");
	scanf("%d",&tq);

	for(int i=0;i<n;i++){
		printf("enter the arrival time of process %d:",i+1);
		scanf("%d",&at[i]);
		printf("enter the burst time of process %d:",i+1);
		scanf("%d",&bt[i]);
		bt_dummy[i]=bt[i];
		flag[i]=0;
		ct[i]=-1;
	}

while(1){
	for(int i=0;i<n;i++){
		if(is_arrived(at[i])){
			if(flag[i]==0){ 	//if process is not completed
				if(tq<bt[i]){   //if time quantum less than burst time
					bt[i]-=tq;
					total+=tq;
				}
				else{						//if burst time less than time quantum
					ct[i]=bt[i]+total;
					total=ct[i];
					flag[i]=1;
					}

				}
			}
		}
		if(is_completed_all(flag,n))
			break;
	}
	printf("order\n");
	for(int i=0;i<n;i++){
		printf("%d\t",ct[i]);
	}



}
