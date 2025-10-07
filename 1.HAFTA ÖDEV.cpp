#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *n, int pos, int value) {
    if (*n >= MAX_SIZE) {
        printf("Array dolu, ekleme yap�lamaz!\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Ge�ersiz konum!\n");
        return;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;

    printf("Eleman eklendi!\n");
}

void deleteElement(int arr[], int *n, int pos) {
    if (*n <= 0) {
        printf("Array bo�, silme yap�lamaz!\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Ge�ersiz konum!\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;

    printf("Eleman silindi!\n");
}

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    printf("Array ters �evrildi!\n");
}

int main() {
    int arr[MAX_SIZE], n, choice, pos, value;

    printf("Dizideki eleman say�s�n� gir: ");
    scanf("%d", &n);

    printf("Elemanlar� gir:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n==== MENU ====\n");
        printf("1. Eleman Ekle\n");
        printf("2. Eleman Sil\n");
        printf("3. Diziyi Ters �evir\n");
        printf("4. Diziyi G�r�nt�le\n");
        printf("5. ��k��\n");
        printf("Se�iminizi yap�n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklenecek konumu gir (0-%d): ", n);
                scanf("%d", &pos);
                printf("Eklenecek de�eri gir: ");
                scanf("%d", &value);
                insertElement(arr, &n, pos, value);
                break;
            case 2:
                printf("Silinecek konumu gir (0-%d): ", n - 1);
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            case 3:
                reverseArray(arr, n);
                break;
            case 4:
                displayArray(arr, n);
                break;
            case 5:
                printf("Programdan ��k�l�yor...\n");
                return 0;
            default:
                printf("Ge�ersiz se�im!\n");
        }
    }
}

