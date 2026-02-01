#include <stdio.h>

#define MAX 10

int stack[MAX], top = -1;

/* Function to add a parcel (Push operation) */
void push() {
    if (top >= MAX - 1) {
        printf("\nStack Overflow! Storage full.\n");
        return;
    }

    int id;
    printf("Enter Parcel ID: ");
    scanf("%d", &id);

    stack[++top] = id;
    printf("Parcel %d added successfully!\n", id);
}

/* Function to remove a parcel (Pop operation) */
void pop() {
    if (top < 0) {
        printf("\nStack Underflow! Storage empty.\n");
        return;
    }

    printf("Parcel %d removed successfully!\n", stack[top--]);
}

/* Function to display all parcels */
void display() {
    if (top < 0) {
        printf("\nStorage empty.\n");
        return;
    }

    printf("\nParcels in Storage (%d total):\n", top + 1);
    for (int i = top; i >= 0; i--) {
        if (i == top)
            printf("-> %d\n", stack[i]);
        else
            printf("   %d\n", stack[i]);
    }
}

/* Function to display stack status */
void status() {
    printf("\nCapacity : %d", MAX);
    printf("\nCurrent  : %d", top + 1);
    printf("\nAvailable: %d", MAX - top - 1);

    if (top >= MAX - 1)
        printf("\nStatus   : FULL\n");
    else if (top < 0)
        printf("\nStatus   : EMPTY\n");
    else
        printf("\nStatus   : AVAILABLE\n");
}

int main() {
    int choice;

    printf("=== PARCEL STORAGE SYSTEM ===\n");

    while (1) {
        printf("\n1. Add Parcel\n2. Remove Parcel\n3. Display Parcels\n4. Storage Status\n5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                status();
                break;
            case 5:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
