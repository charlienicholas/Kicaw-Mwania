#include <iostream>
using namespace std;

// Function untuk menampilkan isi array
void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function Input Data
void inputData(int arr[], int n) {
    cout << "Masukkan " << n << " angka: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Function 1: Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function 2: Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Function 3: Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int pilihan, n;

    // Menunya, akan looping selama user tidak pilih menu keluar
    do {
        cout << "\n--- MENU SORTING (FUNCTION) ---" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 3) {
            cout << "Masukkan jumlah data: ";
            cin >> n;
            int arr[n]; // Deklarasi array

            inputData(arr, n);

            // Memanggil function sesuai pilihan
            switch (pilihan) {
                case 1:
                    bubbleSort(arr, n);
                    cout << "\nHasil Bubble Sort: ";
                    break;
                case 2:
                    selectionSort(arr, n);
                    cout << "\nHasil Selection Sort: ";
                    break;
                case 3:
                    insertionSort(arr, n);
                    cout << "\nHasil Insertion Sort: ";
                    break;
            }
            
            tampilkanArray(arr, n);
            cout << "-------------------------------" << endl;

        } else if (pilihan != 4) {
            cout << "Pilihan tidak tersedia!" << endl;
        }

    } while (pilihan != 4);

    cout << "Program berhenti. Terima kasih!" << endl;
    return 0;
}