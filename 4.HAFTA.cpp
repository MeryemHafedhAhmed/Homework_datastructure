
#include <stdio.h>
#include <stdlib.h>


//Doubly Linked List – Listenin Sonuna Eleman Ekleme
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Listenin sonuna ekleme
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {  // Liste boþsa
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void traversal(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    traversal(head);
    return 0;
}





//Linked Listte Tüm Elemanlarý Recursive ile Silme
void freeListRecursive(struct Node* head) {
    if(head == NULL) return;
    freeListRecursive(head->next);
    free(head);
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Before deleting all elements:\n");
    traversal(head);

    freeListRecursive(head);
    head = NULL;  // Listeyi boþalt
    printf("All elements deleted.\n");
    return 0;
}





//Doubly Linked List – Araya Ekleme
void insertAtPosition(struct Node** head, int pos, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(pos == 1) { // Baþýna ekleme
        newNode->next = *head;
        newNode->prev = NULL;
        if(*head != NULL) (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for(int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Pozisyon geçersiz!\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}



//Circular Linked List ile Normal Linked List Arasýndaki Fark – Sýralama Algoritmasýyla Gözlemleme:

// Bubble Sort örneði - normal linked list
void bubbleSort(struct Node* head) {
    if(head == NULL) return;
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while(ptr1->next != lptr) {
            if(ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
    
}


// Circular linked list bubble sort
struct NodeC {
    int data;
    struct NodeC* next;
};

void bubbleSortCircular(struct NodeC* head) {
    if(head == NULL) return;
    int swapped;
    struct NodeC* ptr1;
    struct NodeC* lptr = head;
    do {
        swapped = 0;
        ptr1 = head;
        do {
            struct NodeC* nextNode = ptr1->next;
            if(nextNode != head && ptr1->data > nextNode->data) {
                int temp = ptr1->data;
                ptr1->data = nextNode->data;
                nextNode->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        } while(ptr1->next != head);
    } while(swapped);
}




