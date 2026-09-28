# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Dadi Maulana Muhammad - 109082500080</p>

## Dasar Teori

Struktur data adalah cara penyimpanan, penyusunan, dan pengaturan data di dalam media penyimpanan komputer sehingga data tersebut dapat digunakan secara efisien [1]. Dalam dunia pemrograman, penggunaan struktur data yang tepat dapat meningkatkan performa eksekusi sebuah program, terutama ketika mengolah data dalam jumlah besar. Bahasa C++ sebagai salah satu bahasa pemrograman tingkat menengah (middle-level language) mendukung berbagai macam tipe data, operator, serta kontrol alur program yang memudahkan implementasi struktur data dasar [2].

### A. Integrated Development Environment (IDE) Code::Blocks<br/>

Code::Blocks adalah sebuah aplikasi Integrated Development Environment (IDE) yang bersifat open-source, bebas, dan cross-platform yang dirancang khusus untuk mendukung bahasa pemrograman C, C++, dan Fortran [1]. IDE ini menyediakan lingkungan kerja terpadu bagi programmer untuk menulis kode sumber, melakukan proses kompilasi (compilation), hingga menjalankan dan mencari kesalahan pada program (debugging) [2].

#### 1. Pembuatan Project Baru

Untuk memulai program C++ di Code::Blocks, langkah awal yang dilakukan adalah membuat Console Application melalui menu File > New > Project, kemudian memilih kompiler berbasis GCC/MinGW yang terintegrasi di dalamnya [1].

#### 2. Proses Kompilasi dan Eksekusi

Code::Blocks menyediakan beberapa fitur utama untuk menjalankan kode, di antaranya Build (Ctrl+F9) untuk menerjemahkan kode sumber menjadi bahasa mesin, Run (Ctrl+F10) untuk mengeksekusi file biner, serta Build and Run (F9) yang menggabungkan kedua proses tersebut secara otomatis [2].

#### 3. Manajemen File Sumber

Setiap kode program C++ disimpan dalam ekstensi file berformat .cpp yang di dalamnya mencakup penyertaan pustaka (library), fungsi utama main(), serta blok pernyataan logika program [1].

### B. Konsep Dasar Bahasa C++<br/>

Bahasa C++ merupakan pengembangan dari bahasa C yang mendukung paradigma pemrograman berorientasi objek (Object-Oriented Programming), namun tetap mempertahankan kemampuan pemrograman prosedural standar [2].

#### 1. Tipe Data dan Variabel

Variabel adalah wadah untuk menyimpan nilai di memori komputer, di mana setiap variabel harus dideklarasikan dengan tipe data tertentu seperti int (bilangan bulat), float / double (bilangan pecahan), dan char (karakter tunggal) [2].

#### 2. Operator Aritmatika dan Logika

C++ menyediakan berbagai operator untuk memanipulasi data, meliputi operator aritmatika (+, -, *, /, %), operator pembanding (==, !=, <, >), serta operator logika (&&, ||, !) yang digunakan dalam proses pengambilan keputusan [1].

#### 3. Percabangan dan Perulangan

Pengontrolan alur program (control flow) pada C++ diatur menggunakan struktur percabangan seperti if-else dan switch-case, serta struktur perulangan (looping) seperti for, while, dan do-while untuk mengeksekusi blok kode secara berulang [2].

## Unguided

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian
memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua
bilangan tersebut.

```C++
#include <iostream>

using namespace std;

int main() {
    float a, b;

    cout << "Bilangan pertama: ";
    cin >> a;
    cout << "Bilangan kedua: ";
    cin >> b;

    cout << "Penjumlahan: " << a << " + " << b << " = " << (a + b) << endl;
    cout << "Pengurangan: " << a << " - " << b << " = " << (a - b) << endl;
    cout << "Perkalian: " << a << " * " << b << " = " << (a * b) << endl;

    if (b != 0) {
        cout << "Pembagian: " << a << " / " << b << " = " << (a / b) << endl;
    } else {
        cout << "Pembagian: Tidak terdefinisi." << endl;
    }

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-01/Output/output-latihan-01-01.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-01/Output/output-latihan-01-02.png)

Program ini dirancang untuk menerima dua buah masukan angka pecahan (floating-point) dari pengguna [1]. Variabel dideklarasikan dengan tipe data float agar mampu menyimpan angka desimal [2]. Setelah nilai dimasukkan, program secara otomatis menghitung dan menampilkan hasil penjumlahan, pengurangan, perkalian, serta pembagian [1]. Khusus untuk operasi pembagian, disertakan struktur pengecekan kondisi if (b != 0) guna mencegah terjadinya error runtime akibat pembagian dengan angka nol [2].

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai
angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat
positif mulai dari 0 s.d 100

```C++
#include <iostream>

