#include <iostream>
#include "array-operasi.h"

using namespace std;

void tampilArray2D(int arr[3][3], string namaArray) {
    cout << "\nIsi " << namaArray << " :" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarIsiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
    cout << "\n-> Elemen di baris " << baris << ", kolom " << kolom << " berhasil ditukar!" << endl;
}

void tukarIsiPointer(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    cout << "\n-> Isi variabel yang ditunjuk pointer berhasil ditukar!" << endl;
}