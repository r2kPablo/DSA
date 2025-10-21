#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Function to check if deque is full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Function to check if deque is empty
int isEmpty() {
    return (front == -1);
}

// Insert element at front
void insertFront(int item) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert at front.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {           //front = (front - 1 + MAX) % MAX; you can also use this
     if (front==0)
          front=MAX-1;
    else
        front=front-1;
       
    }
    deque[front] = item;
    printf("Inserted %d at front.\n", item);
}

// Insert element at rear
void insertRear(int item) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert at rear.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    deque[rear] = item;
    printf("Inserted %d at rear.\n", item);
}

// Delete element from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from front.\n");
        return;
    }
    printf("Deleted element from front: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1; // Only one element was present
    } else {
        front = (front + 1) % MAX;
    }
}

// Delete element from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from rear.\n");
        return;
    }
    printf("Deleted element from rear: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1; // Only one element was present
    } else {     // rear = (rear - 1 + MAX) % MAX; you can also use this
       if (rear==0)
          rear=MAX-1;
       else
           rear=rear-1;
    }
}

// Display deque elements
void display() {
    int i;
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, item;
    while (1) {
        printf("\n***** MENU *****\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to insert at front: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter the element to insert at rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
