#include <stdio.h>
#include <stdlib.h>

int available[3] = {3,3,2};

//int alloc[5][3];
int need[5][3];
int finish[5];

int max[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};

int alloc[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};

int is_safe(){
    for(int i=0;i<5;i++){
        if(finish[i]==-1){
            return 0;
        }
    }
    return 1;
}

int compare(int arr1[],int arr2[],int size){
    for(int i=0;i<size;i++){
        if(arr1[i]>arr2[i]){
            return 0;
        }
    }
    return 1;
}

void main(){
    int order[5];
    for(int i=0;i<5;i++){
        finish[i] = -1;
     /*   for(int j=0;j<3;j++){
            printf("enter %d process %d resource(max):",i,j);
            scanf("%d",&max[i][j]);
        }*/
    }
    /*for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            printf("enter %d process %d resource(allocated):",i,j);
            scanf("%d",&alloc[i][j]);
        }
    }
    for(int j=0;j<3;j++){
        printf("enter %d resource(available):",j);
            scanf("%d",&available[j]);
    }*/
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int k=0;
    int s=0;
    int count=0;
    while(!is_safe()){
        if(finish[k]==1){
            k = (k+1)%5;
            continue;
        }
        else if(finish[k]==-1){
        if(compare(need[k],available,3)){
            for(int i=0;i<3;i++){
                available[i] = available[i] + alloc[k][i];
            }
            finish[k] = 1;
            order[s++] = k;
            count = 0;
        }
        else if(count>=5){
            printf("deadlock");
            exit(1);
            //deadlock condition
        }
        else{
            count++;
        }
        k = (k+1)%5;
        }
    }
    for(int i=0;i<5;i++){
        printf("%d->",order[i]);
    }

}
