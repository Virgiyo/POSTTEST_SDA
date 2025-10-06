#include <iostream>
using namespace std;

// struktur node untuk Circular Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

/*
 * fungsi untuk menyisipkan node baru secara terurut ascending
 * jika list kosong > buat node pertama
 * jika data baru lebih kecil dari head > sisip di awal dan update head
 * jika di tengah > cari posisi yang tepat
 */
void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // kasus 1: List masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node* current = head_ref;

    // kasus 2: data baru lebih kecil dari head → jadi head baru
    if (data < head_ref->data) {
        Node* tail = head_ref->prev; // tail = node sebelum head

        newNode->next = head_ref;
        newNode->prev = tail;
        tail->next = newNode;
        head_ref->prev = newNode;
        head_ref = newNode; // update head ke node baru
        return;
    }

    // kasus 3: Cari posisi di tengah atau akhir
    // jalan sampai menemukan posisi di mana data berikutnya lebih besar
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    // sisipkan setelah current
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

// fungsi untuk menampilkan isi list dari head ke depan 
void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node *head = nullptr;

    // menyisipkan data acak
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);

    /*
       Penjelasan:
       - saat pertama kali, list kosong > node 30 jadi head
       - lalu masukkan 10 > lebih kecil dari head > 10 jadi head baru
       - lalu 40 > lebih besar dari semua > di akhir
       - lalu 20 > di antara 10 dan 30
       - hasil akhirnya: 10 20 30 40 (urut ascending)
    */
    return 0;
}
