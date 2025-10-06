#include <iostream>
using namespace std;

// struktur node untuk circular doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

/*
 * fungsi untuk menukar posisi head dan tail tanpa menukar data
 * hanya pointer yang diubah supaya posisi node benar-benar berpindah
 */
void exchangeHeadAndTail(Node *&head_ref) {
    // kalau list kosong atau cuma 1 node → tidak perlu ditukar
    if (head_ref == nullptr || head_ref->next == head_ref) return;

    Node* head = head_ref;
    Node* tail = head_ref->prev;  // tail adalah node sebelum head

    // kalau hanya ada 2 node, tinggal swap head dan tail aja
    if (head->next == tail) {
        head_ref = tail; // tail jadi head baru
        return;
    }

    // simpan tetangga head dan tail
    Node* headNext = head->next;
    Node* tailPrev = tail->prev;

    // hubungkan tetangga head dan tail yang lama
    headNext->prev = tail;
    tailPrev->next = head;

    // tukar posisi head dan tail
    tail->next = headNext;
    tail->prev = head->prev;  // tail sebelumnya di belakang head
    head->next = head_ref;    // head lama akan diletakkan setelah tail
    head->prev = tailPrev;

    // update koneksi lingkaran
    tail->prev->next = tail;
    head->next->prev = head;

    // update pointer head_ref ke node tail, karena tail sekarang jadi head baru
    head_ref = tail;
}

// fungsi untuk menampilkan list
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

// fungsi untuk menambahkan node di akhir
void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node *head = nullptr;

    // buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head);

    /*
       Penjelasan:
       - sebelum tukar: head = 1, tail = 5 → urutan: 1 2 3 4 5
       - setelah tukar: head = 5, tail = 1 → urutan jadi: 5 2 3 4 1
       - tidak ada data yang ditukar, hanya pointer yang diubah
       - karena circular doubly linked list, semua node tetap terhubung melingkar
    */

    return 0;
}
