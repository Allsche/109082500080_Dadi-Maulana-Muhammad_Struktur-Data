# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>

<p align="center">Dadi Maulana Muhammad - 109082500080</p>

## Dasar Teori

Struktur data dalam bahasa C++ memiliki beberapa elemen penting untuk mengelola memori dan alur program secara efisien, di antaranya adalah penggunaan Array, Pointer, serta Fungsi dan Prosedur.

### A. Array<br/>

Array merupakan kumpulan data dengan nama yang sama dan setiap elemen bertipe data sama. Array digunakan untuk menyimpan data dalam memori pada lokasi yang berurutan, di mana elemen pertama selalu memiliki indeks 0.

#### 1. Array Satu Dimensi

Array satu dimensi adalah array yang hanya terdiri dari satu larik data saja. Pendeklarasian array satu dimensi dilakukan dengan format tipe_data nama_var [ukuran], yang menyatakan jenis elemen dan jumlah maksimum elemen array.

#### 2. Array Dua Dimensi

Bentuk array dua dimensi mirip seperti tabel, sehingga sering digunakan untuk menyimpan data baris dan kolom. Array ini terbagi menjadi dimensi pertama dan dimensi kedua, dengan cara akses yang membutuhkan dua buah indeks.

#### 3. Array Berdimensi Banyak

Array berdimensi banyak mempunyai indeks lebih dari dua yang menyatakan jumlah dimensinya. Implementasi array berdimensi banyak sering digunakan untuk penyimpanan bentuk data yang rumit dan kompleks.

### B. Pointer dan Alamat Memori<br/>

Setiap variabel yang dibuat akan dialokasikan oleh Sistem Operasi pada cell memori (RAM) yang memiliki indeks atau alamat unik (address).

#### 1. Konsep Alamat Memori

Untuk mengetahui alamat memori tempat suatu variabel dialokasikan, digunakan operator address-of (&) yang ditempatkan di depan nama variabel.

#### 2. Pointer

Variabel pointer merupakan tipe variabel yang berisi integer dalam format heksadesimal dan berfungsi untuk menyimpan alamat memori variabel lain. Untuk mendapatkan nilai dari variabel yang alamatnya ditunjuk oleh pointer, digunakan operator dereference (*) di depan nama variabel pointer tersebut.

#### 3. Pointer pada Array dan String

Terdapat keterhubungan kuat antara pointer dan array; nama array tanpa indeks (misal a) pada dasarnya merupakan pointer yang menunjuk ke elemen ke-0 dari array tersebut (&a[0]). Pada String (yang merupakan array karakter yang diakhiri \0), pointer dapat digunakan untuk mengakses deretan karakter tersebut secara berurutan.

### C. Fungsi dan Prosedur<br/>

Fungsi dan prosedur merangkum blok kode untuk melaksanakan tugas khusus, sehingga program menjadi lebih terstruktur, mudah dikembangkan, dan mengurangi duplikasi kode.

#### 1. Fungsi

Fungsi memerlukan masukan (parameter) dan akan mengolah masukan tersebut untuk mengembalikan sebuah nilai (return value) ke pemanggilnya.

#### 2. Prosedur

Dalam C++, prosedur adalah fungsi bertipe void yang berarti fungsi tersebut tidak mengembalikan nilai balik (return value).

#### 3. Parameter (Value, Pointer, Reference)

Parameter yang dikirimkan ke dalam fungsi dapat berupa Call by Value (menyalin nilai, variabel asli tidak berubah), Call by Pointer (melewatkan alamat memori dengan pointer sehingga nilai variabel asli dapat diubah), atau Call by Reference (melewatkan referensi variabel menggunakan & pada parameter formal).

## Guided

### 1. Penggunaan Dasar Pointer

```C++
#include <iostream>
using namespace std;

int main() {
    int x, y;
    int *px;
    
    x = 87;
    px = &x;
    y = *px;
    
    cout << "Alamat x= " << &x << endl;
    cout << "Isi px= " << px << endl;
    cout << "Isi X= " << x << endl;
    cout << "Nilai yang ditunjuk px= " << *px << endl;
    cout << "Nilai y= " << y << endl;
    
    return 0;
}
```

### Output Guided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-guided-01-01.png)

Program ini mendemonstrasikan cara kerja pointer dan alamat memori. Variabel px menyimpan alamat dari x menggunakan perintah px = &x;. Variabel y kemudian diisi dengan nilai yang ditunjuk oleh px menggunakan perintah y = *px;, sehingga y memiliki nilai yang sama dengan x yaitu 87.

