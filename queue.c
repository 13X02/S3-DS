#include<stdio.h>
int rear = -1 ,front = -1;
int q[30];
void enqueue(int q[],int n);
void dequeue(int q[],int n);
void display(int q[],int n);
int main(){
	int choice,n;
	char ch;
	printf("enter the size of the queue");
	scanf("%d",&n);
	while(1){
		printf("\n1. Enqueue \n2. Dequeue \n3. Display ");
		scanf("%d",&choice);
		switch(choice){
			case 1 : enqueue(q,n);
			         break;
			case 2 : dequeue(q,n);
			         break;
			case 3 : display(q,n);
			         break;
		        default: printf("error");
		        	  break;
		     }
		printf("\nDo you want to continue y/n ");
		scanf(" %ch",&ch);
		if(ch == 'n'){
			break;
		}
		}
	return 0;
}
void enqueue(int q[],int n){
	if(rear>n){
		printf("\nOverflow");
	}
	else {
		if(front==-1&&rear ==-1){
			front = 0;
		}
		rear +=1;
		printf("\nEnter the element");
		scanf("%d",&q[rear]);
	}
}
void display(int q[],int n){
	if(front ==-1 ){
		printf("\nempty");
	}
	else {	
		for(int i=front;i<=rear;i++){
			printf("%d\t",q[i]);
		}
	}
}
void dequeue(int q[],int n){
	if(front== -1){
		printf("\nunderflow");
	}
	else{
		printf("\n%d removed ", q[front]);
		if(front==rear){
		 	front=rear =-1;
		 }
		 else{
		 	front++;
		 }
	}	
}
	

			

