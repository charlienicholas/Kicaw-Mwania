#include <iostream>

using namespace std;

// Fungsi pembantu untuk menampilkan array dalam satu baris
void cetakArray(int L[], int n) {
    for (int k = 0; k < n; k++) {
        cout << L[k] << " ";
    }
    cout << endl;
}

void tukar(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partisi(int L[], int p, int r, int nTotal) {
    int x = L[p]; // Pivot dipilih dari elemen pertama
    int i = p;
    int j = r;

    cout << endl << "Pivot dipilih: " << x << endl;
    cout << "Posisi awal: ";
    cetakArray(L, nTotal);

    while (true) {
        // Cari elemen dari kanan yang <= pivot
        while (L[j] > x) {
            j--;
        }
        // Cari elemen dari kiri yang >= pivot
        while (L[i] < x) {
            i++;
        }

        if (i < j) {
            cout << "Tukar " << L[i] << " (kiri) dengan " << L[j] << " (kanan)" << endl;
            tukar(L[i], L[j]);
            
            cout << "Hasil tukar: ";
            cetakArray(L, nTotal);
            
            // Antisipasi angka kembar agar tidak infinite loop
            if (L[i] == L[j]) {
                i++;
            }
        } else {
            return j;
        }
    }
}

void quickSort(int L[], int p, int r, int nTotal) {
    if (p < r) {
        int j = partisi(L, p, r, nTotal);
        // Rekursi untuk sisi kiri dan kanan
        quickSort(L, p, j, nTotal);
        quickSort(L, j + 1, r, nTotal);
    }
}

int main() {
    int n;
    cout << "PROGRAM QUICK SORT (HOARE PARTITION)\n";
    cout << "Masukkan jumlah angka: ";
    cin >> n;

    int *data = new int[n];
    cout << "Masukkan " << n << " angka: " << endl;
    for (int k = 0; k < n; k++) {
        cout << "Data ke " << k+1 << " = ";
        cin >> data[k];
    }

    cout << "\nPROSES SORTIR" << endl;
    quickSort(data, 0, n - 1, n);

    cout << "\n--- HASIL AKHIR ---" << endl;
    cout << "Data Terurut: ";
    cetakArray(data, n);

    delete[] data;
    return 0;
}