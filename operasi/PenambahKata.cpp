//
// Created by insan on 2/22/2018.
//

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include "PenambahKata.h"

using namespace std;

void PenambahKata::ambilInput(Model *m) {
    string kataBahasaIndonesia;
    string kataBahasaSunda;
    string kataBahasaInggris;
    string jenisKata;

    cout << "Masukan kata bahasa Indonesia :" << endl;
    cin >> kataBahasaIndonesia;
    cout << "Masukan terjemahan bahasa Sunda :" << endl;
    cin >> kataBahasaSunda;
    cout << "Masukan terjemahan bahasa Inggris :" << endl;
    cin >> kataBahasaInggris;
    cout << "Masukan ID jenis kata (1: Noun, 2: Pronoun, 3: Verb, 4: Adverb, 5: Adjective, 6: Conjunction, 7: Adposition, 8: Other) :" << endl;
    cin >> jenisKata;

    tambahkanKataKeModel(kataBahasaIndonesia, kataBahasaSunda, kataBahasaInggris, jenisKata, m);
}

/**
 * PenambahKata menambahkan kata baru tiga bahasa ke dalam kamus
 *
 * 1. Cek huruf pertama
 * 2. Ambil atau buat model huruf pertama
 * 3. Telusuri tiap model udah ada kata dan jenis kata bahasa indonesia nya atau belum
 *      3a. Kalau udah ada
 *          - Gausah lakuin apa apa
 *
 *      3b. Kalau belum ada
 *          - Ambil posisi pointer mulai menulis baru pada model pointer universal
 *
 *          3ba. Kalau kata bahasa lain nya belum ada
 *              - Tulis ke indonesia inggris sunda, ambil alamat
 *
 *          3bb. Kalau kata bahasa lain nya udah ada
 *              - Tulis ke indonesia, ambil alamat
 *              - Ambil alamat dari kata bahasa lain yang udah ada
 *
 *          - Tulis ke model pointer universal 3 alamat bahasa dan jenis kata
 *
 * @param indonesia
 * @param sunda
 * @param inggris
 * @param m
 */
void PenambahKata::tambahkanKataKeModel(std::string indonesia, std::string inggris, std::string sunda, std::string jenisKata, Model *m) {

    /**
     * fileModelIndonesia menyimpan string nama file model huruf bahasa Indonesia
     */
    stringstream fileModelIndonesia;

    /**
     * fileModelIndonesia menyimpan string nama file model huruf bahasa Inggris
     */
    stringstream fileModelInggris;

    /**
     * fileModelIndonesia menyimpan string nama file model huruf bahasa Sunda
     */
    stringstream fileModelSunda;

    /**
     * posisiPU adalah posisi pointer mulai menulis baru pada model pointer universal
     */
    int posisiPU;

    /**
     * posisiHurufStopIndonesia adalah posisi pointer pertama huruf stop dari tiap kata bahasa Indonesia
     */
    int posisiHurufStopIndonesia;

    /**
     * posisiHurufStopInggris adalah posisi pointer pertama huruf stop dari tiap kata bahasa Ingrris
     */
    int posisiHurufStopInggris;

    /**
     * posisiHurufStopSunda adalah posisi pointer pertama huruf stop dari tiap kata bahasa Sunda
     */
    int posisiHurufStopSunda;


    // 1. Cek huruf pertama

    // 2. Ambil atau buat model huruf pertama
    fileModelIndonesia << "bin/tree/indonesia/" << indonesia.at(0) << ".model";

    if(ifstream(fileModelIndonesia.str(), ios::binary)) {
        // File ada
        cout << "file ada" << endl;
    }else {
        // File tidak ada, buat file model
        cout << "file tidak ada, buat file model" << endl;
        m->BuatFileModel(fileModelIndonesia.str());
    }

    // 3. Telusuri tiap model udah ada kata dan jenis kata bahasa indonesia nya atau belum
    if(m->KataDanJenisKataSudahAda(fileModelIndonesia.str(), indonesia, jenisKata)) {
        // 3a. Kalau udah ada
    }else {
        // 3b. Kalau belum ada

        // Ambil posisi menambah set pointer baru model pointer universal
        posisiPU = m->GetPosisiMenambahPU();

        posisiHurufStopIndonesia = TulisKata(fileModelIndonesia.str(), indonesia, posisiPU, m);

        if(m->KataDanJenisKataSudahAda(fileModelInggris.str(), inggris, jenisKata)) {
            // Kata dan jenis kata bahasa Inggris nya sudah ada
            posisiHurufStopInggris = m->GetPosisiHurufStop(fileModelInggris.str(), inggris, jenisKata);
        }else {
            // Kata dan jenis kata bahasa Inggris nya belum ada
            // posisiHurufStopInggris = TulisKata(fileModelInggris.str(), inggris, posisiPU, m);
        }

        if(m->KataDanJenisKataSudahAda(fileModelSunda.str(), sunda, jenisKata)) {
            // Kata dan jenis kata bahasa Inggris nya sudah ada
            posisiHurufStopSunda = m->GetPosisiHurufStop(fileModelInggris.str(), sunda, jenisKata);
        }else {
            // Kata dan jenis kata bahasa Inggris nya belum ada
            // posisiHurufStopSunda = TulisKata(fileModelInggris.str(), sunda, posisiPU, m);
        }

        m->TulisPU(posisiPU, indonesia.at(0), posisiHurufStopIndonesia, inggris.at(0), posisiHurufStopInggris,
                   sunda.at(0), posisiHurufStopSunda);

        //[jenis kata][kamus abjad indonesia][][][][kamus abjad inggris][][][][kamus abjad sunda][][][]

    }

}

/**
 * TulisKata menuliskan kata ke model huruf
 * @param alamatFileModel
 * @param kata
 * @param posisiPU
 * @return
 */