### 2. Implementasi Array 1 Dimensi dan 2 Dimensi

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai[MAX];
    static int nilai_tahun[MAX][MAX] = {
        {0,2,2,0,0},
        {0,1,1,1,0},
        {4,4,0,0,4},
        {0,3,3,3,0},
        {5,0,0,0,5}
    };
    
    for (i = 0; i < MAX; i++) {
        cout << "masukkan nilai ke-" << i+1 << endl;
        cin >> nilai[i];
    }
    
    cout << "\ndata nilai siswa : \n";
    for (i = 0; i < MAX; i++) {
        cout << "nilai ke-" << i+1 << " = " << nilai[i] << endl;
    }
    
    cout << "\n nilai tahunan: \n";
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            cout << nilai_tahun[i][j];
        }
        cout << "\n";
    }
    return 0;
}
```

### Output Guided 2 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-guided-02-01.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-guided-02-02.png)

Program ini menggabungkan penggunaan array satu dimensi (nilai) yang diisi secara dinamis oleh pengguna, dan array dua dimensi (nilai_tahun) yang diinisialisasi secara statis layaknya matriks atau tabel. Perulangan bersarang (for di dalam for) digunakan untuk mencetak isi dari array dua dimensi secara berbaris.

### 3. Implementasi Array 1 Dimensi dan 2 Dimensi

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c);

int main() {
    int x, y, z;
    cout << "masukkan nilai bilangan ke-1 = ";
    cin >> x;
    cout << "masukkan nilai bilangan ke-2 = ";
    cin >> y;
    cout << "masukkan nilai bilangan ke-3 = ";
    cin >> z;
    
    cout << "nilai maksimumnya adalah = " << maks3(x, y, z);
    return 0;
}

int maks3(int a, int b, int c) {
    int temp_max = a;
    if (b > temp_max)
        temp_max = b;
    if (c > temp_max)
        temp_max = c;
    return (temp_max);
}
```

### Output Guided 3 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-guided-03-01.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-guided-03-02.png)

Program ini memanfaatkan fungsi maks3 yang memiliki tipe kembalian (return type) int untuk mencari nilai terbesar dari tiga buah bilangan. Fungsi dipanggil pada fungsi utama main() dengan melewatkan parameter aktual x, y, z ke dalam parameter formal a, b, c menggunakan mekanisme Call by Value.

### 4. Implementasi Array 1 Dimensi dan 2 Dimensi

```C++
#include <iostream>
using namespace std;

void tulis (int x);

int main()
{
    int jum;
    cout << " jumlah baris kata=";
    cin >> jum;
    tulis (jum);
    return 0;
}

void tulis (int x) {
    for (int i=0;i<x;i++) {
        cout<<"baris ke-"<<i+1<<endl;
    }
}
```

### Output Guided 4 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-guided-04-01.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-guided-04-02.png)

Program ini mendemonstrasikan pembuatan sebuah prosedur menggunakan tipe data void. Prosedur tulis menerima satu masukan parameter bilangan bulat x dan mencetak kalimat sebanyak angka masukan tersebut. Tidak ada nilai kembalian pada baris terakhir fungsi prosedur ini.

### 5. Cara Melewatkan Parameter

### Call by Value
```C++
#include <iostream>
using namespace std;

void tukar (int x, int y);

int main () {
    int a, b; a=4; b=6;
    cout << "kondisi sebelum ditukar \n";
    cout <<"a= "<<a<<" b = "<<b<<endl;
    
    tukar (a,b);
    
    cout<<"kondisi setelah ditukar \n";
    cout <<"a= "<<a<<" b = "<<b<<endl;
    return 0;
}

void tukar (int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout << "nilai akhir pada fungsi tukar \n";
    cout << " x = "<<x<<" y = "<<y<<endl;
}
```

### Call by Reference
```C++
#include <iostream>
using namespace std;

void tukar (int &x, int &y);

int main () {
    int a, b;
    a=4; b=6;
    cout << "kondisi sebelum ditukar \n";
    cout << " a = "<<a<<" b = "<<b<<endl;
    
    tukar (a,b);
    
    cout<<"kondisi setelah ditukar \n";
    cout <<"a= "<<a<<" b = "<<b<<endl;
    return 0;
}

void tukar (int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout<< "nilai akhir pada fungsi tukar \n";
    cout << " x = "<<x<<" y = "<<y<<endl;
}
```

### Call by Pointer
```C++
#include <iostream>
using namespace std;

void tukar (int *x, int *y);

int main () {
    int a, b; a=4; b=6;
    cout << "kondisi sebelum ditukar \n";
    cout << "a = "<<a<<" b = "<<b<<endl;
    
    tukar (&a,&b);
    
    cout<<"kondisi setelah ditukar \n";
    cout <<"a= "<<a<<" b = "<<b<<endl;
    return 0;
}

void tukar (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    cout << "nilai akhir pada fungsi tukar \n";
    cout << " x = "<<*x<<" y = "<<*y<<endl;
}
```

### Output Guided 5 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-guided-05-a.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-guided-05-b.png)

##### Output 3

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-guided-05-c.png)

