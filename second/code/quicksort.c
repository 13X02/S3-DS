#include<stdio.h>
int n;
void quicksort(int a[],int low,int high);
int partition(int a[],int low,int high);
void input(int a[],int n);
void display(int a[],int n);
int main(){
	int low=0;
	printf("Enter the number of elements");
	scanf("%d",&n);
	int a[n],high=n-1;
    printf("Enter the Numbers");
	input(a,n);
	quicksort(a,low,high);
	display(a,n);
	return 0;
}
void input(int a[],int n){
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
void display(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
void quicksort(int a[],int low,int high){
	int mid;
	if(low<high){
		mid=partition(a,low,high);
		quicksort(a,low,mid-1);
		quicksort(a,mid+1,high);
	}
}
int partition(int a[],int low,int high){
	int i,j,temp;
	i=low;
	j=high;
	int x=a[low];
	while(i<=j){
		while(a[i]<=x&&i<n){
			i++;
		}
		while(a[j]>x&&j>=0){
			j--;
		}
		if(i<j){
			temp = a[j];
			a[j]=a[i];
			a[i]=temp;
		}else{
			temp = a[low];
			a[low]=a[j];
			a[j]=temp;
		}
}return j;
}