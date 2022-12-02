#include <stdio.h>
int main()
{
	int stack[100],i,n,cmd,item,top=-1;
	char ch;
	printf("Enter the no of elements in stack");
	scanf("%d",&n);
	while(1)
	{
		printf("\n Choose the number corresponding to operation\n*******************************************************************	\n1,PUSH\n2,POP\n3,DISPLAY\n4,EXIT\n*******************************************************************");
		scanf("%d",&cmd);
		switch(cmd){
			case 1 : if(top==n-1)
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
				 break;
			case 2 : if(top==-1)
				 {
					printf("\nUnderflow !!!!\n");
				 }
				 else
				 {
					printf("Element POPPED Successfully");
					top=top-1;
				 }
				 break;
			case 3 : for(i=top;i>=0;i--)
				 {
					printf("%d\n",stack[i]);
				 }
				 break;
			case 4 : printf("\nEXITING.........................................\n");
				 goto a;
				 break;
			default : printf("\nERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! CHOOSE BETWEEN 1 AND 4\n");
				 break;
			}
			printf("\nDo you want to continue?(y/n)");
			scanf(" %c",&ch);
			if(ch == 'n')
				break;
	}a:
return 0;
}

