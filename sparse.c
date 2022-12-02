#include<stdio.h>

void tuple(int a[10][10],int t[10][3],int m,int n);
int input(int a[10][10],int m,int n);
void print(int t[10][3],int c);
void transpose(int t[][3],int tr[][3],int c);
void add(int b1[][3],int b2[][3],int b3[][3]);
int main(){
	int c1,c2,a[10][10],b[10][10],t1[20][3] , tr1[20][3],t2[20][3] , tr2[20][3],s[20][3];
	int i,j,m,n,p,q;
	printf("Enter the No of rows and cols of Matrix A");
	scanf("%d%d",&m,&n);
    printf("Enter the matrix");
    c1 = input(a,m,n);
	printf("Enter the No of rows and cols of Matrix B");
	scanf("%d%d",&p,&q);
    printf("Enter the matrix");
    c2 = input(b,p,q);
	if(c1 > m*n/2 && c2 >p*q/2){
		printf("\nNot a Sparse Matrix");
	}else{
		tuple(a,t1,m,n);
		printf("Tuple Representation of Matrix A\nRow\tCol\tVal\n");
		print(t1,c1);
		transpose(t1,tr1,c1);
		printf("Transpose of Matrix A\nRow\tCol\tVal\n");
		print(tr1,c1);
		tuple(b,t2,p,q);
		printf("Tuple Representation of Matrix B\nRow\tCol\tVal\n");
		print(t2,c2);
		transpose(t2,tr2,c2);
		printf("Transpose of Matrix B\nRow\tCol\tVal\n");
		print(tr2,c2);
		if (t1[0][0]!=t2[0][0]||t1[0][1]!=t2[0][1])
		{
			printf("Addition not possible");
		}else
		{
			add(t1,t2,s);
			printf("\nSum of Matrices\nRow\tCol\tVal\n");
			print(s,s[0][2]);
		}
					
		
	}
	return 0;
	}
int input(int a[10][10],int m,int n){
	int i,j,c=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0){
				c++;
			}
		}
	}
	return c;
}
void tuple(int a[10][10],int t[10][3],int m,int n){
	t[0][0]=m;
	t[0][1]=n;
	int k=1,i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]!=0){
				t[k][0]=i;
				t[k][1]=j;
				t[k][2]=a[i][j];
				k++;
			}
		}
	}
	t[0][2] =k-1;
}
void print(int t[10][3],int c){
int i;
	for(i=0;i<=c;i++){
		printf("%d\t%d\t%d\n",t[i][0],t[i][1],t[i][2]);
	}
}
void transpose(int t[][3],int tr[][3],int c){
	int i,j,l=1;	
	tr[0][0]=t[0][1];
	tr[0][1]=t[0][0];
	tr[0][2]=c;	
	for(i=0;i<t[0][1];i++){
		for(j=1;j<=c;j++){
			if(i==t[j][1]){
				tr[l][0]=i;
				tr[l][1]=t[j][0];
				tr[l][2]=t[j][2];
				l++;
			}
		}
	}
}
void add(int b1[][3],int b2[][3],int b3[][3]){

	int t1=b1[0][2];
	int t2 =b2[0][2];
	int i,j,k;
	i=j=k=1;
	b3[0][0]=b1[0][0];
	b3[0][1]=b1[0][1];
	while (i<=t1&&j<=t2)
	{
		if(b1[i][0]<b2[j][0]){
			b3[k][0]=b1[i][0];
			b3[k][1]=b1[i][1];
			b3[k][2]=b1[i][2];
			k++;
			i++;
		}
		else if(b1[i][0]>b2[j][0]){
			b3[k][0]=b2[j][0];
			b3[k][1]=b2[j][1];
			b3[k][2]=b2[j][2];
			k++;
			j++;
		}
		else if(b1[i][1]<b2[j][1]){
			b3[k][0]=b1[i][0];
			b3[k][1]=b1[i][1];
			b3[k][2]=b1[i][2];
			k++;
			i++;
		}
		else if(b1[i][1]>b2[j][1]){
			b3[k][0]=b2[j][0];
			b3[k][1]=b2[j][1];
			b3[k][2]=b2[j][2];
			k++;
			j++;
		}
		else{
			b3[k][0]=b1[i][0];
			b3[k][1]=b1[i][1];
			b3[k][2]=b1[i][2]+b2[j][2];
			k++;
			i++;
			j++;
		}

	}
	b3[0][2]=k-1;
	


	
}