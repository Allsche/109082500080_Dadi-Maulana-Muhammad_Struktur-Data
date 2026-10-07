#include <iostream>
#include "nilai-mahasiswa.h"

using namespace std;

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void inputMahasiswa(Mahasiswa &m) {
    cout << "Masukkan Nama : ";
    cin.ignore();
    getline(cin, m.nama);
    cout << "Masukkan NIM  : ";
    cin >> m.nim;
    cout << "Nilai UTS     : ";
    cin >> m.uts;
    cout << "Nilai UAS     : ";
    cin >> m.uas;
    cout << "Nilai Tugas   : ";
    cin >> m.tugas;
    
    m.nilaiAkhir = hitungNilaiAkhir(m.uts, m.uas, m.tugas);
}

void tampilMahasiswa(Mahasiswa m) {
    cout << "Nama        : " << m.nama << endl;
    cout << "NIM         : " << m.nim << endl;
    cout << "Nilai Akhir : " << m.nilaiAkhir << endl;
    cout << "---------------------------------------------\n";
}