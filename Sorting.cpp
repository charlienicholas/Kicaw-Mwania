#include <iostream>
using namespace std;

// Function Prototype
void tampilkanArray(int arr[], int n);
void inputData(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void inputEnter();
void enter();
void clear();



int main() {
    int pilihan, n;

    clear();

    // Menunya, akan looping selama user tidak pilih menu keluar
    do {
        cout << "\n--- MENU SORTING ---" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        cout << "Tekan enter untuk melanjutkan...";
        enter();

        if (pilihan >= 1 && pilihan <= 3) {
            cout << "Masukkan jumlah data: ";
            cin >> n;
            int arr[n]; // Deklarasi array untuk data dengan index berdasarkan jumlah yang diinginkan user
            
            inputData(arr, n); // Memanggil function untuk menginput data dengan mengirim parameter array data dan array jumlah data

            // Memanggil function sesuai metode sortin yang dipilih
            switch (pilihan) {
                case 1:
                    bubbleSort(arr, n); // Memanggil function untuk sorting dengan metode bubble sort dengan mengirim parameter array data dan array jumlah data
                    cout << "\nHasil Bubble Sort: ";
                    break;
                case 2:
                    selectionSort(arr, n); // Memanggil function untuk sorting dengan metode bubble sort dengan mengirim parameter array data dan array jumlah data
                    cout << "\nHasil Selection Sort: ";
                    break;
                case 3:
                    insertionSort(arr, n); // Memanggil function untuk sorting dengan metode bubble sort dengan mengirim parameter array data dan array jumlah data
                    cout << "\nHasil Insertion Sort: ";
                    break;
            }
            
            tampilkanArray(arr, n);
            cout << "-------------------------------" << endl;
            cout << "Tekan enter untuk kembali ke menu...";
            enter();

        } else if (pilihan != 4) {
            cout << "Pilihan tidak tersedia!" << endl;
        }

    } while (pilihan != 4);

    cout << "Program berhenti. Terima kasih!" << endl;
    return 0;
}


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
        cout << "Data ke " << i+1 << " = ";
        cin >> arr[i];
    }
    cout << endl;
}

// Function 1: Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // Perulangan dalam sekali putaran perbandingan
        cout << "Perulangan ke " << i+1 << endl; 
        for (int j = 0; j < n - i - 1; j++) { // Perulangan untuk perbandingan
            cout << "Perbandingan " << arr[j] << " vs " << arr[j+1] << " = ";
            if (arr[j] > arr[j + 1]) { // Membandingkan data dengan data di belakangnya
                cout << arr[j] << " > " << arr[j+1] << ", maka posisi " << arr[j] << " mundur ke belakang " << arr[j+1] << " => ";
                int temp = arr[j]; // Menyimpan data arr ke penyimpanan sementara agar arr dengan index tersebut kosong
                arr[j] = arr[j + 1]; // Memasukkan data index arr di belakang ke depannya
                arr[j + 1] = temp; // Memasukkan data dari penyimpanan sementara ke arr di belakang yang sudah kosong
            } else {
                cout << arr[j+1] << " > " << arr[j] << ", maka posisi tetap, " << arr[j+1] << " di belakang " << arr[j] << " => ";
            }
            for (int i = 0; i < n; i++) { // Menampilkan data
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Function 2: Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // Perulangan dalam sekali putaran perbandingan
        int minIdx = i; // variabel untuk menyimpan index data terkecil
        cout << "Perulangan ke " << i+1 << endl; 
        for (int j = i + 1; j < n; j++) { // Perulangan untuk perbandingan dalam menentukan data terkecil
            cout << "Perbandingan " << arr[minIdx] << " vs " << arr[j] << " = ";
            if (arr[j] < arr[minIdx]) {
                cout << arr[j] << " < " << arr[minIdx] << ", data terkecil = " << arr[j] << endl;
                minIdx = j;
            } else {
                cout << arr[minIdx] << " < " << arr[j] << ", data terkecil = " << arr[minIdx] << endl;
            }
        }
        int temp = arr[minIdx]; // Data dari array angka terkecil di pindahkan ke penyimpanan sementara
        arr[minIdx] = arr[i]; // Array data terkecil diberi data baru
        arr[i] = temp; // Data terkecil dari penyimpanan sementara di pindahkan ke data terdepan

        cout << "Hasil sorting sementara => ";
        for (int k = 0; k < n; k++) { // Menampilkan data
            cout << arr[k] << " ";
        }
        cout << endl << endl;
    }
}

// Function 3: Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Data yang sedang "dipegang"
        int j;

        // Perulangan mundur untuk mencari posisi yang pas buat 'key'
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j]; // Geser data ke kanan
        }

        arr[j + 1] = key; // Sisipkan 'key' di posisi yang ditemukan

        // Menampilkan proses per langkah
        cout << "Langkah ke-" << i << " (Key " << key << "): ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

// function untuk menerima enter
void inputEnter(){
    cin.ignore();
    cin.get();
} 

// function untuk menerima enter dan membersihkan layar
void enter(){
    inputEnter();
    clear();
}

// function untuk membersihkan layar console
void clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}