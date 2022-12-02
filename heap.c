#include<stdio.h>
void heapify(int a[],int n,int i);
void heapsort(int a[],int n);
void print(int a[],int n);
int main(){
	int n;
	printf("How many elements:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Before Sorting\n");
	print(a,n);
	heapsort(a,n);
	printf("\nAfter Sorting\n");
	print(a,n);
	return 0;
}
void print(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
void heapsort(int a[],int n){
	int temp;
	int i=(n/2)-1;
	while(i>=0){
		heapify(a,n,i);
		i--;
	}
	for(i=n-1;i>=0;i--){
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a,i,0);
	}
}
void heapify(int a[],int n,int i){
	int temp;
	int largest = i ;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if(left<n&&a[left]>a[largest]){
		largest = left;
	}if(right<n&&a[right]>a[largest]){
		largest = right;
	}
	if(largest!=i){
		temp = a[i];
		a[i]= a[largest];
		a[largest]=temp;
		heapify(a,n,largest);
	}
}
		
