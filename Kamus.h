//
// Created by insan on 2/22/2018.
//

#ifndef TUGAS_5_KAMUS_3_BAHASA_KAMUS_H
#define TUGAS_5_KAMUS_3_BAHASA_KAMUS_H


#include "Model.h"
#include "operasi/PenambahKata.h"
#include "operasi/PenerjemahKalimat.h"
#include "operasi/PenampilStruktur.h"

class Kamus {
public:
    Model model;

    Kamus();
    void buka();

private:
    int nomorMenu;

    PenerjemahKalimat penerjemahKalimat;
    PenambahKata penambahKata;
    PenampilStruktur penampilStruktur;

    void tampilkanMenu();
    void eksekusiMenu(int nomorMenu);
};


#endif //TUGAS_5_KAMUS_3_BAHASA_KAMUS_H
