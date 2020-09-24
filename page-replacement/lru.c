#include<stdio.h>

int is_there(int key,int arr[],int size){
	for(int i=0;i<size;i++){
		if(key==arr[i])
			return 1;
	}
	return 0;
}

int is_empty(int arr[],int size){			//atleast one position empty
	for(int i=0;i<size;i++){
		if(arr[i]==-1)
			return 1;
	}
	return 0;
}

void replace(int arr[],int size,int rep,int key){
	for(int i=0;i<size;i++){
		if(arr[i]==rep)
			arr[i]=key;				//replacing with key
	}
}

void snapshot(int arr[],int size){
	printf("page frame snapshot\n");
	for(int i=0;i<size;i++)
		printf("%d\n",arr[i]);
}
//return last occurence index of element < index of reference string
int IndexOf(int r[],int i,int ele){
	int index=-1;
	for(int j=0;j<i;j++){
		if(ele == r[j])
			index=j;
	}
	return index;
}
int least_recently_used(int r[],int frames[],int i,int size){
	int least=32764;
	for(int j=0;j<size;j++){
		int indx = IndexOf(r,i,frames[j]);
		if(indx<least)
			least=indx;
	}
	return least;		//index of least recently used
}


void main(){
	int n=0,count=0;
	int ref[]={3,4,1,2,5,3,2,1};
	printf("enter frame size");
	scanf("%d",&n);
	int frames[n];
	for(int i=0;i<n;i++)
		frames[i]=-1;
	int j=0,k=0;
	int least_index = 0;		//reference string first position
	for(int i=0;i<8;i++){
		if(is_empty(frames,n) && (!is_there(ref[i],frames,n))){		//if empty position
			frames[j%n]=ref[i];
			j++;
			count++;
		}
		else{
		if(!is_there(ref[i],frames,n)){
			count++;
			least_index = least_recently_used(ref,frames,i,n);
			replace(frames,n,ref[least_index],ref[i]);						
		}
		}
	//printf("current ref string:%d\n",ref[i]);
	//printf("least recently used:%d\n",ref[least_index]);
	//snapshot(frames,n);
	}
	printf("no of page frames:%d\n",count);
	
	snapshot(frames,n);
}
/*
7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1

enter frame size2
no of page frames:17
page frame snapshot
0
1

enter frame size3
no of page frames:12
page frame last snapshot
1
0
7

enter frame size4
no of page frames:8
page frame snapshot
7
0
1
2

enter frame size5
no of page frames:7
page frame snapshot
7
0
1
2
3

7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2

enter frame size2
no of page frames:11
page frame snapshot
2
3


enter frame size3
no of page frames:9
page frame snapshot
0
3
2


enter frame size4
no of page frames:6
page frame snapshot
3
0
4
2

enter frame size5
no of page frames:6
page frame snapshot
4
0
1
2
3

3,4,1,2,5,3,2,1

enter frame size2
no of page frames:8
page frame snapshot
2
1

enter frame size3
no of page frames:7
page frame snapshot
2
1
3

enter frame size4
no of page frames:6
page frame snapshot
5
3
1
2

enter frame size5
no of page frames:5
page frame snapshot
3
4
1
2
5

enter frame size6
no of page frames:5
page frame snapshot
3
4
1
2
5
-1 ===> only 5 distict values in reference string


*/
