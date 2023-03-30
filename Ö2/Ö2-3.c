#include <stdio.h>
#include <stdlib.h>
#define BASE 10

// kuyruk veri yapisi
typedef struct queue_node {
    int data;
    struct queue_node* next;
} QueueNode;


typedef struct queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

//Queue yapisi olusturur ve bu yapiyi tutan bir isaretçi dondurur
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

//Verilen Queue yapisina yeni bir dugum ekler. 
void enqueue(Queue* q, int data) {
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    new_node->data = data;
    new_node->next = NULL;
   
    if(q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }
   
    q->rear->next = new_node;
    q->rear = new_node;
}

//Bir kuyruktan eleman çikarmak için kullanilir. 
int dequeue(Queue* q) {
    if(q->front == NULL)
        return -1;
       
    QueueNode* temp = q->front;
    int data = temp->data;
   
    q->front = q->front->next;
   
    if(q->front == NULL)
        q->rear = NULL;
   
    free(temp);
   
    return data;
}

// Bir sayinin belirli bir basamagindaki rakami döndüren fonksiyon
int getDigit(int num, int place) {
    int digit;
     int i;
    for( i = 0; i <= place; i++) {
        digit = num % BASE;
        num /= BASE;
    }
   
    return digit;
}


void radixSort(int arr[], int n) {
     int i,j ;
    // en buyuk sayinin basamak sayisi bulunur
    int max_num = arr[0];
    for( i = 1; i < n; i++) {
        if(arr[i] > max_num)
            max_num = arr[i];
    }
    int num_digits = 0;
    while(max_num > 0) {
        max_num /= BASE;
        num_digits++;
    }
   
    // kuyruk dizisi olusturulur
    Queue** queue_arr = (Queue**)malloc(sizeof(Queue*) * BASE);
    for( i = 0; i < BASE; i++)
        queue_arr[i] = createQueue();
   
    // siralama yapilir
    int divisor = 1;
   
    for( i = 0; i < num_digits; i++) {
        // her rakama gore kuyruklara ekleme yapilir
        for( j = 0; j < n; j++) {
            int digit = getDigit(arr[j], i);
            enqueue(queue_arr[digit], arr[j]);
        }
       
        // kuyruklardan elemanlar çikarilip diziye yerlestirilir
        int index = 0;
        for( j = 0; j < BASE; j++) {
            while(queue_arr[j]->front != NULL) {
                arr[index++] = dequeue(queue_arr[j]);
            }
        }
       
        // bolucu degeri güncellenir
        divisor *= BASE;
    }
   
    // bellekte ayrilan kuyruklar serbest birakilir
    for( i = 0; i < BASE; i++)
        free(queue_arr[i]);
    free(queue_arr);
}

//Dizinin elemanlarini ekrana yazdirmak için kullanilir. 
void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int n,i;
    
    // Kullanicidan eleman sayisi alinir
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Elemanlarin girilmesi istenir
    int arr[n];
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Siralama öncesi dizi yazdirilir
    printf("Before sorting:\n");
    printArray(arr, n);
    
    // Radix sort uygulanir
    radixSort(arr, n);
    
    // Siralama sonrasi dizi yazdirilir
    printf("\nAfter sorting:\n");
    printArray(arr, n);
    return 0;
}
