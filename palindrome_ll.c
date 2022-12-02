#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
	char data;
	struct Node *next;
	struct Node *prev;
};
struct Node *head =NULL;
void push(struct Node** head_ref, char new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	if ((*head_ref) != NULL)
	(*head_ref)->prev = new_node ;
	(*head_ref) = new_node;
}

int isPalindrome(struct Node *left)
{
	if (left == NULL)
	return 1;

	struct Node *right = left;
	while (right->next != NULL)
		right = right->next;

	while (left != right)
	{
		if (left->data != right->data)
			return 0;

		left = left->next;
		right = right->prev;
	}

	return 1;
}
int main()
{
    char s[50];
    printf("Enter a Word\n");
    scanf("%s",s);
    for (int i = 0; i < strlen(s); i++)
    {
        push(&head,s[i]);
    }
    

	if (isPalindrome(head))
		printf("It is Palindrome");
	else
		printf("Not Palindrome");

	return 0;
}
