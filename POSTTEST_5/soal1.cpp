#include <iostream>
using namespace std;

// Struktur Node buat Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); // Kalau tree kosong, langsung buat root baru
    }
    if (val < root->data) {
        root->left = insert(root->left, val); // Masuk ke subtree kiri
    } else if (val > root->data) {
        root->right = insert(root->right, val); // Masuk ke subtree kanan
    }
    return root;
}

// Fungsi buat menghitung total jumlah node di dalam tree
int countNodes(Node* root) {
    // Kalau root kosong, artinya tidak ada node > kembalikan 0
    if (root == nullptr) return 0;

    // Hitung node sekarang (1), lalu tambah jumlah node kiri & kanan
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;

    // Masukkan data ke dalam tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl;
    // Output harusnya: 4

    /*
      Penjelasan:
      Tree:
          50
         /  \
       30    70
       /
      20

      Total node = 4 (50, 30, 70, 20)
    */
    return 0;
}

