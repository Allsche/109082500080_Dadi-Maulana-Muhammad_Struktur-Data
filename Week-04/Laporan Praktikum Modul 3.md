# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>

<p align="center">Dadi Maulana Muhammad - 109082500080</p>

## Dasar Teori

Linked List (senarai berantai) adalah struktur data yang berisi sekumpulan elemen data yang saling terkait dan bersifat dinamis, sehingga ukurannya dapat bertambah atau menyusut sesuai dengan kebutuhan memori program.

### A. Konsep Linked List dengan Pointer<br/>

Implementasi Linked List yang paling efektif adalah menggunakan pointer. Hal ini dikarenakan:
    1. Sifat Linked List yang bentuk datanya saling bergandengan sangat cocok dikelola menggunakan pointer yang fleksibel.
    2. Berbeda dengan array yang bersifat statis (jumlah elemen maksimalnya ditetapkan di awal), pointer bersifat dinamis sehingga efisien dalam menangani penambahan atau penghapusan elemen secara run-time.
Elemen pada linked list dapat menyimpan data tunggal (seperti sebuah variabel string) maupun data majemuk/record (seperti struct data mahasiswa yang terdiri dari nama, NIM, dan alamat).  

### B. Singly Linked List<br/>

Singly Linked List adalah salah satu varian Linked List yang hanya memiliki satu arah panah pointer penunjuk ke elemen selanjutnya.
Komponen utama dari setiap elemen (node) pada Singly Linked List meliputi:
    > Data: Bagian yang berisi informasi utama dari elemen tersebut.
    > Successor (next): Pointer penghubung yang menunjuk ke alamat memori elemen berikutnya.
    Karakteristik Singly Linked List antara lain:
    > Hanya membutuhkan satu buah pointer (next) per elemen.
    > Hanya dapat ditelusuri atau dibaca dengan arah maju (forward).
    > Pointer elemen terakhir (node akhir) selalu menunjuk ke NULL atau Nil (kecuali pada circular list).
    > Memiliki pointer utama yang disebut first atau head yang selalu menunjuk ke alamat elemen pertama di dalam senarai.

### C. Operasi Dasar Singly Linked List<br/>

Singly Linked List diimplementasikan melalui pendekatan Abstract Data Type (ADT) dengan berbagai macam fungsi primitif: 
    1. Create List: Fungsi createList() digunakan untuk menciptakan senarai baru dengan mengatur pointer first menjadi NULL atau kosong.
    2. Alokasi & Dealokasi: Alokasi adalah proses memesan memori di sistem untuk elemen baru (menggunakan new di C++), sedangkan Dealokasi menggunakan sintaks delete untuk menghapusnya dan membebaskan memori.
    3. Insert (Penyisipan):
        > Insert First: Menyisipkan elemen baru di awal/depan senarai, lalu pointer first dipindah ke elemen tersebut.
        > Insert Last: Menyisipkan elemen baru di posisi paling akhir senarai, di mana pointer next dari elemen terakhir sebelumnya disambungkan ke elemen baru ini.
        > Insert After: Menyisipkan elemen baru tepat setelah (after) suatu elemen yang posisinya telah ditentukan oleh user.
    4. Delete (Penghapusan):
        > Delete First: Menghapus elemen paling depan dan memindahkan pointer first ke elemen kedua, kemudian mendealokasikan memori elemen pertama.
        > Delete Last: Menghapus elemen di ujung akhir list.   
        > Delete After: Menghapus sebuah elemen yang berada tepat setelah node referensi tertentu.
    5. View (Tampil): Melakukan perulangan/penelusuran dari first sampai NULL untuk mencetak seluruh info data pada setiap node.
    6. Update: Proses modifikasi atau pengubahan isi data dari sebuah node tertentu, yang biasanya didahului dengan operasi pencarian (searching). 

## Guided

### 1. Header list
```C++
#ifndef List_h
#define List_h
#define Nil nullptr

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedList
{
    address first;
};

bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi (string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);
#endif
```

Berkas header list.h bertugas menyimpan seluruh deklarasi dari fungsi maupun struktur data yang akan menyusun Singly Linked List. Pada file ini, didefinisikan sebuah struct mahasiswa guna menampung informasi umur, NIM, dan nama, sekaligus struct node yang menyimpan tipe bentukan mahasiswa tersebut beserta pointer penunjuk node penerusnya. Selain itu, header ini juga memuat berbagai purwarupa fungsi operasional seperti prosedur untuk mencetak data, menghapus, menyisipkan, menghitung total node, hingga menciptakan senarai baru

### 2. Code utama List
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List)
{
    if (List.first == Nil){
        return true;
    }else{
        return false;
    }
}

void createList(linkedList &List)
{
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &list, address nodeBaru)
{
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedList &list, address nodeBaru, address prev)
{
    if (prev != Nil)
    {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    }else{
        cout<< "Node sebelumnya tidak valid"<< endl;
    }
}

