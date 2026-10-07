#include <iostream>
#include "nilai-mahasiswa.h"

using namespace std;

int main() {
    Mahasiswa mhs[10];
    int jumlahMhs = 0;
    
    cout << "Berapa data mahasiswa yang ingin dimasukkan (max 10)? : ";
    cin >> jumlahMhs;
    
    if(jumlahMhs > 10) jumlahMhs = 10;
    
    for(int i = 0; i < jumlahMhs; i++) {
        cout << "\nData Mahasiswa ke-" << i+1 << endl;
        inputMahasiswa(mhs[i]);
    }
    
    cout << "\n=============================================\n";
    cout << "             DATA NILAI MAHASISWA            \n";
    cout << "=============================================\n";
    
    for(int i = 0; i < jumlahMhs; i++) {
        tampilMahasiswa(mhs[i]);
    }
    
    return 0;
}