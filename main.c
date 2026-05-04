#include <stdio.h>
#include <stdlib.h>
#include "equipment_ds.h"

void displayMenu() {
    printf("\n> Agricultural Equipment Registry\n");
    printf("1. Stack Operations\n");
    printf("2. Simple Queue Operations\n");
    printf("3. Double-Ended Queue (Deque) Operations\n");
    printf("4. Circular Queue Operations\n");
    printf("5. Priority Queue Operations\n");
    printf("6. File Output / Save Data\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    Stack myStack;
    initStack(&myStack); // will write soon

    // need to initialize queues herel..

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("\n-- Stack Menu --\n");
                // implement Push/Pop sub-menu here
                break;
            case 2:
                printf("\n-- Simple Queue Menu --\n");
                // implement Enqueue/Dequeue sub-menu here
                break;
            // add other cases
            case 0:
                printf("Exiting program. Sayonara!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}