Bagian ini membandingkan ketiga jenis passing parameter.
Pada Call by Value, nilai parameter asli tidak berubah karena hanya nilainya yang disalin ke parameter formal.
Pada Call by Reference, perubahan terjadi secara permanen karena argumen fungsi menggunakan referensi parameter awal &.
Pada Call by Pointer, fungsi menerima pointer (address) sebagai masukan, yang kemudian di-dereference * sehingga dapat memanipulasi variabel asal secara langsung. 

## Unguided

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3.

```C++
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
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-latihan-01-01.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-latihan-01-02.png)

Program ini mendemonstrasikan pemanfaatan array dua dimensi untuk memodelkan matriks 3x3. Data diinputkan menggunakan perulangan for bersarang. Untuk penjumlahan dan pengurangan, setiap elemen diproses sesuai indeks baris dan kolom yang sama. Untuk perkalian matriks, ditambahkan satu perulangan bersarang lagi (variabel k) guna mengalikan baris pada matriks A dengan kolom pada matriks B sesuai prinsip aljabar linear.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.

```C++
#include <iostream>

using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 10, y = 20, z = 30;

    cout << "=== Program Tukar 3 Variabel ===" << endl;
    cout << "Nilai Awal:" << endl;
    cout << "x = " << x << " | y = " << y << " | z = " << z << endl;

    tukarPointer(&x, &y, &z);
    cout << "\nSetelah ditukar dengan Pointer:" << endl;
    cout << "x = " << x << " | y = " << y << " | z = " << z << endl;

    x = 10; y = 20; z = 30;

    tukarReference(x, y, z);
    cout << "\nSetelah ditukar dengan Reference:" << endl;
    cout << "x = " << x << " | y = " << y << " | z = " << z << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-latihan-02-01.png)

Program ini mengembangkan logika swap yang ada di bagian guided untuk menukar nilai 3 variabel secara melingkar (nilai a pindah ke b, b ke c, dan c kembali ke a). Metode Call by Pointer dikirimkan menggunakan alamat memori (&) dan diakses dengan dereference (*). Sedangkan Call by Reference langsung di-passing nama variabelnya, namun di dalam deklarasi parameter fungsi digunakan address-of (&) agar langsung memodifikasi variabel asli di memori.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {48, 2, 7 , 21, 5, 20, 77, 9, 10, 1} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut!

```C++
#include <iostream>

using namespace std;

int cariMin(int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int cariMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void cariRataRata(int arr[], int size, float &hasilRata) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    hasilRata = (float)sum / size;
}

int main() {
    int arrA[] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};
    int ukuran = sizeof(arrA) / sizeof(arrA[0]);
    int pilihan;
    float rata_rata = 0;

    do {
        cout << "\n=== MENU OPERASI ARRAY ===" << endl;
        cout << "Array: {48, 2, 7, 21, 5, 20, 77, 9, 10, 1}" << endl;
        cout << "1. Cari Nilai Minimum" << endl;
        cout << "2. Cari Nilai Maksimum" << endl;
        cout << "3. Cari Nilai Rata-Rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "--> Nilai Minimum dari array adalah: " << cariMin(arrA, ukuran) << endl;
                break;
            case 2:
                cout << "--> Nilai Maksimum dari array adalah: " << cariMax(arrA, ukuran) << endl;
                break;
            case 3:
                cariRataRata(arrA, ukuran, rata_rata);
                cout << "--> Nilai Rata-rata dari array adalah: " << rata_rata << endl;
                break;
            case 0:
                cout << "Terima kasih, keluar dari program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-latihan-03-01.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-02/Output/output-latihan-03-02.png)

Program ini dirangkum menggunakan perulangan do-while dan struktur switch-case untuk menciptakan Menu Navigasi Sederhana. Untuk fitur maksimum dan minimum, dibuat menggunakan Function bertipe int yang me-return atau mengembalikan nilai dan langsung dipanggil di dalam perintah cout. Sementara untuk fitur rata-rata, digunakan Procedure bertipe void yang mengkalkulasi hasil lalu memodifikasinya menggunakan mekanisme Pass by Reference (float &hasilRata), sehingga hasil modifikasi variabel memori dapat langsung dicetak di dalam fungsi main().

## Kesimpulan

Berdasarkan praktikum Modul 2, dapat disimpulkan bahwa pengelolaan struktur data yang lebih dinamis di dalam C++ sangat bergantung pada pemahaman kita terhadap tiga komponen krusial: Array, Pointer, serta Fungsi dan Prosedur. Array memungkinkan penyimpanan kumpulan data secara terurut. Penggunaan Pointer membuka akses manipulasi data langsung pada alamat memori komputer, yang sangat vital untuk mengefisienkan alokasi memori program. Di sisi lain, memecah program besar ke dalam sub-program seperti Fungsi (dengan nilai kembalian) dan Prosedur (tanpa nilai kembalian) akan meningkatkan keterbacaan kode (readability), menghindari redundansi, dan memudahkan debugging.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>