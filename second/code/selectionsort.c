#include<stdio.h>
void insert(int a[],int n);
void sort(int a[],int n);
void display(int a[],int n);
int main()
{
    int n;
    printf("Enter the Number of elements");
    scanf("%d",&n);
    int a[n];
    insert(a,n);
    sort(a,n);
    display(a,n);
    return 0;
}
void insert(int a[],int n){
    printf("enter the elements");
    for(int i= 0 ; i<n;i++){
        scanf("%d",&a[i]);
    }
}
void display(int a[],int n){
    for(int i=0; i<n;i++){
        printf("%d\t",a[i]);
    }
}
void sort(int a[],int n){
int i,temp;
for(i=0;i<n;i++){
    int min = a[i];
    int pos =i;
   for (int j = i+1; j < n; j++)
    {
        if (min>a[j])
        {
            min = a[j];
            pos=j;
        }
        
    }
    temp = a[i];
    a[i] = a[pos];
    a[pos] = temp;
}
}
