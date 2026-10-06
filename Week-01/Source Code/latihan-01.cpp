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