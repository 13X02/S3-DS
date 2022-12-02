#include<stdio.h>
int rear = -1 ,front = -1;
int cq[30];
void enqueue(int cq[],int n);
void dequeue(int cq[],int n);
void display(int cq[],int n);
int main(){
	int choice,n;
	char ch;
	printf("enter the size of the queue");
	scanf("%d",&n);
	while(1){
		printf("\n1. Enqueue \n2. Dequeue \n3. Display ");
		scanf("%d",&choice);
		switch(choice){
			case 1 : enqueue(cq,n);
			         break;
			case 2 : dequeue(cq,n);
			         break;
			case 3 : display(cq,n);
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
void enqueue(int cq[],int n){
	if(front == ((rear +1) % n)){
		printf("\nOverflow");
	}
	else{
		 if(front==-1){
			front = rear =0;
			printf("\nenter the item");
			scanf("%d",&cq[rear]);
		}
		else{
			rear = (rear + 1) % n;
			printf("\nEnter the element");
			scanf("%d",&cq[rear]);
		}
	}	
	
}
void display(int cq[],int n){
	int f = front, r = rear;
	if (front == -1) {
		printf("No number in the queue");
		return;
	}
	printf("Queue Contents :\n");
	if (f <= r) {
		while (f <= r){
			printf("%d\n", cq[f]);
			f++;
		}
	}
	else {
		while (f <= n - 1) {
			printf("%d\n",cq[f]);
			f++;
		}
		f = 0;
		while (f <= r) {
			printf("%d\n",cq[f]);
			f++;
		}
	}
}
void dequeue(int cq[],int n){
	if(front== -1){
		printf("\nunderflow");
	}
	else{
		printf("\n%d removed ", cq[front]);
		if(front==rear){
		 	front=rear =-1;
		 }
		 else{
		 	front=front +1 %n;
		 }
	}	
}