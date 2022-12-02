#include<stdio.h>
int t1,t2,t3;
struct poly{
int coeff;
int expo;
}x1[10],x2[10],x3[10];
void input(struct poly p[10],int t);
void print(struct poly p[10],int t);
void add();
int main(){
	printf("Enter the no of terms in First Polynomial");
	scanf("%d",&t1);
	input(x1,t1);
	printf("\nEnter the no of terms in Second Polynomial");
	scanf("%d",&t2);
	input(x2,t2);
	add();
	printf("\n X1 = ");
	print(x1,t1);
	printf("\n X2 = ");
	print(x2,t2);
	printf("\n X3 = X1 + X2 \n X3 = ");
	print(x3,t3);
	printf("\n");
	return 0;
}
void input(struct poly p[10],int t){
	int i;
	for(i=0;i<t;i++){
		printf("\nEnter Coefficient");
		scanf("%d",&p[i].coeff);
		printf("\nEnter Exponent");
		scanf("%d",&p[i].expo);
	}
}
void print(struct poly p[10],int t){
	int i;
	for(i=0;i<t;i++){
		printf("%d x ^ %d ",p[i].coeff,p[i].expo);
		if(i==t-1)
			continue;
		printf(" + ");
	}
}
void add()
{
        int i=0,j=0,k=0;
	while(i<t1 && j<t2){
		if(x1[i].expo==x2[j].expo){
			x3[k].coeff = x1[i].coeff+x2[j].coeff;
			x3[k].expo = x1[i].expo;
			i++;
			j++;
			k++;
		}else if (x1[i].expo > x2[j].expo){
			x3[k].coeff = x1[i].coeff;
			x3[k].expo = x1[i].expo;
			i++;
			k++;
		}else{
			x3[k].coeff = x2[j].coeff;
			x3[k].expo = x2[i].expo;
			j++;
			k++;
		}
	}
	while(i<t1){
		x3[k].coeff = x1[i].coeff;
		x3[k].expo = x1[i].expo;
		i++;
		k++;
	}
	while(j<t2){
		x3[k].coeff = x2[j].coeff;
		x3[k].expo = x3[j].expo;
		j++;
		k++;
	}
	t3=k;
}
	
