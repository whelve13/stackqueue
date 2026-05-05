#include <stdio.h>
#include <stdlib.h>
#include "equipment_ds.h"

void displayMainMenu()
{
    printf("\n>========================================<\n");
    printf("   AGRICULTURAL EQUIPMENT REGISTRY HUB    \n");
    printf(">========================================<\n");
    printf("1. Stack Operations (LIFO)\n");
    printf("2. Simple Queue Operations (FIFO)\n");
    printf("3. Double-Ended Queue (Deque) Operations\n");
    printf("4. Circular Queue Operations\n");
    printf("5. Priority Queue Operations (by Price)\n");
    printf("6. File Output / Save Data\n");
    printf("0. Exit Program\n");
    printf("------------------------------------------\n");
    printf("Select Data Structure to interact with: ");
}

int main()
{
    // we initialize structs
    Stack myStack;
    initStack(&myStack);

    Queue simpleQ, dequeQ, circularQ, priorityQ;
    initQueue(&simpleQ);
    initQueue(&dequeQ);
    initQueue(&circularQ);
    initQueue(&priorityQ);

    int mainChoice, subChoice;
    AgriEquipment tempEq;

    while (1)
    {
        displayMainMenu();
        if (scanf("%d", &mainChoice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            clearInput(); // we flush bad input
            continue;
        }

        switch (mainChoice)
        {
            case 1: // STACK
                do
                {
                    printf("\n> STACK MENU\n");
                    printf("1. Push\n2. Pop\n3. Display\n4. Search\n0. Back to Main\nChoice: ");
                    scanf("%d", &subChoice);
                    if (subChoice == 1) push(&myStack, createEquipmentRecord());
                    else if (subChoice == 2) pop(&myStack);
                    else if (subChoice == 3) displayStack(&myStack);
                    else if (subChoice == 4) universalSearch(myStack.top);
                } while (subChoice != 0);
                break;

            case 2: // simple queue
                do
                {
                    printf("\n> SIMPLE QUEUE MENU\n");
                    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Search\n0. Back to Main\nChoice: ");
                    scanf("%d", &subChoice);
                    if (subChoice == 1) enqueue(&simpleQ, createEquipmentRecord());
                    else if (subChoice == 2) dequeue(&simpleQ);
                    else if (subChoice == 3) displayQueue(&simpleQ);
                    else if (subChoice == 4) universalSearch(simpleQ.front);
                } while (subChoice != 0);
                break;

            case 3: // deque
                do
                {
                    printf("\n> DEQUE MENU\n");
                    printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Search\n0. Back\nChoice: ");
                    scanf("%d", &subChoice);
                    if (subChoice == 1) insertFrontDeque(&dequeQ, createEquipmentRecord());
                    else if (subChoice == 2) insertRearDeque(&dequeQ, createEquipmentRecord());
                    else if (subChoice == 3) deleteFrontDeque(&dequeQ);
                    else if (subChoice == 4) deleteRearDeque(&dequeQ);
                    else if (subChoice == 5) displayQueue(&dequeQ);
                    else if (subChoice == 6) universalSearch(dequeQ.front);
                } while (subChoice != 0);
                break;

            case 4: // circular queue
                do
                {
                    printf("\n> CIRCULAR QUEUE MENU\n");
                    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Search\n0. Back\nChoice: ");
                    scanf("%d", &subChoice);
                    if (subChoice == 1) enqueueCircular(&circularQ, createEquipmentRecord());
                    else if (subChoice == 2) dequeueCircular(&circularQ);
                    else if (subChoice == 3) displayCircularQueue(&circularQ);
                    else if (subChoice == 4) universalSearch(circularQ.front);
                } while (subChoice != 0);
                break;

            case 5: // priority queue
                do
                {
                    printf("\n> PRIORITY QUEUE MENU\n");
                    printf("1. Enqueue (Sorted by Price)\n2. Dequeue (Highest Price)\n3. Display\n4. Search\n0. Back\nChoice: ");
                    scanf("%d", &subChoice);
                    if (subChoice == 1) enqueuePriority(&priorityQ, createEquipmentRecord());
                    else if (subChoice == 2) dequeue(&priorityQ); // Normal dequeue takes from front
                    else if (subChoice == 3) displayQueue(&priorityQ);
                    else if (subChoice == 4) universalSearch(priorityQ.front);
                } while (subChoice != 0);
                break;

            case 6: // file io
                printf("\n> SAVE DATA TO FILE\n");
                printf("Which structure do you want to save?\n");
                printf("1. Stack\n2. Simple Queue\n3. Deque\n4. Priority Queue\n(Note: Circular Queue requires specialized save logic due to loops)\nChoice: ");
                scanf("%d", &subChoice);
                
                Queue tempSaveWrapper; 
                if (subChoice == 1) tempSaveWrapper.front = myStack.top;
                else if (subChoice == 2) tempSaveWrapper.front = simpleQ.front;
                else if (subChoice == 3) tempSaveWrapper.front = dequeQ.front;
                else if (subChoice == 4) tempSaveWrapper.front = priorityQ.front;
                else
                {
                    printf("Invalid choice or structure not supported for direct save.\n");
                    break;
                }
                saveQueueToFile(&tempSaveWrapper);
                break;

            case 0: // exit
                printf("Exiting system!\n");
                exit(0);

            default:
                printf("Invalid selection.\n");
        }
    }
    return 0;
}