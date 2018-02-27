//
// Created by insan on 2/22/2018.
//

#ifndef TUGAS_5_KAMUS_3_BAHASA_MODEL_H
#define TUGAS_5_KAMUS_3_BAHASA_MODEL_H


class Model {

private:


public:
    Model();

    static int INISIALISASI_POINTER_KONTEN_PERTAMA;

    void BuatFileModel(std::string fileModelString);

    bool KataDanJenisKataSudahAda(std::string fileModel, std::string kata, std::string jenisKata);

    int GetPosisiMenambahPU();

    int TulisKata(std::string alamatFileModel, std::string kata, int posisiPU);

    int GetPosisiHurufStop(std::string fileModel, std::string kata, std::string jenisKata);

    void TulisPU(int posisiPU, char &hurufAwalIndonesia, int posisiHurufStopIndonesia, char &hurufAwalInggris,
                 int posisiHurufStopInggris, char &hurufAwalSunda, int posisiHurufStopSunda);

    void SetPointerMulaiMenulis(unsigned char *grafKamus, int alamat);

    int GetPointerMulaiMenulis(unsigned char *grafKamus);

    unsigned char *GetGrafKamus(std::string alamatFileModel, int &panjangGrafKamus);

    int GetPointerHurufPertamaPeriksa(unsigned char *grafKamus);

    void SetPointerHurufPertamaPeriksa(unsigned char *grafKamus, int alamat);

    unsigned char GetGrafKamusPosisi(unsigned char *grafKamus, int index);

    void SetGrafKamusPosisi(unsigned char *grafKamus, int index, int value);

    int GetPointerAlamatTujuan(unsigned char *grafKamus, int alamatA, int alamatB, int alamatC);

    void SetPointerAlamatTujuan(unsigned char *grafKamus, int alamatA, int alamatB, int alamatC, int alamatTujuan);
};


#endif //TUGAS_5_KAMUS_3_BAHASA_MODEL_H
