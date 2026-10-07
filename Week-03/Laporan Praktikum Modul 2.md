# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>

<p align="center">Dadi Maulana Muhammad - 109082500080</p>

## Dasar Teori

Dalam pemrograman, seringkali tipe data dasar bawaan (built-in) seperti int, float, atau char tidak cukup untuk merepresentasikan objek dunia nyata yang kompleks secara utuh. Untuk mengatasi hal tersebut, diperkenalkanlah konsep Abstract Data Type (ADT).

### A. Konsep Abstract Data Type (ADT)<br/>

Abstract Data Type (ADT) adalah definisi statik yang mencakup definisi TYPE (tipe data) beserta sekumpulan PRIMITIF (operasi dasar) yang dapat dilakukan terhadap tipe data tersebut. Dalam ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku.
Sebuah ADT dapat dibangun menggunakan tipe data dasar atau bahkan dapat disusun dari definisi ADT lainnya yang sudah ada (struktur nested). Dalam bahasa pemrograman C atau C++, TYPE dari ADT umumnya diterjemahkan menjadi struct, sementara PRIMITIF-nya diterjemahkan menjadi fungsi (function) atau prosedur (void). 

### B. Primitif pada ADT<br/>

Operasi dasar atau primitif pada ADT dikelompokkan ke dalam beberapa jenis fungsi dan prosedur, antara lain:

#### 1. Konstruktor/Kreator:

Berfungsi untuk membentuk nilai dari tipe tersebut, dan biasanya namanya diawali dengan kata Make atau Create.

#### 2. Selektor:

Digunakan untuk mengakses nilai dari komponen suatu tipe, di mana biasanya penamaannya diawali dengan kata Get.

#### 3. Prosedur Pengubah:

Digunakan untuk mengubah nilai dari komponen tertentu dalam struktur ADT (biasanya disebut mutator atau setter).

#### 4. Destruktor:

Bertugas untuk menghancurkan nilai objek beserta alokasi memorinya.

#### 5. Destruktor:

Meliputi prosedur Baca/Tulis untuk I/O, operator relasional, dan aritmatika terhadap tipe bentukan tersebut.

### C. Implementasi ADT<br/>

Implementasi ADT yang baik memisahkan definisi (struktur tipe dan header fungsi), realisasi (isi program fungsi), dan program utama pengguna (driver) ke dalam file yang berbeda.
Biasanya ADT diimplementasikan ke dalam 3 jenis file, yaitu:

#### 1. File Definisi/Spesifikasi (.h):

Memuat pendefinisian tipe (struct) dan deklarasi spesifikasi fungsi/prosedur yang akan digunakan.

#### 2. File Realisasi/Body (.cpp atau .c):

Berisi kode program aktual (implementasi) dari deklarasi primitif yang ada di file header. Realisasinya diwajibkan sebisa mungkin memanfaatkan selektor dan konstruktor.

#### 3. File Utama/Main (main.cpp):

Berfungsi sebagai program pemanggil (driver) yang hanya memuat logika utama sistem dengan melakukan #include terhadap file .h dari ADT.

## Guided

### 1. Program Data Mahasiswa Menggunakan Konsep ADT Sederhana

### mahasiswa.h
```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```
### mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim = ";
    cin >> m.nim;
    cout << "input nilai1 = ";
    cin >> m.nilai1;
    cout << "input nilai2 = ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2;
}
```

### main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}
```

### Output Guided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-03/Output/output-guided-01-01.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-03/Output/output-guided-01-02.png)

Pada guided ini diilustrasikan penerapan ADT dengan memisahkannya menjadi 3 modul file. Pertama, spesifikasi struktur data mahasiswa dan purwarupa fungsi inputMhs serta rata2 dibuat pada file header mahasiswa.h. Kedua, badan (body) dari fungsi tersebut dimuat dan dijabarkan pada mahasiswa.cpp yang menyertakan referensi file headernya. Terakhir, file main.cpp hanya bertugas mendeklarasikan variabel bertipe mahasiswa, kemudian mengeksekusi operasi tersebut melalui pemanggilan fungsi tanpa perlu mencampurnya dengan sintaks deklarasi kompleks.

