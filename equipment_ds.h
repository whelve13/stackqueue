#ifndef EQUIPMENT_DS_H
#define EQUIPMENT_DS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef enum
{
    LEGAL_ENTITY,
    PHYSICAL_PERSON
} OwnerType;

typedef union
{
    char companyCode[20];
    char personFullName[100];
} OwnerInfo;

// main data
typedef struct {
    char regNumber[20];
    char equipmentType[50];
    float pricePerUnit;
    char brand[50];
    char color[30];
    Date lastInspection;
    OwnerType oType;        
    OwnerInfo owner;        
} AgriEquipment;

// doubly-linked node
typedef struct Node {
    AgriEquipment data;
    struct Node* next;
    struct Node* prev;
} Node;

// stack structure (LIFO)
typedef struct {
    Node* top;
} Stack;

// queue structure (FIFO)
typedef struct {
    Node* front;
    Node* rear;
} Queue;


// utility
AgriEquipment createEquipmentRecord();
void printEquipmentRecord(AgriEquipment eq);

// stack operations
void initStack(Stack* s);
void push(Stack* s, AgriEquipment data);
AgriEquipment pop(Stack* s);

// queue operations
void initQueue(Queue* q);
void enqueue(Queue* q, AgriEquipment data);
AgriEquipment dequeue(Queue* q);

// ... We will add prototypes for Deque, Circular, Priority, and File I/O next ...

#endif