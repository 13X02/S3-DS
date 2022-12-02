#include<stdio.h>
void insert(int a[],int n);
void display(int a[],int n);
void sort(int a[],int n);
int main(){
	int n;
	printf("Enter the number of elements");
	scanf("%d",&n);
	int a[n];
	insert(a,n);
	printf("\nBefore sorting\n");
	display(a,n);
	sort(a,n);
	printf("\nAfter sorting\n");
	display(a,n);
	return 0;
}
void insert(int a[],int n){
	printf("Enter the elements");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
void display(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
void sort(int a[],int n){
	int j,key,i;
	for(i=0;i<n;i++){
		key =a[i];
		j=i-1;
		while(j>=0&&a[j]>key){
			a[j+1]=a[j];
			j= j-1;
		}	
		a[j+1]=key;
	}
}