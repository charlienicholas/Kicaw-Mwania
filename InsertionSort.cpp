#include <iostream>
using namespace std;

int main() {
    // TAHAP 1: Menyiapkan data yang berantakan
    int data[] = {9, 5, 1, 4, 3};
    int n = 5; // Jumlah elemen

    cout << "Data awal: 9, 5, 1, 4, 3" << endl;
    cout << "--------------------------" << endl;

    // TAHAP 2: Mulai menyisir data (dimulai dari elemen kedua/indeks 1)
    for (int i = 1; i < n; i++) {
        int key = data[i]; // Ini adalah "kartu" yang sedang kita pegang
        int j = i - 1;     // Ini adalah indeks teman di sebelah kirinya

        cout << "Iterasi " << i << ": Mengambil angka " << key << endl;

        // TAHAP 3: Proses "Menggeser" (Shifting)
        // Selama angka di kiri lebih besar dari key, kita geser ke kanan
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j]; // Geser angka yang lebih besar ke kanan
            j = j - 1;             // Pindah ke kiri lagi untuk cek angka berikutnya
        }

        // TAHAP 4: Penyisipan (Insertion)
        // Setelah ketemu tempat yang pas (atau sudah mentok di paling kiri)
        data[j + 1] = key;

        // TAHAP 5: Tampilkan hasil sementara agar terlihat perubahannya
        cout << "Hasil sementara: ";
        for (int k = 0; k < n; k++) cout << data[k] << " ";
        cout << endl << endl;
    }

    cout << "--------------------------" << endl;
    cout << "Hore! Data sudah rapi: ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    
    cout << endl;
    return 0;
}