#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi buat cari nilai terbesar di BST
int findMaxValue(Node* root) {
    // Kalau tree kosong → balikin -1
    if (root == nullptr) return -1;

    // Selama masih ada anak kanan, terus jalan ke kanan
    while (root->right != nullptr) {
        root = root->right;
    }

    // Node paling kanan adalah nilai terbesar
    return root->data;
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl;
    // Output harusnya: 80

    /*
      Penjelasan:
      - Nilai terbesar di BST selalu ada di ujung kanan
      - Di tree ini node paling kanan adalah 80
    */
    return 0;
}