void insertLast(linkedList &list, address nodeBaru)
{
    if (isEmpty(list))
    {
        list.first = nodeBaru;
    }else
    {
        address nodeBantu = list.first;
        while(nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedList &list)
{
    address nodeHapus;
    if (isEmpty(list) == false)
    {
        nodeHapus = list.first;
        list.first = list.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }else
    {
        cout<<"List Kosong" << endl;
    }
}

void delLast(linkedList &list)
{
    address nodeHapus, nodePrev;
    if (isEmpty(list) == false)
    {
        nodeHapus = list.first; 
        if(nodeHapus->next == Nil)
        {
            list.first->next = Nil;
            dealokasi(nodeHapus);
        }else
        {
            while(nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }else
    {
        cout<<"List kosong"<< endl;
    }
}

void delAfter(linkedList &list, address nodeHapus, address nodePrev)
{
    if(isEmpty(list) == true)
    {
        cout<< "List kosong"<<endl;
    }else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }else
        {
            cout<<"Node sebelumnya (prev) tidak valid"<< endl;
        }
    }
}

void printList(linkedList list)
{
    if(isEmpty(list))
    {
        cout<< "List kosong." << endl;
    }else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}


int nbList(linkedList list)
{
    int count = 0;
    address nodeBantu = list.first;
    while(nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedList &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;

    while(nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout<< "List sudah terhapus"<< endl;
}
```

File list.cpp merupakan tempat di mana seluruh fungsi dan prosedur yang telah dideklarasikan sebelumnya direalisasikan secara konkret. Tiap fungsi dijabarkan logikanya sesuai dengan tujuannya, seperti mengalokasikan ruang memori bagi node yang baru dibuat, mendeteksi status kekosongan list, memanipulasi penambahan atau penghapusan elemen, hingga proses mencetak informasi mahasiswa ke layar. Modul ini pada intinya mengelola aliran pointer antar-elemen agar keseluruhan data dapat tertata dengan baik di dalam senarai.

### 3. Main list
```C++
#include "list.h"
using namespace std;

int main()
{
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "221110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
}
```

Berkas main.cpp bertindak sebagai program penggerak yang menguji coba implementasi fungsi linked list. Langkah awalnya adalah membentuk sebuah list kosong, dilanjutkan dengan tahap pengalokasian lima buah node yang masing-masing menyimpan identitas mahasiswa. Kelima data ini lalu disisipkan ke dalam senarai menggunakan metode insertLast, insertAfter, dan insertFirst. Selanjutnya, sistem akan mencetak isi senarai beserta total elemennya, sebelum akhirnya memanggil fungsi delFirst guna mengeliminasi node terdepan.

## Unguided

### 1. Program Singly Linked List Data Tunggal Berbasis ADT Modular Header singlylist

### Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED
#include <iostream>

#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif
```
### Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
```

### main.cpp
```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Allsche/109082500080_Dadi-Maulana-Muhammad_Struktur-Data/blob/main/Week-04/Output/output-latihan-01-01.png)

Praktikum guided ini menerapkan model Singly Linked List secara utuh menggunakan pendekatan modular (Header, Body, Main).
Pada Singlylist.h dideklarasikan struktur elmlist yang memuat dua bagian: info sebagai penampung nilai integer dan next sebagai pointer ke node selanjutnya.
Pada Singlylist.cpp, fungsi alokasi memanfaatkan operator new C++ untuk memesan blok memori untuk elemen list baru. Prosedur insertFirst bekerja dengan cara menyambungkan panah elemen baru ke elemen awal, lalu mengganti pointer kepala (first) agar menunjuk elemen baru tersebut.
Pada main.cpp, 5 buah elemen dialokasikan dan dimasukkan berturut-turut ke awal list, sehingga nilai yang diinputkan terakhir (yaitu angka 9) akan muncul di urutan terdepan (konsep LIFO). Sesuai dengan hasil keluaran yang ditampilkan di modul, output dari program ini adalah deret angka 9 12 8 0 2.

## Kesimpulan

Berdasarkan praktikum pada Modul 4, dapat disimpulkan bahwa Singly Linked List adalah metode pengorganisasian data yang jauh lebih fleksibel dibandingkan tipe array konvensional. Melalui pemanfaatan pointer (address), alokasi memori (node) dapat ditambahkan atau dikurangi kapan saja di tengah berjalannya program tanpa terikat kapasitas maksimal. Mekanisme satu arah panah ini mendasari operasi penting primitif Linked List, mulai dari pembentukan list kosong, penyisipan elemen dari berbagai arah (Depan, Belakang, Setelah node tertentu), hingga proses penghapusan elemen dari sistem agar memori tidak terbuang sia-sia.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>