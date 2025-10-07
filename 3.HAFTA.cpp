#include <stdio.h>
#include <stdlib.h>

// Node yapýsý
struct Node {
    int data;
    struct Node* next;
};

// Listeyi gezip yazdýrma
void traversal(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Baþýna ekleme
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Sonuna ekleme
void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Belirli pozisyona ekleme (1-indexed)
void insertAtPosition(struct Node** head, int pos, int newData) {
    if(pos == 1) {
        insertAtBeginning(head, newData);
        return;
    }

    struct Node* temp = *head;
    for(int i=1; i<pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Pozisyon geçersiz!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Eleman silme (verilen pozisyona göre)
void deleteAtPosition(struct Node** head, int pos) {
    if(*head == NULL) return;

    struct Node* temp = *head;

    if(pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for(int i=1; i<pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Pozisyon geçersiz!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    struct Node* head = NULL;

    // Liste oluþturma ve ekleme
    insertAtEnd(&head, 10); // Liste: 10
    insertAtEnd(&head, 20); // Liste: 10->20
    insertAtBeginning(&head, 5); // Liste: 5->10->20
    insertAtPosition(&head, 2, 7); // Liste: 5->7->10->20

    traversal(head); // Listeyi yazdýr

    // Silme iþlemi
    deleteAtPosition(&head, 3); // Liste: 5->7->20
    traversal(head);

    return 0;
}


