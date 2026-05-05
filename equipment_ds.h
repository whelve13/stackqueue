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
typedef struct
{
    char regNumber[20];
    char equipmentType[50];
    float pricePerUnit;
    char brand[50];
    char color[30];
    Date lastInspection;
    OwnerType oType;        
    OwnerInfo owner;        
} AgriEquipment;

typedef struct Node {
    AgriEquipment data;
    struct Node* next;
    struct Node* prev;
} Node;

// stack struct (LIFO)
typedef struct {
    Node* top;
} Stack;

// queue struct (FIFO)
typedef struct {
    Node* front;
    Node* rear;
} Queue;


// prototypes:

// utility
AgriEquipment createEquipmentRecord();
void printEquipmentRecord(AgriEquipment eq);
void clearInput();

// stack
void initStack(Stack* s);
void push(Stack* s, AgriEquipment data);
AgriEquipment pop(Stack* s);
void displayStack(Stack* s);

// simple queue
void initQueue(Queue* q);
void enqueue(Queue* q, AgriEquipment data);
AgriEquipment dequeue(Queue* q);
void displayQueue(Queue* q);

// deque
void insertFrontDeque(Queue* q, AgriEquipment data);
void insertRearDeque(Queue* q, AgriEquipment data);
AgriEquipment deleteFrontDeque(Queue* q);
AgriEquipment deleteRearDeque(Queue* q);

// circular queue
void enqueueCircular(Queue* q, AgriEquipment data);
AgriEquipment dequeueCircular(Queue* q);
void displayCircularQueue(Queue* q);

// priority queue
int compareEquipment(AgriEquipment newRecord, AgriEquipment existingRecord, int criterion, int ascending);
void enqueuePriority(Queue* q, AgriEquipment data, int criterion, int ascending);

// search
void universalSearch(Node* head);

// io
void saveQueueToFile(Queue* q);

#endif