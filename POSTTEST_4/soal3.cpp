#include <iostream>
#include <string>
using namespace std;

// struktur Node untuk menyimpan data antrian printer
struct Node {
    string document; // nama dokumen
    Node* next;      // pointer ke dokumen berikutnya
};

// fungsi untuk menambahkan dokumen ke antrian enqueue
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // kalau antrian kosong > front dan rear menunjuk ke node baru
    if (front == nullptr) {
        front = rear = newNode;
    } else {
        // kalau tidak kosong > sambungkan rear ke node baru dan geser rear
        rear->next = newNode;
        rear = newNode;
    }
}

// fungsi untuk mengeluarkan dokumen dari antrian (dequeue)
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // kalau kosong, kembalikan string kosong

    Node* temp = front;          // simpan node paling depan
    string docName = temp->document; // ambil nama dokumennya
    front = front->next;         // geser front ke elemen berikutnya

    // kalau front jadi nullptr, berarti antrian kosong > rear juga harus nullptr
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp; // hapus node lama
    return docName;
}

// fungsi untuk memproses semua dokumen di antrian
void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr; // elemen paling depan
    Node* rear = nullptr;  // elemen paling belakang

    // tambahkan beberapa dokumen ke antrian printer
    enqueue(front, rear, "document1.pdf");
    enqueue(front, rear, "report.docx");
    enqueue(front, rear, "presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    /*
       Penjelasan:
       - dokumen pertama yang masuk adalah yang pertama keluar
       - prosesnya berurutan:
         1. document1.pdf
         2. report.docx
         3. presentation.pptx
       - setelah semua diproses, antrian kosong
       - queue pakai FIFO (First In, First Out)
    */

    return 0;
}
