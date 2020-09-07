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
void main(){
    int alloc[5][3] = { { 0, 1, 0 }, // P0    // Allocation Matrix 
                        { 2, 0, 0 }, // P1 
                        { 3, 0, 2 }, // P2 
                        { 2, 1, 1 }, // P3 
                        { 0, 0, 2 } }; // P4 
  
    int max[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix 
                      { 3, 2, 2 }, // P1 
                      { 9, 0, 2 }, // P2 
                      { 2, 2, 2 }, // P3 
                      { 4, 3, 3 } }; // P4 
  
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
    printf("order in which process are requested");
    for (int i = 0;i<n-1;i++) 
        printf(" P%d ->", order[i]); 
    printf(" P%d\n",order[n-1]); 
  
}
