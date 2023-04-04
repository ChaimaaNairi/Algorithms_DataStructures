#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int data;
int index;
struct Node* next;
struct Node* prev;
} Node;

Node* insert_sorted(Node* head, int data) {
Node* new_node = (Node*)malloc(sizeof(Node));
new_node->data = data;
new_node->next = NULL;
new_node->prev = NULL;
new_node->index = 0;
if (head == NULL) {
return new_node;
}
if (data < head->data) {
new_node->next = head;
head->prev = new_node;
head = new_node;
Node* current = head->next;
while (current != NULL) {
current->index++;
current = current->next;
}
return head;
}
Node* current = head;
while (current->next != NULL && current->next->data < data) {
current = current->next;
}
new_node->next = current->next;
if (current->next != NULL) {
current->next->prev = new_node;
Node* update_index = current->next;
while (update_index != NULL) {
update_index->index++;
update_index = update_index->next;
}
}
current->next = new_node;
new_node->prev = current;
new_node->index = current->index + 1;
return head;
}

Node* binary_search(Node* head, int target) {
Node* left = head;
Node* right = NULL;
while (left != right) {
Node* middle = left;
int half_distance = 0;
Node* temp = left;
while (temp != right) {
half_distance++;
temp = temp->next;
}
half_distance /= 2;
int i;
for ( i = 0; i < half_distance; i++) {
middle = middle->next;
}
if (middle->data == target) {
return middle;
} else if (middle->data < target) {
left = middle->next;
} else {
right = middle;
}
}
return NULL;
}

int main() {
Node* head = NULL;
int n;
printf("Gireceginiz sayi adedini girin: ");
scanf("%d", &n);
int i;
for ( i = 0; i < n; i++) {
int num;
printf("Sayi girin: ");
scanf("%d", &num);
head = insert_sorted(head, num);
}
int target;
printf("Aranacak sayiyi girin: ");
scanf("%d", &target);
Node* result = binary_search(head, target);
if (result) {
printf("Bulunan deger: %d, Indeks: %d\n", result->data, result->index);
} else {
printf("Deger bulunamadi.\n");
}
return 0;
}