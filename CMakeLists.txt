cmake_minimum_required(VERSION 3.9)
project(tugas_5_kamus_3_bahasa)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
SET(BUILD_SHARED_LIBRARIES OFF)
SET(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(tugas_5_kamus_3_bahasa main.cpp stemmer/Stemmer.cpp stemmer/Stemmer.h Kamus.cpp Kamus.h operasi/PenambahKata.cpp operasi/PenambahKata.h operasi/PenerjemahKalimat.cpp operasi/PenerjemahKalimat.h operasi/PenampilStruktur.cpp operasi/PenampilStruktur.h Model.cpp Model.h)