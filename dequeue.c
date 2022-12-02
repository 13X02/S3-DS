#include<stdio.h>
int dq[20],front=-1,rear=-1;
void insertfront(int dq[],int n);
void insertrear(int dq[],int n);
void deletefront(int dq[],int n);
void deleterear(int dq[],int n);
void display(int dq[],int n);
int main(){
	int c,n;
	char ch;
	printf("Enter the size of dequeue");
	scanf("%d",&n);
	while(1){
		printf("1. Insert at Front\n 2.Insert at Rear \n3. Delete at Front \n4.Delete at Rear \n5. Display");
		scanf("%d",&c);
		switch(c){
			case 1 : insertfront(dq,n);
				 break;
			case 2 : insertrear(dq,n);
				 break;
			case 3 : deletefront(dq,n);
				 break;
			case 4 : deleterear(dq,n);
				 break;
			case 5 : display(dq,n);
				 break;
			default: printf("error");
				 break;
			}
		printf("Continue y/n");
		scanf(" %c",&ch);
		if(ch=='n')
			break;
	}
	return 0;
}
void insertfront(int dq[],int n){
    if (front==0&&rear==n-1||front==rear+1)
    {
        printf("Overflow");
        return;
    }
    if (front==-1)
    {
        front=0;
        rear=0;
    }else if (front==0)
    {
    front = n-1;
    }else{
        front = front-1;
    }
    printf("Enter the element");
    scanf("%d",&dq[front]);
    
    
    
}
void deletefront(int dq[],int n){
	if(front== -1){
		printf("\nunderflow");
	}
	else{
		printf("\n%d removed ", dq[front]);
		if(front==rear){
		 	front=rear =-1;
		 }
		 else{
		 	front=front +1 %n;
		 }
	}	
}
void insertrear(int dq[],int n){
	if(front == ((rear +1) % n)){
		printf("\nOverflow");
	}
	else{
		 if(front==-1){
			front = rear =0;
			printf("\nenter the item");
			scanf("%d",&dq[rear]);
		}
		else{
			rear = (rear + 1) % n;
			printf("\nEnter the element");
			scanf("%d",&dq[rear]);
		}
	}	
	
}
void deleterear(int dq[],int n){
	if(front == -1){
		printf("Empty");
	}
	else{
        printf("\n%d removed",dq[rear]);
		if(front==rear){
			front = rear-1;
		}
		else if(rear == 0){
			front = n-1;
		}
		else{
			rear =rear -1;
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