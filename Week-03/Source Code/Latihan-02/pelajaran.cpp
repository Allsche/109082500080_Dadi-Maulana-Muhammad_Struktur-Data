#include <iostream>
#include "pelajaran.h"

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pelBaru;
    pelBaru.namamapel = namapel;
    pelBaru.kodemapel = kodepel;
    return pelBaru;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namamapel << endl;
    cout << "nilai          : " << pel.kodemapel << endl;
}