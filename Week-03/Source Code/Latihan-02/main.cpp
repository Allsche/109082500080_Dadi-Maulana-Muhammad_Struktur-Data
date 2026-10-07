#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Kalkulus";
    string kodepel = "Cal";
    
    pelajaran pel = create_pelajaran(namapel, kodepel);
    
    tampil_pelajaran(pel);
    
    return 0;
}