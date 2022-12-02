#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node * header = NULL;
void display();
void enqueue();
void dequeue();
int main()
{
int choice;
char ch;
	while (1) {
        printf("1.Display\n2.Enqueue\n3.Dequeue ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			display();
			break;
		case 2:
			enqueue();
			break;
		case 3:
			dequeue();
			break;
		default:
			printf("Incorrect Choice\n");
		}
		printf("\nDo you want to continue y/n ");
		scanf(" %ch",&ch);
		if(ch == 'n'){
			break;
		}
    }
	return 0;
}
void display(){
    struct node*temp;
    if(header==NULL)
        printf("Empty");
    else{
        temp = header;
        while (temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->link;
        }
        
    }

}

void enqueue(){
    int data;
    struct node*temp,*ptr;
    temp = malloc(sizeof(struct node));
    printf("Enter the number");
    scanf("%d",&data);
    temp->link=NULL;
    temp->data= data;
    ptr = header;
	if(ptr==NULL){
    header = temp;    
    }
    else{
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
    }

}
void dequeue(){
	struct node* temp;
	if (header == NULL)
		printf("\nEmpty");
	else {
		temp = header;
		header = header->link;
	}
}
