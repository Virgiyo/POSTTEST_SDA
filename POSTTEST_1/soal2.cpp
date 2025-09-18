#include <iostream>
using namespace std;

int main() {
    int matriks[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    int jumlah = 0;
    for (int j = 0; j < 3; j++) {
        jumlah += matriks[1][j];
    }

    cout << "Jumlah elemen baris genap = " << jumlah << endl;
    return 0;
}