using namespace std;

int main() {
    int angka;
    
    cout << "Masukkan bilangan bulat 0 - 100: ";
    cin >> angka;
    
    if (angka < 0 || angka > 100) {
        cout << "Angka harus antara 0 s.d. 100!" << endl;
        return 0;
    }
    cout << angka << ": ";
    
    if (angka == 0) {
        cout << "nol";
    } else if (angka == 100) {
        cout << "seratus";
    } else if (angka >= 11 && angka <= 19) {
        switch (angka) {
            case 11: cout << "sebelas"; break;
            case 12: cout << "dua belas"; break;
            case 13: cout << "tiga belas"; break;
            case 14: cout << "empat belas"; break;
            case 15: cout << "lima belas"; break;
            case 16: cout << "enam belas"; break;
            case 17: cout << "tujuh belas"; break;
            case 18: cout << "delapan belas"; break;
            case 19: cout << "sembilan belas"; break;
        }
    } else {
        int puluhan = angka / 10;
        int satuan = angka % 10;
        
        switch (puluhan) {
            case 1: cout << "sepuluh"; break;
            case 2: cout << "dua puluh"; break;
            case 3: cout << "tiga puluh"; break;
            case 4: cout << "empat puluh"; break;
            case 5: cout << "lima puluh"; break;
            case 6: cout << "enam puluh"; break;
            case 7: cout << "tujuh puluh"; break;
            case 8: cout << "delapan puluh"; break;
            case 9: cout << "sembilan puluh"; break;
        }
        
        switch (satuan) {
            case 1: cout << " satu"; break;
            case 2: cout << " dua"; break;
            case 3: cout << " tiga"; break;
            case 4: cout << " empat"; break;
            case 5: cout << " lima"; break;
            case 6: cout << " enam"; break;
            case 7: cout << " tujuh"; break;
            case 8: cout << " delapan"; break;
            case 9: cout << " sembilan"; break;
        }
    }
    
    cout << endl;
    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-01/Output/output-latihan-02-01.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-01/Output/output-latihan-02-02.png)

Program ini berfungsi untuk menerjemahkan angka bilangan bulat positif dari rentang 0 hingga 100 menjadi bentuk tulisan kata-kata [1]. Validasi awal digunakan untuk memastikan input berada dalam batas yang diizinkan [2]. Logika program memecah angka menggunakan operator pembagian bulat (/) untuk mendapatkan digit puluhan dan operator sisa bagi / modulus (%) untuk mendapatkan digit satuan [1]. Struktur percabangan switch-case diterapkan secara efektif untuk memetakan nilai puluhan dan satuan ke dalam bentuk string terbilang secara akurat [2].

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>

using namespace std;

int main() {
    int n;
    
    cout << "Masukkan angka: ";
    cin >> n;
    
    cout << "Output:" << endl;
    for (int i = n; i >= 1; i--) {
        for (int s = 0; s < (n - i); s++) {
            cout << "  "; 
        }
        
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        
        cout << endl;
    }
    
    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*" << endl;
    
    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-01/Output/output-latihan-03-01.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-01/Output/output-latihan-03-02.png)

Program ketiga memanfaatkan konsep perulangan bersarang (nested loop) untuk mencetak pola angka simetris yang mengerucut ke bawah dengan posisi rata tengah (center alignment) [1]. Perulangan luar mengatur jumlah baris menurun dari angka input n hingga 1, sementara perulangan di dalam mengatur pencetakan spasi kiri, urutan angka menurun di sisi kiri, karakter bintang (*) sebagai pemisah di tengah, dan urutan angka menaik di sisi kanan [2]. Baris terakhir ditutup dengan mencetak simbol bintang tunggal yang diposisikan tepat di tengah-tengah pola [1].

## Kesimpulan

Berdasarkan praktikum Modul 1 mengenai Code::Blocks IDE dan Pengenalan Bahasa C++, dapat disimpulkan bahwa pemahaman terhadap lingkungan pengembangan perangkat lunak serta sintaks dasar bahasa C++ merupakan fondasi utama dalam mempelajari struktur data [1]. Penggunaan tipe data, operator aritmatika, struktur kontrol percabangan (if-else, switch-case), serta perulangan (looping) memungkinkan programmer untuk membangun logika program yang terstruktur, efisien, dan interaktif dalam menyelesaikan berbagai permasalahan komputasi [2].

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>