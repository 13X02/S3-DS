#include<stdio.h>
int binarysearch(int a[],int n,int key);
int main(){
	int n,key;
	printf("Enter the number of elements");
	scanf("%d",&n);
	int a[n];
	printf("Enter the number of elements in sorted order");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter element to search");
	scanf("%d",&key);
	int pos = binarysearch(a,n,key);
	if(pos==-1){
		printf("Not Found");
	}else{
		printf("Found at %d pos",pos);
	}
	return 0;
}
int binarysearch(int a[],int n,int key){
	int low=0,high=n-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(key>a[mid]){
			low=mid+1;
		}else if(key<a[mid]){
			high = mid-1;
		}else{
			return mid;
		}
	}
	return -1;
}