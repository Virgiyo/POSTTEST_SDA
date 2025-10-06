#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;   // menyimpan satu karakter dari string
    Node* next;  // ini adalah pointer node dibawahnya
};

// fungsi untuk menambahkan data ke atas stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top}; // membuat node baru yang menunjuk top ke node lama
    top = newNode;                       // menjadikan node baru sebagai top node baru
}

// fungsi untuk mengambil data teratas dari stack dan menghapusnya
char pop(Node*& top) {
    if (top == nullptr) return '\0';     // kalau stack kosong, kembalikan null char
    Node* temp = top;                    // simpan node paling atas
    char poppedValue = temp->data;       // ambil data dari node itu
    top = top->next;                     // geser top ke bawah
    delete temp;                         // hapus node lama
    return poppedValue;                  // kembalikan karakter yang di pop
}

// fungsi untuk membalik string menggunakan stack
string reverseString(string s) {
    Node* stackTop = nullptr;  // stack kosong di awal
    string reversed = "";

    // push setiap karakter dari string s ke dalam stack
    for (char c : s) {
        push(stackTop, c);
    }

    // pop semua karakter dari stack dan tambahkan ke string reversed
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed; // hasil akhir string sudah terbalik
}

int main() {
    string text = "Struktur Data";

    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl;

    /*
       Penjelasan:
       - kita menaruh setiap huruf ke dalam stack satu per satu
       - karena stack bersifat LIFO (yang masuk terakhir keluar pertama),
         maka saat di-pop urutannya otomatis terbalik
       - jadi hasil akhirnya: "ataD rutkurtS"
    */
    return 0;
}
