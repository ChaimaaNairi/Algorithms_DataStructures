#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Kuyruk yapisi
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Kuyruk olusturmak için yardimci fonksiyon
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

// Kuyruga eleman eklemek için fonksiyon
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

// Kuyrugun eleman sayisini donduren fonksiyon
int size(Queue* q) {
    return q->size;
}



int main() {
    int queue[MAX_SIZE];
    int front = 0, rear = -1;
    int choice, num, i;
    
    do {
        printf("\n------ MENU ------\n");
        printf("1. eleman ekle\n");
        printf("2. eleman sil\n");
        printf("3. kuyruk Display \n");
        printf("4. Exit\n");
        printf("------------------\n");
        printf("Seciminizi girin: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (rear == MAX_SIZE - 1) {
                    printf("Kuyruk dolu.\n");
                } else {
                    printf("Eklenecek ogeyi girin: ");
                    scanf("%d", &num);
                    rear++;
                    queue[rear] = num;
                    printf("%d basariyla eklendi.\n", num);
                }
                break;
            case 2:
                if (front > rear) {
                    printf("kuyruk bos.\n");
                } else {
                    num = queue[front];
                    front++;
                    printf("%d basariyla silindi.\n", num);
                }
                break;
            case 3:
                if (front > rear) {
                    printf("kuyruk bos.\n");
                } else {
                    printf("Kuyruk ogeleri: ");
                    for ( i = front; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
        }
    } while (choice != 4);
    
    return 0;
}
