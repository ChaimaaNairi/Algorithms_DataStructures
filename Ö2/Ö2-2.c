#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Kuyruk yapısı
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Kuyruk oluşturmak için yardımcı fonksiyon
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

// Kuyruğa eleman eklemek için fonksiyon
void enqueue(Queue* q, int value) {
    if (q->size == MAX_SIZE) {
        printf("Kuyruk dolu!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;
}

// Kuyruktan eleman silmek için fonksiyon
int dequeue(Queue* q) {
    if (q->size == 0) {
        printf("Kuyruk boş!\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return value;
}

// Kuyruktaki ilk elemana bakmak için fonksiyon
int peek(Queue* q) {
    if (q->size == 0) {
        printf("Kuyruk boş!\n");
        return -1;
    }
    return q->data[q->front];
}

// Kuyruğun eleman sayısını döndüren fonksiyon
int size(Queue* q) {
    return q->size;
}

int main() {
    // Kuyruk oluştur
    Queue* q = createQueue();

    // Eleman ekle
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    // Kuyruktaki eleman sayısı
    printf("Kuyruk boyutu: %d\n", size(q));

    // Kuyruktan eleman çıkar
    int value = dequeue(q);
    printf("Kuyruktan çıkarılan eleman: %d\n", value);

    // Kuyruktaki ilk elemanı görüntüle
    printf("Kuyruktaki ilk eleman: %d\n", peek(q));

    // Kuyruk boş mu?
    if (size(q) == 0) {
        printf("Kuyruk boş!\n");
    } else {
        printf("Kuyruk dolu!\n");
    }

    return 0;
}
