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
    if (root == nullptr) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// Fungsi traversal pre-order (root > left > right)
void preOrderTraversal(Node* root) {
    // Kalau node kosong > langsung keluar
    if (root == nullptr) return;

    // Cetak data node saat ini (karena pre-order mulai dari root)
    cout << root->data << " ";

    // Telusuri subtree kiri
    preOrderTraversal(root->left);

    // Telusuri subtree kanan
    preOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root);
    cout << endl;
    // Output harusnya: 50 30 20 40 70 60 80

    /*
      Penjelasan:
      - Urutan pre-order: root > kiri > kanan
      - Jadi program bakal cetak node utama dulu,
        baru lanjut ke kiri, lalu kanan
    */
    return 0;
}

