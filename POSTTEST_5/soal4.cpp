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

// Fungsi untuk traversal post-order (left > right > root)
void postOrderTraversal(Node* root) {
    // Kalau node kosong > langsung keluar (base case)
    if (root == nullptr) return;

    // Telusuri subtree kiri dulu
    postOrderTraversal(root->left);

    // Telusuri subtree kanan
    postOrderTraversal(root->right);

    // Cetak data node saat ini
    cout << root->data << " ";
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

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root);
    cout << endl;
    // Output harusnya: 20 40 30 60 80 70 50

    /*
      Penjelasan:
      - Urutan post-order: kiri > kanan > root
      - Jadi dia print anak kiri dulu, terus kanan, terakhir node induknya
    */
    return 0;
}

