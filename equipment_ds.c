#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipment_ds.h"

void clearInput()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

AgriEquipment createEquipmentRecord()
{
    AgriEquipment eq;
    int typeChoice;

    printf("\n> Enter Equipment Details\n");
    printf("Registration Number: ");
    scanf("%19s", eq.regNumber);
    
    printf("Equipment Type (e.g., tractor, plow): ");
    scanf("%49s", eq.equipmentType);
    
    printf("Price per unit: ");
    scanf("%f", &eq.pricePerUnit);
    
    printf("Brand: ");
    scanf("%49s", eq.brand);
    
    printf("Color: ");
    scanf("%29s", eq.color);
    
    printf("Last Inspection Date (DD MM YYYY): ");
    scanf("%d %d %d", &eq.lastInspection.day, &eq.lastInspection.month, &eq.lastInspection.year);
    
    printf("Owner Type (0 for Legal Entity, 1 for Physical Person): ");
    scanf("%d", &typeChoice);
    clearInput(); // clear newline in buffer
    
    if (typeChoice == 0)
    {
        eq.oType = LEGAL_ENTITY;
        printf("Enter Company Code: ");
        fgets(eq.owner.companyCode, sizeof(eq.owner.companyCode), stdin);
        *(eq.owner.companyCode + strcspn(eq.owner.companyCode, "\n")) = '\0'; 
    } else
    {
        eq.oType = PHYSICAL_PERSON;
        printf("Enter Full Name (First Last): ");
        fgets(eq.owner.personFullName, sizeof(eq.owner.personFullName), stdin);
        *(eq.owner.personFullName + strcspn(eq.owner.personFullName, "\n")) = '\0';
    }
    
    return eq;
}

void printEquipmentRecord(AgriEquipment eq)
{
    printf("\n[Reg: %s] %s %s (%s) - $%.2f\n", 
           eq.regNumber, eq.brand, eq.equipmentType, eq.color, eq.pricePerUnit);
    printf("Last Inspected: %02d/%02d/%04d\n", 
           eq.lastInspection.day, eq.lastInspection.month, eq.lastInspection.year);
           
    if (eq.oType == LEGAL_ENTITY)
    {
        printf("Owner - Legal Entity (Code: %s)\n", eq.owner.companyCode);
    } else
    {
        printf("Owner - Physical Person (Name: %s)\n", eq.owner.personFullName);
    }
    printf("--------------------------------------------------\n");
}

// stack implementation (LIFO)
void initStack(Stack* s)
{
    s->top = NULL;
}

void push(Stack* s, AgriEquipment data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newNode->data = data;
    newNode->prev = NULL; // unused in simple stack
    newNode->next = s->top; // point new node to the current top
    s->top = newNode; // update top to be the new node
    printf("Record pushed to Stack.\n");
}

AgriEquipment pop(Stack* s)
{
    AgriEquipment emptyRecord = {"", "", 0.0, "", "", {0,0,0}, LEGAL_ENTITY, {""}}; // dummy
    
    if (s->top == NULL)
    {
        printf("Stack Underflow! No elements to pop.\n");
        return emptyRecord;
    }
    
    Node* temp = s->top; // hold the node to be deleted
    AgriEquipment poppedData = temp->data; // extract the data
    s->top = s->top->next; // move top pointer down
    free(temp); // free the memory
    
    return poppedData;
}

