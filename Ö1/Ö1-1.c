#include <stdio.h>
#include <stdlib.h>

// çift yönlü düğüm yapısı 
struct node {
int data;
struct node *prev;
struct node *next;
};

// bağlı liste başlangıç düğümü
struct node *head = NULL;

// düğüm oluşturma fonksiyonu
struct node *createNode(int data) {
struct node *new_node = (struct node*)malloc(sizeof(struct node));
new_node->data = data;
new_node->prev = NULL;
new_node->next = NULL;
return new_node;
}

// listenin başına düğüm ekleme fonksiyonu
void insertAtBeginning(int data) {
struct node *new_node = createNode(data);
if(head == NULL) {
head = new_node;
} else {
head->prev = new_node;
new_node->next = head;
head = new_node;
}
}

// listenin sonuna düğüm ekleme fonksiyonu
void insertAtEnd(int data) {
struct node *new_node = createNode(data);
struct node *current_node = head;
if(head == NULL) {
head = new_node;
} else {
while(current_node->next != NULL) {
current_node = current_node->next;
}
current_node->next = new_node;
new_node->prev = current_node;
}
}

// listenin istenilen konumuna düğüm ekleme fonksiyonu
void insertAtPosition(int data, int position) {
struct node *new_node = createNode(data);
struct node *current_node = head;
int i;
for(i=1; i<position-1; i++) {
if(current_node->next == NULL) {
printf("Bu pozisyon mevcut değil.\n");
return;
}
current_node = current_node->next;
}
if(position == 1) {
head->prev = new_node;
new_node->next = head;
head = new_node;
} else {
new_node->prev = current_node;
new_node->next = current_node->next;
if(current_node->next != NULL) {
current_node->next->prev = new_node;
}
current_node->next = new_node;
}
}

// listenin başından düğüm silme fonksiyonu
void deleteFromBeginning() {
struct node *temp = head;
if(head == NULL) {
printf("Liste boş.\n");
} else {
head = head->next;
if(head != NULL) {
head->prev = NULL;
}
free(temp);
}
}

// listenin sonundan düğüm silme fonksiyonu
void deleteFromEnd() {
struct node *current_node = head;
if(head == NULL) {
printf("Liste boş.\n");
} else if(head->next == NULL) {
head = NULL;
free(current_node);
} else {
while(current_node->next != NULL) {
current_node = current_node->next;
}
current_node->prev->next = NULL;
free(current_node);
}
}

// listenin istenilen konumundan düğüm silme fonksiyonu
void deleteFromPosition(int position) {
struct node *current_node = head;
int i;
for(i=1; i<position; i++) {
if(current_node == NULL) {
printf("Bu pozisyon mevcut değil.\n");
return;
}
current_node = current_node->next;
}
if(current_node == head) {
head = current_node->next;
if(head != NULL) {
head->prev = NULL;
}
free(current_node);
} else if(current_node->next == NULL) {
current_node->prev->next = NULL;
free(current_node);
} else {
current_node->prev->next = current_node->next;
current_node->next->prev = current_node->prev;
free(current_node);
}
}

// listenin elemanlarını ekrana yazdırma fonksiyonu
void printList() {
struct node *current_node = head;
if(head == NULL) {
printf("Liste boş.\n");
} else {
printf("Liste elemanları: ");
while(current_node != NULL) {
printf("%d ", current_node->data);
current_node = current_node->next;
}
printf("\n");
}
}

int main() {
int n, data, position, i, choice;
while (1) {
printf("\n1. Listenin başına eleman ekleme\n");
printf("2. Listenin sonuna eleman ekleme\n");
printf("3. Listenin istenilen konumuna eleman ekleme\n");
printf("4. Listenin başından eleman silme\n");
printf("5. Listenin sonundan eleman silme\n");
printf("6. Listenin istenilen konumundan eleman silme\n");
printf("7. Çıkış\n");
printf("Seçiminizi yapın: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Kaç eleman eklenecek? ");
scanf("%d", &n);
printf("Başa eklenecek elemanları girin:\n");
int i;
for ( i = 0; i < n; i++) {
scanf("%d", &data);
insertAtBeginning(data);
}
printList();
break;
case 2:
printf("Kaç eleman eklenecek? ");
scanf("%d", &n);
printf("Sona eklenecek elemanları girin:\n");
for (i = 0; i < n; i++) {
scanf("%d", &data);
insertAtEnd(data);
}
printList();
break;
case 3:
printf("Hangi pozisyona eleman eklenecek? ");
scanf("%d", &position);
printf("Eklenecek elemanı girin: ");
scanf("%d", &data);
insertAtPosition(data, position);
printList();
break;
case 4:
deleteFromBeginning();
printList();
break;
case 5:
deleteFromEnd();
printList();
break;
case 6:
printf("Hangi pozisyondaki eleman silinecek? ");
scanf("%d", &position);
deleteFromPosition(position);
printList();
break;
case 7:
exit(0);
default:
printf("Geçersiz seçim\n");
}
}
return 0;
}