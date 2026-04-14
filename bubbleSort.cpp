#include <iostream>

using namespace std;

int main() {
    int data[4] = {27, 14, 70, 1};
    int n = 4;

    cout << "Proses Bubble Sort:" << endl;

    cout << "Data Awal -> ";
    for (int k = 0; k < n; k++) cout << data[k] << " ";
    cout << endl << endl;

    for (int i = 0; i < n - 1; i++) {

        cout << "Perulangan ke " << i+1 << endl;
        for (int j = 0; j < n - 1; j++) {

            cout << data[j] << " vs " << data[j+1];

            if (data[j] > data[j+1]) {
                // Tukar posisi
                int swap = data[j];
                data[j] = data[j+1];
                data[j+1] = swap;
                cout << " (Tukar)";
            } else {
                cout << " (Tetap)";
            }

            // Tampilkan baris data saat ini
            cout << " -> ";
            for (int k = 0; k < n; k++) cout << data[k] << " ";
            cout << endl;
        }
        cout << "----------" << endl;
    }

    cout << "Hasil Akhir: ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    
    cout << endl;

    return 0;
}