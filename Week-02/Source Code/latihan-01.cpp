#include <iostream>

using namespace std;

int main() {
    int matriksA[3][3], matriksB[3][3], hasil[3][3];
    cout << "=== PROGRAM MATRIKS 3x3 ===" << endl;
    
    cout << "\nMasukkan elemen Matriks A (3x3):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> matriksA[i][j];
        }
    }

    cout << "\nMasukkan elemen Matriks B (3x3):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> matriksB[i][j];
        }
    }

    cout << "\n--- Hasil Penjumlahan (A + B) ---" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = matriksA[i][j] + matriksB[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n--- Hasil Pengurangan (A - B) ---" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = matriksA[i][j] - matriksB[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n--- Hasil Perkalian (A * B) ---" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                hasil[i][j] += matriksA[i][k] * matriksB[k][j];
            }
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}