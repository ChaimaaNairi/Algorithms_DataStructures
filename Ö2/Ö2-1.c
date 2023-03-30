#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100

// stack veri yapisi
typedef struct stack_node {
    char data;
    struct stack_node* next;
} StackNode;

typedef struct stack {
    StackNode* top;
} Stack;

// Yeni bir stack olusturan fonksiyon
Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

// Stack'e veri ekleyen fonksiyon
void push(Stack* s, char data) {
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

// Stack'ten veri cikaran fonksiyon
char pop(Stack* s) {
    if(s->top == NULL)
        return -1;
    
    StackNode* temp = s->top;
    char data = temp->data;
    s->top = s->top->next;
    free(temp);
    
    return data;
}

// queue veri yapisi
typedef struct queue_node {
    char data;
    struct queue_node* next;
} QueueNode;

typedef struct queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Yeni bir queue olusturan fonksiyon
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Queue'ya veri ekleyen fonksiyon
void enqueue(Queue* q, char data) {
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

// Queue'dan veri cikaran fonksiyon
char dequeue(Queue* q) {
    if(q->front == NULL)
        return -1;
       
    QueueNode* temp = q->front;
    char data = temp->data;
   
    q->front = q->front->next;
   
    if(q->front == NULL)
        q->rear = NULL;
   
    free(temp);
   
    return data;
}

// palindrom kontrol fonksiyonu
int isPalindrome(char* str) {
    int i, len;
    char c;

    // stack ve queue olusturulur
    Stack* s = createStack();
    Queue* q = createQueue();

    // stringdeki tum karakterler stack ve queue'ya eklenir
    len = strlen(str);
    for (i = 0; i < len; i++) {
        c = str[i];
        if (isalnum(c)) { // sadece harf ve rakamlar alinir
            c = tolower(c); // buyuk harfler kucuk harfe cevrilir
            push(s, c);
            enqueue(q, c);
        }
    }

    // stack ve queue'tan karakterler cikarilir ve karsilastirilir
    while (s->top != NULL) {
        if (pop(s) != dequeue(q)) {
            return 0; // palindrom degil
        }
    }

    return 1; // palindrom
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
   
    // fgets ile okunan string'in sonunda newline karakteri olabilir, onu silmek için
    str[strcspn(str, "\n")] = '\0';
   
    if(isPalindrome(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);
   
    return 0;
}
