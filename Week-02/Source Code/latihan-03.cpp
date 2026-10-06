#include <iostream>

using namespace std;

int cariMin(int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int cariMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void cariRataRata(int arr[], int size, float &hasilRata) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    hasilRata = (float)sum / size;
}

int main() {
    int arrA[] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};
    int ukuran = sizeof(arrA) / sizeof(arrA[0]);
    int pilihan;
    float rata_rata = 0;

    do {
        cout << "\n=== MENU OPERASI ARRAY ===" << endl;
        cout << "Array: {48, 2, 7, 21, 5, 20, 77, 9, 10, 1}" << endl;
        cout << "1. Cari Nilai Minimum" << endl;
        cout << "2. Cari Nilai Maksimum" << endl;
        cout << "3. Cari Nilai Rata-Rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "--> Nilai Minimum dari array adalah: " << cariMin(arrA, ukuran) << endl;
                break;
            case 2:
                cout << "--> Nilai Maksimum dari array adalah: " << cariMax(arrA, ukuran) << endl;
                break;
            case 3:
                cariRataRata(arrA, ukuran, rata_rata);
                cout << "--> Nilai Rata-rata dari array adalah: " << rata_rata << endl;
                break;
            case 0:
                cout << "Terima kasih, keluar dari program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}