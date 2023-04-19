#include <stdio.h>
#include <stdlib.h>

// Agac dugumu yapisi
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Agac kontrol fonksiyonu
int isTree(Node* node) {
    // Dugum NULL ise agac yapisi saglanir.
    if (node == NULL) {
        return 1;
    }

    // Sol alt agac icin kontrol yapilir.
    if (node->left != NULL && node->left->data > node->data) {
        return 0;
    }

    // Sag alt agac icin kontrol yapilir.
    if (node->right != NULL && node->right->data < node->data) {
        return 0;
    }

    // Alt agaclarin her biri icin kontrol yapilir.
    if (!isTree(node->left) || !isTree(node->right)) {
        return 0;
    }

    // Tum kontrolleri gecen bir agaç yapisi saglanir.
    return 1;
}

int main() {
    // Ağacın oluşturulması
    Node* root = NULL;
    int sayi,n ;
    printf("kac sayi girilecek ");
    scanf("%d",&n);
    printf("sayilar giriniz : ");
    int i;
    for( i=0; i<n; i++) {
        scanf("%d", &sayi);
        // Dugum olusturulur ve agaca eklenir.
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = sayi;
        new_node->left = NULL;
        new_node->right = NULL;

        // Agac bos ise yeni dugum root olarak atanır.
        if (root == NULL) {
            root = new_node;
        } else {
            // Agacin dugumleri taranarak, yeni dugumun yerlestirilecegi dugum bulunur.
            Node* current = root;
            Node* parent;
            while (1) {
                parent = current;
                if (sayi < current->data) {
                    current = current->left;
                    if (current == NULL) {
                        parent->left = new_node;
                        break;
                    }
                } else {
                    current = current->right;
                    if (current == NULL) {
                        parent->right = new_node;
                        break;
                    }
                }
            }
        }
    }

    // Agacin kontrolu yapilir.
    if (isTree(root)) {
        printf("Verilen veri modeli agac yapisina sahiptir.\n");
    } else {
        printf("Verilen veri modeli agac yapisina sahip degildir.\n");
    }

    return 0;
}
