#include <bits/stdc++.h>
using namespace std;

// File: GENAP_2309106112.cpp
// Tugas: Flight Schedule System (Tema GENAP)
// Nama : VIRGIYO LAHANG
// NIM  : 2309106112

struct Node {
    string kodePenerbangan;
    string tujuan;
    string status;
    Node* next;
    Node(const string &k, const string &t, const string &s) : kodePenerbangan(k), tujuan(t), status(s), next(nullptr) {}
};

class FlightList {
private:
    Node* head;
    int sz;
    string baseCode; // misalnya "JT-112"
    int codeCounter; // 0 -> JT-112, 1 -> JT-112-1, 2 -> JT-112-2
    string nim;

    string generateCode() {
        string code;
        if (codeCounter == 0) code = baseCode;
        else code = baseCode + "-" + to_string(codeCounter);
        codeCounter++;
        return code;
    }

public:
    FlightList(const string &nim_) : head(nullptr), sz(0), codeCounter(0), nim(nim_) {
        if (nim.size() >= 3) {
            baseCode = "JT-" + nim.substr(nim.size()-3);
        } else baseCode = "JT-000";
    }

    ~FlightList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void addEnd(const string &tujuan, const string &status) {
        string kode = generateCode();
        Node* node = new Node(kode, tujuan, status);
        if (!head) head = node;
        else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
        sz++;
        cout << "Jadwal ditambahkan (akhir) dengan kode: " << kode << "\n";
    }

    void insertAtPosByNIM(const string &tujuan, const string &status) {
        int lastDigit = 0;
        if (!nim.empty() && isdigit(nim.back())) lastDigit = nim.back() - '0';
        int pos = lastDigit + 1;
        if (pos < 1) pos = 1;
        if (pos > sz + 1) pos = sz + 1; 

        string kode = generateCode();
        Node* node = new Node(kode, tujuan, status);

        if (pos == 1) {
            node->next = head;
            head = node;
        } else {
            Node* cur = head;
            for (int i = 1; i < pos-1 && cur; ++i) cur = cur->next;
            if (!cur) {
                cur = head;
                if (!cur) head = node;
                else {
                    while (cur->next) cur = cur->next;
                    cur->next = node;
                }
            } else {
                node->next = cur->next;
                cur->next = node;
            }
        }
        sz++;
        cout << "Jadwal disisipkan di posisi " << pos << " dengan kode: " << kode << "\n";
    }

    void deleteFirst() {
        if (!head) {
            cout << "Tidak ada jadwal untuk dihapus.\n";
            return;
        }
        Node* tmp = head;
        head = head->next;
        cout << "Menghapus jadwal paling awal: " << tmp->kodePenerbangan << " (" << tmp->tujuan << ")\n";
        delete tmp;
        sz--;
    }

    void updateStatus(const string &kode, const string &newStatus) {
        Node* cur = head;
        while (cur) {
            if (cur->kodePenerbangan == kode) {
                cur->status = newStatus;
                cout << "Status untuk " << kode << " berhasil diperbarui menjadi: " << newStatus << "\n";
                return;
            }
            cur = cur->next;
        }
        cout << "Kode penerbangan tidak ditemukan: " << kode << "\n";
    }

    void displayAll() const {
        if (!head) {
            cout << "Inventory jadwal kosong.\n";
            return;
        }
        cout << "+------------------------------------------------------+\n";
        cout << "|  No  | Kode Penerbangan | Tujuan                 | Status           |\n";
        cout << "+------------------------------------------------------+\n";
        Node* cur = head;
        int idx = 1;
        while (cur) {
            cout << setw(5) << idx << " | " << setw(16) << cur->kodePenerbangan << " | ";
            cout << left << setw(22) << cur->tujuan << " | " << right << setw(15) << cur->status << " |\n";
            cout << right; // reset
            cur = cur->next;
            idx++;
        }
        cout << "+------------------------------------------------------+\n";
    }

    int size() const { return sz; }
};

int main() {
    const string NAMA = "VIRGIYO LAHANG";
    const string NIM = "2309106112";

    FlightList flights(NIM);

    while (true) {
        cout << "\n+------------------------------------------------------------+\n";
        cout << "|             FLIGHT SCHEDULE SYSTEM                         |\n";
        cout << "|           [ " << NAMA << " - " << NIM << " ]";
        cout << setw(41 - (int)NAMA.size() - (int)NIM.size()) << " |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                               |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                             |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                                |\n";
        cout << "| 4. Update Status Penerbangan                               |\n";
        cout << "| 5. Tampilkan Semua Jadwal                                  |\n";
        cout << "| 0. Keluar                                                  |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "Pilih menu: ";
        int pilihan;
        if (!(cin >> pilihan)) break;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (pilihan == 0) {
            cout << "Keluar... sampai jumpa!\n";
            break;
        }

        if (pilihan == 1) {
            string tujuan, status;
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            cout << "Masukkan status (misal: Tepat Waktu / Terlambat / Naik Pesawat): ";
            getline(cin, status);
            flights.addEnd(tujuan, status);
        } else if (pilihan == 2) {
            string tujuan, status;
            cout << "(Sisip otomatis pada posisi: digit terakhir NIM + 1)\n";
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            cout << "Masukkan status: ";
            getline(cin, status);
            flights.insertAtPosByNIM(tujuan, status);
        } else if (pilihan == 3) {
            flights.deleteFirst();
        } else if (pilihan == 4) {
            string kode, statusBaru;
            cout << "Masukkan kode penerbangan yang ingin di-update: ";
            getline(cin, kode);
            cout << "Masukkan status baru: ";
            getline(cin, statusBaru);
            flights.updateStatus(kode, statusBaru);
        } else if (pilihan == 5) {
            flights.displayAll();
        } else {
            cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    }

    return 0;
}
