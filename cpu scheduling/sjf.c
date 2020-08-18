#include<stdio.h>

static int count=0;
static int j=0;
static int total=0;


void arrange_time(int at[],int bt[],int ct[],int wt[],int dummy[]){
	int min=999;
	int index_min=-1;
	if(j==count)
		return;
	//find minimum burst time for process with arrival time zero
	for(int i=0;i<3;i++){
		if(at[i]==0 && bt[i]<min && bt[i]!=0){
			min=bt[i];
			index_min=i+1;
		}
	}
	if(index_min==-1)
		return;
	printf("min_index:%d\n",index_min);
	//index_min corresponds to zero arrival time process with min burst time ,hence waiting time of that process is zero
	if(total==0)
		wt[index_min-1]=total;
	//process is non-preemptive
	ct[index_min-1]=total+bt[index_min-1]; //completion time is burst time
	for(int i=0;i<3;i++){
		if(dummy[i]==bt[index_min-1])
			dummy[i]=0;
	}
	//bt[index_min-1]=0;  //making the minimum burst time 0 hence waiting time and turnaround need to be calculated there
	   //putting zeros in matching cases
	total=ct[index_min-1];
	j++;
	arrange_time(at,bt,ct,wt,dummy); //recursive call
}
void bubblesort(int array[],int size){
	int temp;
	int flag=0;
	for(int i=0;i<size;i++){
		flag=0;
		for(int j=0;j<size-i-1;j++){
			if(array[j]>array[j+1]){
				flag=1;
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}

		}
		if(flag==0) break;  //no exchanges then exit
	}
}

void main(){
	int at[3];
	int bt[3];
	int ct[3];
	int wt[3];
	int tat[3];
	int bt_dummy[3];
	int sumtat=0,sumwt=0;

	for(int i=0;i<3;i++){
		
		printf("enter the arrival time :");
		scanf("%d",&at[i]);
		
		printf("enter the burst time : ");
		scanf("%d",&bt[i]);
		bt_dummy[i]=bt[i];
	}
	for(int i=0;i<3;i++){
		ct[i]=-1;
	}
	
	
	for(int i=0;i<3;i++){
		if(at[i]==0)
			count++;  //counting no of zero arrival times
	}
	bubblesort(bt_dummy,3);  //arranging copy of burst time in ascending order
	arrange_time(at,bt,ct,wt,bt_dummy);
	
	for(int i=0;i<3;i++){
		if(bt_dummy[i]!=0){
			printf("dummy:%d",bt_dummy[i]);
			for(int j=0;j<3;j++){
				if(at[j]<=total){
					printf("burst%d",bt[j]);
				if(bt[j]!=0 && (bt[j]==bt_dummy[i])){					
						ct[j]=total+bt[j];
						total=ct[j];
						bt_dummy[i]=0;
					}
				}
			}
			
		}
	}
	printf("total:%d\n",total);
	for(int i=0;i<3;i++){
		if(ct[i]==-1){
			ct[i]=total+bt[i];
			total=ct[i];
			//bt[i]=0;
		}
		printf("%d\t",ct[i]);
	}

	for(int i=0;i<3;i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		printf("\n waiting time : %d",wt[i]);
		printf("\nturnaround time : %d",tat[i]);
		sumtat+=tat[i];
		sumwt+=wt[i];
	}
	printf("\navg waiting time : %.2f",(float)sumwt/3);
	printf("\navg turnaround time : %.2f",(float)sumtat/3);


}
/*
enter the arrival time :8
enter the burst time : 1
enter the arrival time :4
enter the burst time : 9
enter the arrival time :0
enter the burst time : 7
min_index:3
dummy:1burst9burst0dummy:9burst9burst0total:16
17	16	7	