void displayStack(Stack* s)
{
    if (s->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("\n> Stack Contents (Top to Bottom)\n");
    Node* current = s->top;
    while (current != NULL)
    {
        printEquipmentRecord(current->data);
        current = current->next;
    }
}

// simple queue implementation (FIFO)
void initQueue(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, AgriEquipment data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newNode->data = data;
    newNode->next = NULL; 
    newNode->prev = NULL; // unused in simple queue

    if (q->rear == NULL)
    {
        // if queue empty, both front and rear point to new node
        q->front = q->rear = newNode;
    } else
    {
        // we add new node at the end and change rear
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Record enqueued to Simple Queue.\n");
}

AgriEquipment dequeue(Queue* q)
{
    AgriEquipment emptyRecord = {"", "", 0.0, "", "", {0,0,0}, LEGAL_ENTITY, {""}}; // dummy
    
    if (q->front == NULL)
    {
        printf("Queue Underflow! No elements to dequeue.\n");
        return emptyRecord;
    }
    
    Node* temp = q->front; // store previous front
    AgriEquipment dequeuedData = temp->data; // extract data
    
    q->front = q->front->next; // move front one node ahead
    
    // if front NULL, then change rear to NULL as well
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp); // free memory
    return dequeuedData;
}

void displayQueue(Queue* q)
{
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("\n> Simple Queue Contents (Front to Rear)\n");
    Node* current = q->front;
    while (current != NULL)
    {
        printEquipmentRecord(current->data);
        current = current->next;
    }
}

// double-ended queue (Deque)
void insertRearDeque(Queue* q, AgriEquipment data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (q->rear == NULL)
    { // empty queue
        newNode->prev = NULL;
        q->front = q->rear = newNode;
    } else
    {
        newNode->prev = q->rear; // link back to old rear
        q->rear->next = newNode; // link old rear forward to new node
        q->rear = newNode; // update rear pointer
    }
    printf("Record inserted at the Rear of Deque.\n");
}

void insertFrontDeque(Queue* q, AgriEquipment data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->prev = NULL;

    if (q->front == NULL)
    { // empty queue
        newNode->next = NULL;
        q->front = q->rear = newNode;
    } else
    {
        newNode->next = q->front; // link forward to old front
        q->front->prev = newNode; // link old front back to new node
        q->front = newNode; // update front pointer
    }
    printf("Record inserted at the Front of Deque.\n");
}

AgriEquipment deleteFrontDeque(Queue* q)
{
    AgriEquipment emptyRecord = {"", "", 0.0, "", "", {0,0,0}, LEGAL_ENTITY, {""}};
    if (q->front == NULL)
    {
        printf("Deque Underflow! No elements at Front.\n");
        return emptyRecord;
    }

    Node* temp = q->front;
    AgriEquipment data = temp->data;

    q->front = q->front->next; // move front pointer forward
    
    if (q->front == NULL)
    {
        q->rear = NULL; // queue is now empty
    } else
    {
        q->front->prev = NULL; // sever the backward link
    }
    
    free(temp);
    return data;
}

AgriEquipment deleteRearDeque(Queue* q)
{
    AgriEquipment emptyRecord = {"", "", 0.0, "", "", {0,0,0}, LEGAL_ENTITY, {""}};
    if (q->rear == NULL)
    {
        printf("Deque Underflow! No elements at Rear.\n");
        return emptyRecord;
    }

    Node* temp = q->rear;
    AgriEquipment data = temp->data;

    q->rear = q->rear->prev; // move rear pointer backward
    
    if (q->rear == NULL)
    {
        q->front = NULL; // queue is now empty
    } else
    {
        q->rear->next = NULL; // sever the forward link
    }
    
    free(temp);
    return data;
}

// circular queue
void enqueueCircular(Queue* q, AgriEquipment data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->prev = NULL;

    if (q->front == NULL)
    { // first node points to itself to form the circle
        q->front = newNode;
        q->rear = newNode;
        newNode->next = q->front;
    } else
    { // we add to rear, link to front, update rear pointer
        q->rear->next = newNode;
        newNode->next = q->front; 
        q->rear = newNode;
    }
    printf("Record enqueued to Circular Queue.\n");
}

AgriEquipment dequeueCircular(Queue* q)
{
    AgriEquipment emptyRecord = {"", "", 0.0, "", "", {0,0,0}, LEGAL_ENTITY, {""}};
    if (q->front == NULL)
    {
        printf("Circular Queue Underflow!\n");
        return emptyRecord;
    }

    AgriEquipment data;
    
    // single node case
    if (q->front == q->rear)
    { 
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else
    { // multiple nodes
        Node* temp = q->front;
        data = temp->data;
        q->front = q->front->next; // move front forward
        q->rear->next = q->front; // maintain circular link from rear
        free(temp);
    }
    return data;
}

void displayCircularQueue(Queue* q)
{
    if (q->front == NULL)
    {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("\n> Circular Queue Contents\n");
    Node* current = q->front;
    do
    {
        printEquipmentRecord(current->data);
        current = current->next;
    } while (current != q->front); // stop when we loop back to start
}

// priority queue
void enqueuePriority(Queue* q, AgriEquipment data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    // case 1 - queue is empty
    if (q->front == NULL)
    {
        q->front = q->rear = newNode;
        printf("Record added as first Priority Queue element.\n");
        return;
    }

    // case 2 - new node has > priority
    if (data.pricePerUnit > q->front->data.pricePerUnit)
    {
        newNode->next = q->front;
        q->front->prev = newNode;
        q->front = newNode;
        printf("Record inserted at the front of Priority Queue.\n");
        return;
    }

    // case 3 - we traverse to find correct sorted pos
    Node* current = q->front;
    while (current->next != NULL && current->next->data.pricePerUnit >= data.pricePerUnit)
    {
        current = current->next;
    }

    // we insert after current node
    newNode->next = current->next;
    
    if (current->next != NULL)
    {
        current->next->prev = newNode; // link next node back to newNode
    } else
    {
        q->rear = newNode; // if inserted at very end, we update rear pointer
    }
    
    current->next = newNode;
    newNode->prev = current;
    printf("Record inserted into Priority Queue based on price.\n");
}