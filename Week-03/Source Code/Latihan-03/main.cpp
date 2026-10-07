#include <iostream>
#include "array-operasi.h"

using namespace std;

int main() {
    int arrayA[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int arrayB[3][3] = { {10,11,12}, {13,14,15}, {16,17,18} };
    
    cout << "=== KONDISI AWAL ===" << endl;
    tampilArray2D(arrayA, "Array A");
    tampilArray2D(arrayB, "Array B");
    
    tukarIsiArray(arrayA, arrayB, 1, 1);
    
    cout << "\n=== SETELAH PERTUKARAN ARRAY (Baris 1 Kolom 1) ===" << endl;
    tampilArray2D(arrayA, "Array A");
    tampilArray2D(arrayB, "Array B");

    int val1 = 99;
    int val2 = 88;
    int *p1 = &val1;
    int *p2 = &val2;

    cout << "\n=== SEBELUM TUKAR POINTER ===" << endl;
    cout << "Nilai Pointer 1: " << *p1 << " | Nilai Pointer 2: " << *p2 << endl;
    
    tukarIsiPointer(p1, p2);
    
    cout << "\n=== SETELAH TUKAR POINTER ===" << endl;
    cout << "Nilai Pointer 1: " << *p1 << " | Nilai Pointer 2: " << *p2 << endl;

    return 0;
}