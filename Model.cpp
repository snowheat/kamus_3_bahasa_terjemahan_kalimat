//
// Created by insan on 2/22/2018.
//

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Model.h"

int Model::INISIALISASI_POINTER_KONTEN_PERTAMA = 20;

using namespace std;

Model::Model() {

}

/**
 * BuatFileModel membuat model huruf kamus baru
 * @param fileModelString
 */
void Model::BuatFileModel(string fileModelString) {
    cout << "buat " << fileModelString << endl;
    ofstream fileModel(fileModelString);
    if(!fileModel) {
        cout << "File tidak dapat dibuat" << endl;
    }else {
        unsigned char * grafKamus = nullptr;
        grafKamus = new unsigned char [INISIALISASI_POINTER_KONTEN_PERTAMA]();
        grafKamus[0] = 2;
        grafKamus[1] = 2;
        grafKamus[2] = 2;
        grafKamus[3] = 0;
        grafKamus[4] = 0;
        grafKamus[5] = INISIALISASI_POINTER_KONTEN_PERTAMA; // Pointer mulai menulis
        grafKamus[6] = 0;
        grafKamus[7] = 0;
        grafKamus[8] = INISIALISASI_POINTER_KONTEN_PERTAMA; // Huruf pertama periksa
        grafKamus[9] = 2;
        grafKamus[10] = 2;
        grafKamus[11] = 2;
        grafKamus[12] = 2;
        grafKamus[13] = 2;
        grafKamus[14] = 2;
        grafKamus[15] = 2;
        grafKamus[16] = 2;
        grafKamus[17] = 0;
        grafKamus[18] = 0;
        grafKamus[19] = 20;

        if (fileModel.is_open()) {
            for(int i = 0; i<INISIALISASI_POINTER_KONTEN_PERTAMA; i++) {
                fileModel.put(grafKamus[i]);
            }
            fileModel.close();
        }

        delete[] grafKamus;

    }
}

/**
 * KataDanJenisKataSudahAda mengecek apakah kata dan jenis kata tersebut sudah ada pada fileModel
 * @param fileModel
 * @param kata
 * @param jenisKata
 * @return
 */
bool Model::KataDanJenisKataSudahAda(std::string fileModel, std::string kata, std::string jenisKata) {

    return false;
}

/**
 * GetPosisiMenambahPU mengambil posisi menambah set pointer baru model pointer universal
 * @return
 */
int Model::GetPosisiMenambahPU() {
    return 0;
}



/**
 * GetPosisiHurufStop mengambil alamat pointer huruf stop untuk kata dan jenis kata tersebut
 * @param fileModel
 * @param kata
 * @param jenisKata
 * @return
 */
int Model::GetPosisiHurufStop(std::string fileModel, std::string kata, std::string jenisKata) {
    return 0;
}

/**
 * TulisPU menuliskan Pointer Universal baru
 * @param posisiPU
 * @param hurufAwalIndonesia
 * @param posisiHurufStopIndonesia
 * @param hurufAwalInggris
 * @param posisiHurufStopInggris
 * @param hurufAwalSunda
 * @param posisiHurufStopSunda
 */
void
Model::TulisPU(int posisiPU, char &hurufAwalIndonesia, int posisiHurufStopIndonesia, char &hurufAwalInggris,
               int posisiHurufStopInggris, char &hurufAwalSunda, int posisiHurufStopSunda) {

}

/**
 * GetPointerMulaiMenulis get pointer mulai menulis
 * @param grafKamus
 * @return
 */
int Model::GetPointerMulaiMenulis(unsigned char *grafKamus) {
    int pointerMulaiMenulis = (65536 * grafKamus[3]) + (256 * grafKamus[4]) + grafKamus[5];
    return pointerMulaiMenulis;
}

/**
 * SetPointerMulaiMenulis set pointer mulai menulis
 * @param grafKamus
 * @param alamat
 */
void Model::SetPointerMulaiMenulis(unsigned char *grafKamus, int alamat) {
    grafKamus[3] = alamat / 65536;
    grafKamus[4] = (alamat % 65536) / 256;
    grafKamus[5] = (alamat % 65536) % 256;
}

/**
 * GetPointerHurufPertamaPeriksa
 * @param grafKamus
 * @return
 */
int Model::GetPointerHurufPertamaPeriksa(unsigned char *grafKamus) {
    return (65536 * grafKamus[6]) + (256 * grafKamus[7]) + grafKamus[8];
}

/**
 * SetPointerHurufPertamaPeriksa
 * @param grafKamus
 * @param alamat
 */
void Model::SetPointerHurufPertamaPeriksa(unsigned char *grafKamus, int alamat) {
    grafKamus[6] = alamat / 65536;
    grafKamus[7] = (alamat % 65536) / 256;
    grafKamus[8] = (alamat % 65536) % 256;
}

/**
 * GetPointerAlamatTujuan
 * @param grafKamus
 * @param alamatA
 * @param alamatB
 * @param alamatC
 * @return
 */
int Model::GetPointerAlamatTujuan(unsigned char *grafKamus, int alamatA, int alamatB, int alamatC) {
    return (65536 * grafKamus[alamatA]) + (256 * grafKamus[alamatB]) + grafKamus[alamatC];
}

/**
 * GetPointerAlamatTujuan
 * @param grafKamus
 * @param alamatA
 * @param alamatB
 * @param alamatC
 * @param alamatTujuan
 */
void Model::SetPointerAlamatTujuan(unsigned char *grafKamus, int alamatA, int alamatB, int alamatC, int alamatTujuan) {
    grafKamus[alamatA] = alamatTujuan / 65536;
    grafKamus[alamatB] = (alamatTujuan % 65536) / 256;
    grafKamus[alamatC] = (alamatTujuan % 65536) % 256;
}

/**
 * GetGrafKamus
 * @param alamatFileModel
 * @param panjangGrafKamus
 * @return
 */
unsigned char *Model::GetGrafKamus(std::string alamatFileModel, int &panjangGrafKamus) {
    https://stackoverflow.com/questions/25495544/change-a-variable-in-main-from-a-function

    /**
     * k tiap iterasi karakter dari file model
     */
    char k;

    /**
     * i iterator
     */
    int i;

    ifstream fileModel(alamatFileModel, ios::binary);
    if(fileModel.is_open()) {

        fileModel.seekg (0, fileModel.end);
        panjangGrafKamus = fileModel.tellg();
        fileModel.seekg (0, fileModel.beg);

        unsigned char *grafKamus = new unsigned char[panjangGrafKamus]();

        i = 0;
        while (! fileModel.eof() && i<panjangGrafKamus )
        {
            fileModel.read(&k, 1);
            grafKamus[i] = k;
            //cout << i << " > " << int(grafKamus[i]) << " : " << k << endl;
            i++;
        }

        fileModel.close();

        return grafKamus;
    }else {
        return nullptr;
    }

}

/**
 * GetGrafKamusPosisi
 * @param grafKamus
 * @param index
 * @return
 */
unsigned char Model::GetGrafKamusPosisi(unsigned char *grafKamus, int index) {
    return grafKamus[index];
}

/**
 * SetGrafKamusPosisi
 * @param grafKamus
 * @param index
 * @param value
 */
void Model::SetGrafKamusPosisi(unsigned char *grafKamus, int index, int value) {
    //cout << "setGrafKamus " << index << " - " << value << endl;
    grafKamus[index] = value;
}
