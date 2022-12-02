#include <stdio.h>
int stack[100],top;
void push(int n);
void pop();
void display();
int main()
{
	int i,n,cmd,item;
	top=-1;
	char ch;
	printf("Enter the no of elements in stack");
	scanf("%d",&n);
	while(1)
	{
		printf("\n Choose the number corresponding to operation\n1,PUSH\n2,POP\n3,DISPLAY\n4,EXIT\n");
		scanf("%d",&cmd);
		switch(cmd){
			case 1 : push(n);	
				 break;
			case 2 : pop();
				 break;
			case 3 : display();
				 break;
			case 4 : printf("\nEXITING\n");
				 goto a;
				 break;
			default : printf("\n CHOOSE BETWEEN 1 AND 4\n");
				 break;
			}
			printf("\nDo you want to continue?(y/n)");
			scanf(" %c",&ch);
			if(ch == 'n')
				break;
	}a:
return 0;
}
void push(int n)
{
int item;
if(top==n-1)
	{
	 printf("\nStack Overflow !!!!\n");

	}
else
	{
	printf("Enter the element");
	scanf("%d",&item);
	top=top+1;
	stack[top]=item;
}
}
void pop(){
if(top==-1)
{
	printf("\nUnderflow !!!!\n");
}
else
{
	printf("Element POPPED Successfully");
	top=top-1;
}
}
void display(){
int i;
if(top == -1){
	printf("Stack is empty");
}else{
	for(i=top;i>=0;i--){
		printf("%d\n",stack[i]);
	}
}
}

