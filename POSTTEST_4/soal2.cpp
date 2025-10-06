#include <iostream>
#include <string>
using namespace std;

// struktur node buat stack
struct Node {
    char data;
    Node* next;
};

// fungsi push untuk masukin karakter ke stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// fungsi pop untuk ngeluarin karakter dari stack
char pop(Node*& top) {
    if (top == nullptr) return '\0'; // stack kosong
    Node* temp = top;
    char popped = temp->data;
    top = top->next;
    delete temp;
    return popped;
}

// fungsi buat ngecek apakah kurung buka dan tutup cocok
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// fungsi utama untuk ngecek keseimbangan tanda kurung
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr; // stack kosong di awal

    for (char c : expr) {
        // kalau ketemu kurung buka > push ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // kalau ketemu kurung tutup > cek pasangannya
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) {
                // stack kosong tapi ada kurung tutup > tidak seimbang
                return false;
            }
            char topChar = pop(stackTop);
            if (!isMatchingPair(topChar, c)) {
                // pasangan buka-tutup nggak cocok > tidak seimbang
                return false;
            }
        }
    }

    // setelah semua dicek, stack harus kosong > seimbang
    bool balanced = (stackTop == nullptr);

    // bersihin sisa node biar nggak bocor memori
    while (stackTop != nullptr) {
        Node* temp = stackTop;
        stackTop = stackTop->next;
        delete temp;
    }

    return balanced;
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "{[(])}";

    cout << expr1 << " > " << (areBracketsBalanced(expr1) ? "seimbang" : "tidak seimbang") << endl;
    cout << expr2 << " > " << (areBracketsBalanced(expr2) ? "seimbang" : "tidak seimbang") << endl;

    /*
       Penjelasan:
       - "{[()]}" > tiap kurung buka punya pasangan tutup yang benar urutannya,
         jadi hasilnya "seimbang"
       - "{[(])}" > urutannya salah, karena setelah '[' harusnya ']' bukan ')',
         jadi hasilnya "tidak Seimbang"
       - stack bantu nyimpen kurung buka sementara sampai ketemu kurung tutup yang cocok
    */

    return 0;
}
