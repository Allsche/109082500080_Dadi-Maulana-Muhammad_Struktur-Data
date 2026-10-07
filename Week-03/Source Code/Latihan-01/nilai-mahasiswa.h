#ifndef NILAI-MAHASISWA_H_INCLUDED
#define NILAI-MAHASISWA_H_INCLUDED
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas);
void inputMahasiswa(Mahasiswa &m);
void tampilMahasiswa(Mahasiswa m);

#endif 