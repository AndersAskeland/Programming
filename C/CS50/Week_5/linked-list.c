/**
 * C program to insert new node at the end of a Singly Linked List
 */

#include <stdio.h>
#include <stdlib.h>


/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
}*head;

// Prototypes
void createList(int n);
void insertNodeAtEnd(int data);
void displayList();


int main()
{
    int n, data;

    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    insertNodeAtEnd(n);

    printf("\nData in the list \n");
    displayList();

    /*
     * Insert data at the end of the singly linked list
     */
    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    insertNodeAtEnd(data);

    printf("\nData in the list \n");
    displayList();

    return 0;
}

/*
 * Create a new node and inserts at the end of the linked list.
 */
void insertNodeAtEnd(int n)
{
    struct node *newNode, *temp;

    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = n; // Link the data field with data
        head->next = NULL; // Link the address field to NULL
    }
    else
    {
        newNode = (struct node*)malloc(sizeof(struct node));

        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
        }
        newNode->data = n; // Link the data part
        newNode->next = NULL; 

        temp = head;

        // Traverse to the last node
        while(temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; // Link address part

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}


/*
 * Display entire list
 */
void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}