int PenambahKata::TulisKata(std::string alamatFileModel, std::string kata, int posisiPU, Model *m) {

    /**
     * panjangGrafKamus
     */
    int panjangGrafKamus;

    /**
     * grafKamus
     */
    unsigned char* grafKamus;

    /**
     * grafKamusBaru
     */
    unsigned char* grafKamusBaru;

    /**
     * pointerHurufPertamaPemeriksa
     */
    int pointerHurufPertamaPemeriksa;

    /**
     * i iterator
     */
    int i;

    /**
     * pointer iterator
     */
    int pointerMulaiMenulis;

    /**
     * mulaiIndex
     */
    int mulaiIndex;

    grafKamus = m->GetGrafKamus(alamatFileModel, panjangGrafKamus);

    if(grafKamus != NULL) {

        pointerMulaiMenulis = m->GetPointerMulaiMenulis(grafKamus);

        if(pointerMulaiMenulis == m->INISIALISASI_POINTER_KONTEN_PERTAMA) {
            // Graf kamus masih kosong
            grafKamus = TulisKataMulaiIndex(grafKamus, kata, 0, 0, posisiPU, panjangGrafKamus, Model *m);
            cout << (grafKamus == NULL) << endl;
            cout << panjangGrafKamus << endl;

        }else {
            // Graf kamus ada isi
        }


    }else {
        cout << "null" << endl;
    }

    delete[] grafKamus;
    grafKamus = nullptr;
}

/**
 * panjangGrafKamusBaru
 * @param kata
 * @param mulaiIndex
 * @param posisiPU
 * @param panjangGrafKamus
 * @return
 */
unsigned char *PenambahKata::TulisKataMulaiIndex(unsigned char *grafKamus, std::string kata, int mulaiIndex, int alamatPointerOrtu, int posisiPU, int &panjangGrafKamus, Model *m) {

    /**
     * grafKamusBaru
     */
    unsigned char *grafKamusBaru;

    /**
     * pMulaiMenulis
     */
    int pMulaiMenulis;

    /**
     * pLanjutMenulis
     */
    int pLanjutMenulis;

    /**
     * panjangGrafKamusLama
     */
    int panjangGrafKamusLama;

    /**
     * i iterator
     */
    int i;

    pMulaiMenulis = m->GetPointerMulaiMenulis(grafKamus);

    panjangGrafKamusLama = panjangGrafKamus;

    //mulaiIndex < kata.length() : tulis huruf + kosong + stop
    //mulaiIndex = kata.length() : belum kosong + stop
    //mulaiIndex = kata.length()+1 : belum stop
    panjangGrafKamus = panjangGrafKamus + ((kata.length() - mulaiIndex + 2) * 11) + 1;
    grafKamusBaru = new unsigned char[panjangGrafKamus]();

    for(i=0; i<panjangGrafKamus; ++i) {
        if(i<panjangGrafKamusLama) {
            grafKamusBaru[i] = grafKamus[i];
        }
        //cout << i << " - " << int(grafKamusBaru[i]) << endl;
    }

    if(mulaiIndex < kata.length()) {

        // mulaiIndex < kata.length() : tulis huruf + kosong + stop
        pLanjutMenulis = pMulaiMenulis;
        for(i=0; i<(kata.length()-mulaiIndex); i++) {
            m->SetGrafKamusPosisi(grafKamusBaru, pLanjutMenulis, 1);
            m->SetGrafKamusPosisi(grafKamusBaru, pLanjutMenulis+1, tolower(kata[i]));
            m->SetPointerAlamatTujuan(grafKamusBaru, pLanjutMenulis+2, pLanjutMenulis+3, pLanjutMenulis+4, alamatPointerOrtu);
            m->SetPointerAlamatTujuan(grafKamusBaru, pLanjutMenulis+5, pLanjutMenulis+6, pLanjutMenulis+7, pLanjutMenulis+11);
            m->SetPointerAlamatTujuan(grafKamusBaru, pLanjutMenulis+8, pLanjutMenulis+9, pLanjutMenulis+10, (2));

            alamatPointerOrtu = pLanjutMenulis;
            pLanjutMenulis+=11;
        }

    }

    if(mulaiIndex == kata.length() || mulaiIndex < kata.length()) {
        // mulaiIndex = kata.length() : belum kosong + stop
        // Tulis kata kosong
        m->SetGrafKamusPosisi(grafKamusBaru, pLanjutMenulis, 1);
        m->SetGrafKamusPosisi(grafKamusBaru, pLanjutMenulis+1, (2));
        m->SetPointerAlamatTujuan(grafKamusBaru, pLanjutMenulis+2, pLanjutMenulis+3, pLanjutMenulis+4, alamatPointerOrtu);
        m->SetPointerAlamatTujuan(grafKamusBaru, pLanjutMenulis+5, pLanjutMenulis+6, pLanjutMenulis+7, pLanjutMenulis+11);
        m->SetPointerAlamatTujuan(grafKamusBaru, pLanjutMenulis+8, pLanjutMenulis+9, pLanjutMenulis+10, (2));

        alamatPointerOrtu = pLanjutMenulis;
        pLanjutMenulis+=11;
    }

    // mulaiIndex = kata.length()+1 : belum stop
    // Tulis kata stop dan alamat pointer universal
    // Stop 

    for(i=0; i<panjangGrafKamus; ++i) {
        if(i<panjangGrafKamusLama) {
            grafKamusBaru[i] = grafKamus[i];
        }
        cout << i << " - " << int(grafKamusBaru[i]) << " - " << char(grafKamusBaru[i])  << endl;
    }

    delete[] grafKamus;
    grafKamus = nullptr;

    return grafKamusBaru;
}

