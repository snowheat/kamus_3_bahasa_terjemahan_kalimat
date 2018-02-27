//
// Created by insan on 2/22/2018.
//

#include <iostream>
#include "Kamus.h"

using namespace std;

Kamus::Kamus() {

}

void Kamus::buka() {
    tampilkanMenu();
}

void Kamus::tampilkanMenu() {
    cout << "===========================================================" << endl;
    cout << "|                                                         |" << endl;
    cout << "|            KAMUS SILIWANGI [SAEUTIK GE MAHI]            |" << endl;
    cout << "|                                                         |" << endl;
    cout << "===========================================================" << endl;
    cout << "1. Terjemahkan" << endl;
    cout << "2. Tambah kata" << endl;
    cout << "3. Ubah kata" << endl;
    cout << "4. Hapus kata" << endl;
    cout << "5. Tampilkan struktur kamus" << endl;
    cout << "PILIH : ";
    cin >> nomorMenu;
    //cout << "Nomor Menu " << nomorMenu << endl;
    eksekusiMenu(nomorMenu);
}

void Kamus::eksekusiMenu(int nomorMenu) {
    switch (nomorMenu) {
        case 2 :
            penambahKata.ambilInput(&model);
            break;
        default:
            cout << "Salah kode perintah" << endl;
    }
    tampilkanMenu();
}