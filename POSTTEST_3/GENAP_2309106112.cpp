#include <bits/stdc++.h>
using namespace std;

struct FlightNode {
    string kode;
    string tujuan;
    string status;
    FlightNode* next;
    FlightNode* prev;
    FlightNode(const string& k, const string& t, const string& s)
        : kode(k), tujuan(t), status(s), next(nullptr), prev(nullptr) {}
};

//DOUBLE LINKED LIST
struct FlightList {
    FlightNode* head;
    FlightNode* tail;
    FlightList(): head(nullptr), tail(nullptr) {}

    // tamnah di akhir
    void addBack(const string& kode, const string& tujuan, const string& status) {
        FlightNode* node = new FlightNode(kode, tujuan, status);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    // tambah di depan
    void addFront(const string& kode, const string& tujuan, const string& status) {
        FlightNode* node = new FlightNode(kode, tujuan, status);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    // sisip jadwal
    void insertAt(const string& kode, const string& tujuan, const string& status, int pos) {
        if (pos <= 1 || !head) {
            addFront(kode, tujuan, status);
            return;
        }
        FlightNode* cur = head;
        int idx = 1;
        while (cur && idx < pos-1) { cur = cur->next; idx++; }
        if (!cur || !cur->next) {
            addBack(kode, tujuan, status);
            return;
        }
        FlightNode* node = new FlightNode(kode, tujuan, status);
        node->next = cur->next;
        node->prev = cur;
        cur->next->prev = node;
        cur->next = node;
    }

    // hapus jadwal awal
    void removeFront() {
        if (!head) { cout << "Tidak ada jadwal...\n"; return; }
        FlightNode* tmp = head;
        cout << "Menghapus jadwal...: " << tmp->kode << " (" << tmp->tujuan << ")\n";
        if (head == tail) { head = tail = nullptr; }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete tmp;
    }

    // cari berdasarkan kode
    FlightNode* findByKode(const string& kode) {
        FlightNode* cur = head;
        while (cur) {
            if (cur->kode == kode) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    // update status penerbangan
    void updateStatus(const string& kode, const string& newStatus) {
        FlightNode* f = findByKode(kode);
        if (!f) { cout << "Kode " << kode << " tidak ditemukan sayang.\n"; return; }
        f->status = newStatus;
        cout << "Status " << kode << " diperbarui menjadi: " << newStatus << "\n";
    }

    // tampilkan semua jadwal (dari depan)
    void displayForward() {
        if (!head) { cout << "Tidak ada jadwal...\n"; return; }
        cout << left << setw(14) << "Kode" << setw(20) << "Tujuan" << setw(20) << "Status" << "\n";
        cout << string(54,'-') << "\n";
        FlightNode* cur = head;
        while (cur) {
            cout << setw(14) << cur->kode << setw(20) << cur->tujuan << setw(20) << cur->status << "\n";
            cur = cur->next;
        }
    }

    // tampilkan semua jadwal (dari belakang)
    void displayBackward() {
        if (!tail) { cout << "Tidak ada jadwal...\n"; return; }
        cout << left << setw(14) << "Kode" << setw(20) << "Tujuan" << setw(20) << "Status" << "\n";
        cout << string(54,'-') << "\n";
        FlightNode* cur = tail;
        while (cur) {
            cout << setw(14) << cur->kode << setw(20) << cur->tujuan << setw(20) << cur->status << "\n";
            cur = cur->prev;
        }
    }

    // detail berdasarkan kode
    void showDetail(const string& kode) {
        FlightNode* f = findByKode(kode);
        if (!f) { cout << "Kode tidak ditemukan...\n"; return; }
        cout << "=== Detail Jadwal ===\n";
        cout << "Kode   : " << f->kode << "\n";
        cout << "Tujuan : " << f->tujuan << "\n";
        cout << "Status : " << f->status << "\n";
    }

    ~FlightList() {
        FlightNode* cur = head;
        while (cur) {
            FlightNode* nx = cur->next;
            delete cur;
            cur = nx;
        }
    }
};

int main() {
    string name = "Virgiyo Lahang";
    string nim = "2309106112";

    int last1 = nim.back() - '0';
    int last3 = stoi(nim.substr(nim.size()-3));
    int insertPos = (last1 == 0) ? 2 : (last1+1);

    string baseCode = to_string(last3);
    while (baseCode.size() < 3) baseCode = "0" + baseCode;

    int autoCounter = 0;
    auto generateKode = [&]() {
        if (autoCounter == 0) { autoCounter++; return "JT-" + baseCode; }
        string k = "JT-" + baseCode + "-" + to_string(autoCounter);
        autoCounter++;
        return k;
    };

    FlightList fl;

    while (true) {
        cout << "\n+--------------------------------------+\n";
        cout << "|        FLIGHT SCHEDULE SYSTEM        |\n";
        cout << "|   [ " << name << " - " << nim << " ]    |\n";
        cout << "+--------------------------------------+\n";
        cout << "1. Tambah Jadwal Penerbangan\n";
        cout << "2. Sisipkan Jadwal Penerbangan\n";
        cout << "3. Hapus Jadwal Paling Awal\n";
        cout << "4. Update Status Penerbangan\n";
        cout << "5. Tampilkan Semua Jadwal (depan)\n";
        cout << "6. Tampilkan Semua Jadwal (belakang)\n";
        cout << "7. Tampilkan Detail Jadwal\n";
        cout << "0. Keluar\n";
        cout << "Pilih> ";
        string opt; getline(cin, opt);

        if (opt=="0") break;
        else if (opt=="1") {
            string tujuan, status;
            cout << "Tujuan: "; getline(cin, tujuan);
            cout << "Status: "; getline(cin, status);
            fl.addBack(generateKode(), tujuan, status);
        }
        else if (opt=="2") {
            string tujuan, status;
            cout << "Tujuan: "; getline(cin, tujuan);
            cout << "Status: "; getline(cin, status);
            cout << "Menyisip pada posisi " << insertPos << "\n";
            fl.insertAt(generateKode(), tujuan, status, insertPos);
        }
        else if (opt=="3") fl.removeFront();
        else if (opt=="4") {
            cout << "Kode penerbangan: ";
            string kode; getline(cin, kode);
            cout << "Status baru: ";
            string st; getline(cin, st);
            fl.updateStatus(kode, st);
        }
        else if (opt=="5") fl.displayForward();
        else if (opt=="6") fl.displayBackward();
        else if (opt=="7") {
            cout << "Masukkan kode: ";
            string kode; getline(cin, kode);
            fl.showDetail(kode);
        }
        else cout << "Pilih yang bener... sayang.\n";
    }

    cout << "Keluar... sampai jumpa! sayang.\n";
    return 0;
}

