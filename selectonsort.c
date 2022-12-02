#include<stdio.h>
void insert(int a[],int n);
void display(int a[],int n);
void sort(int a[],int n);
int minpos(int a[],int c,int n);
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
	int j,temp;
	for(int i=0;i<n;i++){
		j = minpos(a,i,n);
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}
int minpos(int a[],int c,int n){
	int i,pos=c,min=a[c];
	for(i = c+1;i<n;i++){
		if(min>a[i]){
			min=a[i];
			pos = i;
		}
	}
	return pos;
}













