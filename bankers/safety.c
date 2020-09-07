#include<stdio.h>

static int index=0;
static int n=5;// Number of processes 
static int m=3;// Number of resources

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
void main(){
	int alloc[n][m];
	int max[n][m];
	printf("\nenter allocated and max resource for each process instances\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("\nenter allocated  resource %d for process %d:",j+1,i+1);
			scanf("%d",&alloc[i][j]);
			printf("\nenter max  resource %d for process %d:",j+1,i+1);
			scanf("%d",&max[i][j]);
			
		}
	}
    /*int alloc[5][3] = { { 0, 1, 0 }, // P0    // Allocation Matrix 
                        { 2, 0, 0 }, // P1 
                        { 3, 0, 2 }, // P2 
                        { 2, 1, 1 }, // P3 
                        { 0, 0, 2 } }; // P4 
  
    int max[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix 
                      { 3, 2, 2 }, // P1 
                      { 9, 0, 2 }, // P2 
                      { 2, 2, 2 }, // P3 
                      { 4, 3, 3 } }; // P4 
                      */
  
    int avail[3] = { 3, 3, 2 }; // Available Resources 
    int need[n][m],flag[n],order[n];
    int index=0;
    for(int i=0;i<n;i++){
    	flag[i]=0;
    	order[i]=0;
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		need[i][j]=max[i][j]-alloc[i][j];
    	}
    }
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
  else
  	printf("insufficient resource to satisfy");
}
/*
enter allocated and max resource for each process instances

enter allocated  resource 1 for process 1:0

enter max  resource 1 for process 1:7

enter allocated  resource 2 for process 1:1

enter max  resource 2 for process 1:5

enter allocated  resource 3 for process 1:0

enter max  resource 3 for process 1:3

enter allocated  resource 1 for process 2:2

enter max  resource 1 for process 2:3

enter allocated  resource 2 for process 2:0

enter max  resource 2 for process 2:2

enter allocated  resource 3 for process 2:0

enter max  resource 3 for process 2:2

enter allocated  resource 1 for process 3:3

enter max  resource 1 for process 3:9

enter allocated  resource 2 for process 3:0

enter max  resource 2 for process 3:0

enter allocated  resource 3 for process 3:2

enter max  resource 3 for process 3:

enter allocated  resource 1 for process 4:2

enter max  resource 1 for process 4:2

enter allocated  resource 2 for process 4:1

enter max  resource 2 for process 4:2

enter allocated  resource 3 for process 4:1

enter max  resource 3 for process 4:2

enter allocated  resource 1 for process 5:0

enter max  resource 1 for process 5:4

enter allocated  resource 2 for process 5:0

enter max  resource 2 for process 5:3

enter allocated  resource 3 for process 5:2

enter max  resource 3 for process 5:3
order in which process are requested: P1 -> P3 -> P4 -> P0 -> P2
*/
