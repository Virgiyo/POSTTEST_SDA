#include <iostream>
#include <algorithm>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

bool compareIPK(Mahasiswa a, Mahasiswa b) {
    return a.ipk < b.ipk; // ascending
}

int main() {
    Mahasiswa mhs[4];

    for (int i = 0; i < 4; i++) {
        cout << "Masukkan data mahasiswa ke-" << i+1 << endl;
        cout << "Nama : "; cin >> mhs[i].nama;
        cout << "NIM  : "; cin >> mhs[i].nim;
        cout << "IPK  : "; cin >> mhs[i].ipk;
        cout << endl;
    }

    sort(mhs, mhs+4, compareIPK);

    cout << "Data mahasiswa setelah diurutkan berdasarkan IPK ascending:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << mhs[i].nama << " | " << mhs[i].nim << " | " << mhs[i].ipk << endl;
    }

    return 0;
}
