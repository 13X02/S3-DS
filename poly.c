#include<stdio.h>
struct poly{
int coeff;
int expo;
};

int main(){
	struct poly x1[10],x2[10],x3[10];
	int t1,t2,i=0,j=0,k=0,p;
	printf("Enter the no of terms in First Polynomial");
	scanf("%d",&t1);
	for(p=0;p<t1;p++){
		printf("\nEnter Coefficient");
		scanf("%d",&x1[p].coeff);
		printf("\nEnter Exponent");
		scanf("%d",&x1[p].expo);
	}
	printf("\nEnter the no of terms in Second Polynomial");
	scanf("%d",&t2);
	for(p=0;p<t2;p++){
		printf("\nEnter Coefficient");
		scanf("%d",&x2[p].coeff);
		printf("\nEnter Exponent");
		scanf("%d",&x2[p].expo);
	}
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
	printf("\n X1 = ");
	for(p=0;p<t1;p++){
		printf("%d x ^ %d ",x1[p].coeff,x1[p].expo);
		if(p==t1-1)
			continue;
		printf(" + ");
	}
	printf("\n X2 = ");
	for(p=0;p<t2;p++){
		printf("%d x ^ %d ",x2[p].coeff,x2[p].expo);
		if(p==t2-1)
			continue;
		printf(" + ");
	}
	printf("\n X3 = X1 + X2 \n X3 = ");
	for(p=0;p<k;p++){
		printf("%d x ^ %d ",x3[p].coeff,x3[p].expo);
		if(p==k-1)
			continue;
		printf(" + ");
	}printf("\n");
	return 0;
}
	
	
