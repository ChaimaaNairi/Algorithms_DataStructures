#include <stdio.h>
#include <stdlib.h>


// Dugum yapisini tanimlama
typedef struct Node {
    int data;
    struct Node* next;
} Node;


// Yeni düðüm oluþturma fonksiyonu
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}


// n elemanli dairesel bagli liste olusturma fonksiyonu
Node* create_circular_list(int n) {
    Node* head = create_node(1);
    Node* current = head;

int i;
    for ( i = 2; i <= n; i++) {
        current->next = create_node(i);
        current = current->next;
    }


    current->next = head;
    return head;
}


// Josephus problemi eleme fonksiyonu
Node* josephus_elimination(Node* head, int k) {
    Node* current = head;


    // Liste tek dugume indirgenece kadar dongu
    while (current->next != current) {
        // k-1 kiþi atlanýr
        int i;
        for ( i = 1; i < k - 1; i++) {
            current = current->next;
        }


        // k. kiþi elenir
        Node* eliminated_node = current->next;
        current->next = current->next->next;
        current = current->next;


        printf("Elenen: %d\n", eliminated_node->data);
        free(eliminated_node);
    }


    // Hayatta kalan dugum döndürülür
    return current;
}


int main() {
    int n, k;


    printf("Insan sayisini girin (n): ");
    scanf("%d", &n);


    printf("Adim boyutunu girin (k): ");
    scanf("%d", &k);


    Node* head = create_circular_list(n);
    Node* survivor = josephus_elimination(head, k);


    printf("Hayatta kalan: %d\n", survivor->data);


    free(survivor);
    return 0;
}