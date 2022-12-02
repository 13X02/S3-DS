#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int coef;
	int expo;
	struct Node* link;
};

void input(struct Node** poly)
{
	int coef, exp, c;
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	*poly = temp;
    printf("Enter no of terms");
    scanf("%d",&c);
	for (int i = 0; i < c; i++)
    {
		printf("\n Coeffecient: ");
		scanf("%d", &coef);
		printf("\n Exponent: ");
		scanf("%d", &exp);
		temp->coef = coef;
		temp->expo = exp;
		temp->link = (struct Node*)malloc(sizeof(struct Node));
		temp = temp->link;
		temp->link = NULL;
	}	
}

void display(struct Node* poly)
{
	while(poly != NULL)
	{
		printf("%dX^%d", poly->coef, poly->expo);
		poly = poly->link;
		if(poly != NULL)
			printf("+");
	}
}

void add(struct Node** result, struct Node* first, struct Node* second)
{
 	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 	temp->link = NULL;
 	*result = temp;
 	while(first!=NULL && second!=NULL)
 	{
 		if(first->expo > second->expo)
 		{
 			temp->coef = first->coef;
 			temp->expo = first->expo;
 			first = first->link;
 		}
 		else if(first->expo < second->expo)
 		{
 			temp->coef = second->coef;
 			temp->expo = second->expo;
 			second = second->link;
 		}
 		else
 		{
 			temp->coef = first->coef + second->coef;
 			temp->expo = first->expo;
 			first = first->link;
 			second = second->link;
 		}

 		if(first!=NULL && second!=NULL)
 		{
 			temp->link = (struct Node*)malloc(sizeof(struct Node));
 			temp = temp->link;
 			temp->link = NULL;
 		}
 	}
 	while(first!=NULL || second!=NULL)
 	{
 		temp->link = (struct Node*)malloc(sizeof(struct Node));
 		temp = temp->link;
 		temp->link = NULL;
 			
 		if(first)
 		{
 			temp->coef = first->coef;
 			temp->expo = first->expo;
 			first = first->link;
 		}

 		else if(second)
 		{
 			temp->coef = second->coef;
 			temp->expo = second->expo;
 			second = second->link;
 		}
 	}
}

int main()
{

	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* result = NULL;

	
	printf("\nEnter the First polynomial:\n");
	input(&first);
	printf("\nEnter the Second polynomial:\n");
	input(&second);
	add(&result, first, second);

    printf("\nThe resultant ");
	display(result);
	return 0;
}