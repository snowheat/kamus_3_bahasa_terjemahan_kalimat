//
// Created by insan on 2/22/2018.
//

#ifndef TUGAS_5_KAMUS_3_BAHASA_PENAMBAHKATA_H
#define TUGAS_5_KAMUS_3_BAHASA_PENAMBAHKATA_H


#include "../Model.h"

class PenambahKata {

public:
    void ambilInput(Model *m);

    void tambahkanKataKeModel(std::string indonesia, std::string inggris, std::string sunda, std::string jenisKata, Model *m);

    int TulisKata(std::string alamatFileModel, std::string kata, int posisiPU, Model *m);

    unsigned char *
    TulisKataMulaiIndex(unsigned char *grafKamus, std::string kata, int mulaiIndex, int alamatPointerOrtu, int posisiPU,
                        int &panjangGrafKamus, Model *m);
};


#endif //TUGAS_5_KAMUS_3_BAHASA_PENAMBAHKATA_H