## Unguided

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3uts+0.4uas+0.3*tugas.

### nilai-mahasiswa.h
```C++
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
```

### nilai-mahasiswa.cpp
```C++
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
```

### main.cpp
```C++
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
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-03/Output/output-latihan-01-01.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-03/Output/output-latihan-01-02.png)

Program ini mendemonstrasikan implementasi gabungan antara Abstract Data Type (Tipe data bentukan struct), array satu dimensi, dan implementasi fungsi. Tipe data Mahasiswa dibuat untuk menyatukan beragam atribut mahasiswa. Nilai nilaiAkhir diolah secara modular lewat fungsi hitungNilaiAkhir menggunakan rumus persentase yang disediakan pada soal, kemudian hasilnya diisikan kembali ke dalam komponen field struct array pada perulangan input.

### 2. Buatlah ADT pelajaran di dalam file pelajaran.h, implementasi ADT di pelajaran.cpp, dan dicoba di main.cpp sesuai soal Latihan 2.

### pelajaran.h
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
#include <string>

using namespace std;

struct pelajaran {
    string namamapel;
    string kodemapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```
### mahasiswa.cpp
```C++
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
```

### main.cpp
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    
    pelajaran pel = create_pelajaran(namapel, kodepel);
    
    tampil_pelajaran(pel);
    
    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-03/Output/output-latihan-02-01.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-03/Output/output-latihan-02-02.png)

Program ini mendemonstrasikan secara murni kaidah pembuatan ADT di bahasa C++ menggunakan pemisahan file modular (Header, Body, Driver). Fungsi primitif create_pelajaran bertindak sebagai kreator/konstruktor (sebuah operasi dasar pembentuk nilai tipe yang diatur dalam ADT). File main.cpp tidak lagi mengetahui kerumitan logika assigning (penugasan nilai); ia hanya mengoperasikan primitif fungsi dan tipe struktur saja.

### 3. Buatlah program dengan ketentuan: 2 array 2D, 2 pointer, fungsi tampil isi array, fungsi penukaran 2 array pada posisi tertentu, dan prosedur pertukaran isi pointer.

### array-operasi.h
```C++
#ifndef ARRAY-OPERASI_H_INCLUDED
#define ARRAY-OPERASI_H_INCLUDED
#include <string>

using namespace std;

void tampilArray2D(int arr[3][3], string namaArray);
void tukarIsiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom);
void tukarIsiPointer(int *ptr1, int *ptr2);

#endif
```

### array-operasi.cpp
```C++
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
```

### main.cpp
```C++
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
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-latihan-03-01.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-latihan-03-02.png)

Program ini mendemonstrasikan implementasi penggunaan array 2 dimensi, pemanfaatan pointer, serta prosedur pada bahasa C++. Sebuah prosedur digunakan untuk menampilkan matriks 3x3 ke layar secara dinamis dengan nama array sebagai string. Prosedur tukarIsiArray mengakses alamat matriks array dan mengubah nilainya berdasarkan indeks baris dan kolom yang dimasukkan. Di bagian bawah main, dua buah variabel dideklarasikan dan ditunjuk oleh variabel pointer. Nilai dereference (nilai asli dari pointer) kemudian ditukar menggunakan operasi prosedur berparameter pointer (Call by Pointer).

## Kesimpulan

Dari praktikum Modul 3, dapat disimpulkan bahwa Abstract Data Type (ADT) adalah mekanisme fundamental dalam bahasa pemrograman yang sangat membantu dalam pengkategorian struktur data. Penggunaan ADT menyatukan tipe/atribut (struct) dan fungsi perlakuan (primitif) sehingga suatu objek yang kompleks bisa direpresentasikan dengan lebih logis. Pemisahan kode program (Header, Body, dan Driver) secara modular juga memberikan manfaat besar berupa kode yang lebih tertata rapi, perlindungan data tersembunyi (encapsulation), dan kemudahan perbaikan (debugging) dalam rekayasa perangkat lunak skala besar.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>