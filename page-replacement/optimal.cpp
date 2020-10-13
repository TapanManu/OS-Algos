#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int m=5;			//maximum size of frame
int frames[m];			//frame
int mapf[m];				//mapfs the loc
int frindex=-1;

void snapshot(int size){
	for(int i=0;i<size;i++)
		cout<<frames[i]<<"\t";
}

int minIndex(int arr[],int size,int index,int ele,int start){
	bool flag = false;
	for(int i=start;i<size;i++){
		if(i!=index && ele == arr[i]){
			return i;
		}
	}
	if(!flag)
		return -1;

}

int least_used(int arr[],int size,int n,int start){
	int min_index=-2;
	for(int i=0;i<n;i++){
		int tmp = minIndex(arr,size,mapf[i],frames[i],start);
	//	cout<<"\n"<<tmp<<"\t\n";
		if(tmp==-1){
			frindex = i;
			return tmp;
		}
		if(min_index<tmp)
			min_index = tmp;
	}
	return min_index;
	//-1 returned if no element found
}

void replace(int rep,int ele,int n,int pos){
	for(int i=0;i<n;i++){
		if(frames[i]==ele){
			frames[i]=rep;			//replace the element with least reference in future
			mapf[i]=pos;				//update the position
		}
	}
}

int presence(int rep,int n){
	for(int i=0;i<n;i++){
		if(frames[i]==rep)
			return 0;
	}
	cout<<"h1\n";
	return 1;				//not found
}

int notAvail(int arr[],int size,int start){
	return minIndex(arr,size,mapf[0],frames[0],start)==-1 && 
		   minIndex(arr,size,mapf[1],frames[1],start)==-1 &&
		   minIndex(arr,size,mapf[2],frames[2],start)==-1;

}

int main(){
	int count=0;
	int arr[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	int n=0;
	int size=20;
	cout<<"no of frames\n";
	cin>>n;
	for(int i=0;i<n;i++){
		frames[i]=-1;
		mapf[i]=-1;
	}
	
	int j=0;				//frame pointer
	int k=0;				//reference string pointer
	while(k<size){
		int empty = presence(-1,n);				//check whether empty element exists
		int pres = presence(arr[k],n);
		if(!empty){			//either k<n or element not found later
			if(pres){
				frames[j%n]=arr[k];
				mapf[j%n]=k;
				j++;
				count++;
			}
		}
		else{
			//find the least used element in future
			int indx = least_used(arr,size,n,k);
			cout<<"index:"<<indx<<"\n";
			//replace
			if(indx!=-1){
				if(pres){
					replace(arr[k],arr[indx],n,k);
					count++;
				}
			}
			else if(notAvail(arr,size,k)){
				if(pres){
					frames[j%n]=arr[k];
					mapf[j%n]=k;
					j++;
					count++;
				}
			}
			else{
				if(pres){
					replace(arr[k],frames[frindex],n,k);
					count++;
				}
			}
		}
		snapshot(n);
		cout<<"\n";
		//}
		k++;
	}
	cout<<"no of frames:"<<count<<"\n";
	return 0;
}
/*
no of frames
3
h1
7	-1	-1	
h1
7	0	-1	
h1
7	0	1	
h1
h1
index:-1
2	0	1	
h1
index:-1
2	0	1	
h1
h1
index:-1
2	0	3	
h1
index:9
2	0	3	
h1
h1
index:10
2	4	3	
h1
index:-1
2	4	3	
h1
index:-1
2	4	3	
h1
h1
index:-1
2	0	3	
h1
index:-1
2	0	3	
h1
index:-1
2	0	3	
no of frames:7


no of frames
3
h1
7	-1	-1	
h1
7	0	-1	
h1
7	0	1	
h1
h1
index:17
2	0	1	
h1
index:13
2	0	1	
h1
h1
index:13
2	0	3	
h1
index:9
2	0	3	
h1
h1
index:10
2	4	3	
h1
index:-1
2	4	3	
h1
index:-1
2	4	3	
h1
h1
index:-1
2	0	3	
h1
index:15
2	0	3	
h1
index:-1
2	0	3	
h1
h1
index:-1
2	0	1	
h1
index:16
2	0	1	
h1
index:-1
2	0	1	
h1
index:-1
2	0	1	
h1
h1
index:-1
7	0	1	
h1
index:-1
7	0	1	
h1
index:-1
7	0	1	
no of frames:9
*/

