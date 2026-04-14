#include <iostream>
#include <iomanip>
using namespace std;

// fungsi Selection Sort
void SelectionSort(int Array[], int Size) {
    int i, j, kecil, temp;

    for (i = 0; i < Size - 1; i++) {
        kecil = i; // index 0

        cout << "kecil index = " << kecil << endl;
        
        cout << "Iterasi ke " << i+1 << endl;

        for (j = i + 1; j < Size; j++) {
            cout << "Perbandingan " <<  Array[kecil] << " vs " << Array[j] << endl;
            if (Array[kecil] > Array[j]) {
                kecil = j;
            }
            cout << "kecil index = " << kecil << endl;
            cout << "hasilnya = ";
            for (int i = 0; i < 3; i++) {
            cout << Array[i] << "  ";
            }
            cout << endl;
        }

        temp = Array[i];
        Array[i] = Array[kecil];
        Array[kecil] = temp;
        cout << endl << endl;
    }
}

// fungsi utama
int main() {
    int NumList[3] = {5, 3, 6};

    cout << "PENGURUTAN DENGAN SELECTION SORT\n";
    cout << "Data sebelum diurutkan:\n";

    for (int d = 0; d < 3; d++) {
        cout << setw(3) << NumList[d];
    }

    cout << "\n\n";

    SelectionSort(NumList, 3);

    cout << "Data setelah diurutkan:\n";

    for (int i = 0; i < 3; i++) {
        cout << setw(3) << NumList[i];
    }


    cout << endl;

    return 0;
}