#include "linkedList.h"



//Inserting a node to linked list
//If head is null creates the head with the first node inserted
//else adds new nodes at the end

void insertNodeLast(node **headRef, int data)
{
	node *t;
	node *temp;
	node *head = *headRef;
	t = (node *)malloc(sizeof(node));
	//printf("Inserting data to list %d\n", data);
	if(head == NULL)
	{
		//printf("Inserting first node\n");
		head = t;
	}
	else
	{
		temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = t;
	}
	t->next = NULL;
	t->data = data;
	*headRef = head;
}

void insertNodeFirst(node **headRef, int data)
{
	node *t;
	node *head = *headRef;
	t = (node *)malloc(sizeof(node));
	if(head == NULL)
	{
		head = t;
	}
	else
	{
		t->next = head;
		head = t;
	}
	t->data = data;
	*headRef = head;
}

void insertAtIndex(node **headRef, int index, int data)
{
	node *temp;
	node *t;
	node *head = *headRef;
	int counter = 0;
	t = (node *)malloc(sizeof(node));
	printf("Inserting at position %d\n", index);
	if(index < 0)
		printf("Invalid index\n");
	else if(index == 0)
		insertNodeFirst(&head, data);
	else
	{
		temp = head;
		while(temp != NULL && counter != index-1)
		{
			printf("Iterating loop and counter is: %d and index is: %d\n", counter, index);	
			temp = temp->next;
			counter++;
		}
		printf("Exited loop with counter: %d\n", counter);
		if(index-1 > counter)
			printf("Invalid index\n");
		else
		{
			t->data = data;
			t->next = temp->next;
			temp->next = t;
		}
	}
	*headRef = head;
}


//Prints the content of the list one element at a time

void printList(node *head)
{
	node *temp;
	temp = head;
	printf("List contents: ");
	while(temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");

}

void createList(node **headRef, int array[], int n)
{
	int i;
	node *head = NULL;
	for(i = 0; i < n; i++)
	{
		insertNodeLast(&head, array[i]);
	}
	*headRef = head;
}


/*
//main method to test the functionality of the linked list
int main()
{
	node *head = NULL;
	int data;
	int choice, index;
	//Simple test to pass by reference of pointers in linked list
	//pointers should be returned when you create memory for the pointer in the remote function
	//
	//head = (node *)malloc(sizeof(node));
	//head->data = 0;
	//head->next = NULL;
	do
	{
		printf("Menu:\n");
		printf("1. Insert at the beginning\n2. Insert at the end\n3. Print the list contents\n4. Insert at index\n5. Exit Program\n");
		printf("What do you want to do? : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element you want to enter into the list: ");
		                scanf("%d", &data);
				insertNodeFirst(&head, data);
				break;
			case 2:
				printf("Enter the element you want to enter into the list: ");
                		scanf("%d",&data);
				insertNodeLast(&head, data);
				break;
			case 3:
				printList(head);
				break;
			case 4:
				printf("Enter the element you want to enter into the list: ");
		                scanf("%d", &data);
				printf("Enter the index: ");
				scanf("%d", &index);
				insertAtIndex(&head, index, data);
				break;
			case 5:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid option selected\n");
				break;
		}
	}while(choice!=5);
	return 0;
}
*/
