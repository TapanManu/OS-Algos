#include<stdio.h>

static int index=0;
static int n=3;// Number of processes 
static int m=2;// Number of resources

void incrorder(int order[],int ele){
	if(index<n){
		order[index++]=ele;
	}
}
int is_completed(){
	return index==n;
}
int is_satisfied(int flag[],int size){
	for(int i=0;i<size;i++)
		if(flag[i]==0)
			return 0;
	return 1;
}
int resource_request(int request[],int need[][m],int alloc[][m],int avail[],int index){
	int flag=0;
	for(int i=0;i<m;i++)
		if(request[i]>need[index][i])
			if(request[i]>avail[i]){
				flag=1;
				break;
			}
	if(flag==0){
		for(int i=0;i<m;i++){
			avail[i]-=request[i];
			alloc[index][i]+=request[i];
			need[index][i]-=request[i];
		}
	}
	if(flag==1){
		printf("resource not available to satisfy request\n");
	}
	return flag;
}
void main(){
	int alloc[n][m];
	int max[n][m];
	int req[m];		//request matrix
	printf("\nenter allocated and max resource for each process instances\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("\nenter allocated  resource %d for process %d:",j+1,i+1);
			scanf("%d",&alloc[i][j]);
			printf("\nenter max  resource %d for process %d:",j+1,i+1);
			scanf("%d",&max[i][j]);
			
		}
	}
    /* alloc =[ 1 , 2
    			2 , 4
    			3 , 6
    		 ]
       max =[4,5
       		 6,7
       		 9,11]
                      */
  
    int avail[3] = { 3, 3, 2 }; // Available Resources 
    int need[n][m],flag[n],order[n];
    int index=0;
    int request;
    for(int i=0;i<n;i++){
    	flag[i]=0;
    	order[i]=0;
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		need[i][j]=max[i][j]-alloc[i][j];
    	}
    }
    
    printf("enter which process requests resource\n");
    scanf("%d",&request);
    printf("request the resource\n");
    for(int i=0;i<m;i++){
    	printf("request at %d",i+1);
    	scanf("%d",&req[i]);
    	//printf("%d",req[i]);
    }

   if(!resource_request(req,need,alloc,avail,request-1)){
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(flag[j]==0){
    			int tempflag=0;
    			for(int k=0;k<m;k++){
    				if(need[j][k]>avail[k]){
    					tempflag=1;
    					break;
    				}
    			}
    			if(tempflag==0){
    				incrorder(order,j);
    				for(int k=0;k<m;k++)
    					avail[k]+=alloc[j][k];
    				flag[j]=1;
    			}
    		}
    		if(is_completed())
    			break;
    	}
    }
    if(is_satisfied(flag,n)){
    printf("order in which process are requested:");
    for (int i = 0;i<n-1;i++) 
        printf(" P%d ->", order[i]); 
    printf(" P%d\n",order[n-1]); 
  }
  else{
  	printf("\ndeadlock state");
  	printf("\nrequest cannot be allowed");
}
  }
else{
	printf("\nrequest cannot be allowed");
}
}
/*
enter allocated and max resource for each process instances

enter allocated  resource 1 for process 1:1

enter max  resource 1 for process 1:4

enter allocated  resource 2 for process 1:2

enter max  resource 2 for process 1:5

enter allocated  resource 1 for process 2:2

enter max  resource 1 for process 2:6

enter allocated  resource 2 for process 2:4

enter max  resource 2 for process 2:7

enter allocated  resource 1 for process 3:3

enter max  resource 1 for process 3:9

enter allocated  resource 2 for process 3:6

enter max  resource 2 for process 3:11
enter which process requests resource
1
request the resource
request at 11
request at 21
order in which process are requested: P0 -> P1 -> P2
*/
