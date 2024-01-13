#include <stdio.h>
#include <stdlib.h>

// Created Node structure for a doubly linked list
struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the doubly linked list
void displayList(struct Node *head) 
{
    struct Node *current = head;
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to add a node to the head of the doubly linked list
struct Node *addToHead(struct Node *head, int data) 
    {
    struct Node *newNode = createNode(data);
    if (head == NULL) 
    {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to add a node to the tail of the doubly linked list
struct Node *addToTail(struct Node *head, int data) 
    {
    struct Node *newNode = createNode(data);
    if (head == NULL) 
    {
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL) 
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to add a node in the middle of the doubly linked list
struct Node *addToMiddle(struct Node *head, int data, int position) 
    {
    struct Node *newNode = createNode(data);
    if (head == NULL) 
    {
        return newNode;
    }

    struct Node *current = head;
    int count = 1;

    while (count < position - 1 && current->next != NULL) 
    {
        current = current->next;
        count++;
    }

    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL) 
    {
        current->next->prev = newNode;
    }
    current->next = newNode;

    return head;
}

// Function to delete a node from the doubly linked list
struct Node *deleteNode(struct Node *head, int data) 
    {
    if (head == NULL) 
    {
        return NULL;
    }

    struct Node *current = head;
    while (current != NULL && current->data != data) 
    {
        current = current->next;
    }

    if (current == NULL) 
    {
        printf("Node with data %d not found in the list.\n", data);
        return head;
    }

    if (current->prev != NULL) 
    {
        current->prev->next = current->next;
    } 
    else 
    {
        head = current->next;
    }

    if (current->next != NULL) 
    {
        current->next->prev = current->prev;
    }

    free(current);
    return head;
}

// Function to free the memory allocated for the doubly linked list
void exitList(struct Node *head) 
    {
    struct Node *current = head;
    struct Node *nextNode;

    while (current != NULL) 
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() 
{
    struct Node *head = NULL;
    int choice, data, position;

    do {
        printf("\n--------------ADDITION, DELETION AND INSERTION IN DOUBLY LINKED LIST------------\n");
        printf("\nSelect an Option:\n");
        printf("1. Add element to Head\n");
        printf("2. Add element to Tail\n");
        printf("3. Add element to Middle\n");
        printf("4. Delete Node\n");
        printf("5. Display \n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data to add to head: ");
                scanf("%d", &data);
                head = addToHead(head, data);
                break;
            case 2:
                printf("Enter data to add to tail: ");
                scanf("%d", &data);
                head = addToTail(head, data);
                break;
            case 3:
                printf("Enter data to add to middle: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = addToMiddle(head, data, position);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 5:
                printf("Current Linked List: ");
                displayList(head);
                break;
            case 6:
                exitList(head);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}