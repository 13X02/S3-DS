#include<stdio.h>
int linearsearch(int a[],int n,int key);
int main(){
	int n,key;
	printf("Enter the number of elements");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter element to search");
	scanf("%d",&key);
	int pos = linearsearch(a,n,key);
	if(pos==-1){
		printf("Not Found");
	}else{
		printf("Found at %d pos",pos);
	}
	return 0;
}
int linearsearch(int a[],int n,int key){
	for(int i=0;i<n;i++){
		if(a[i]==key){
			return i;
		}
	}
	return -1;
}