# Penyelesaian Word Search Puzzle dengan Algoritma Brute Force

## Deskripsi Singkat
Program ini merupakan program untuk menyelesaikan Word Search Puzzle menggunakan algoritma brute force, ditulis dalam bahasa C++. Program menerima input berupa file teks yang berisi word search puzzle, dan mengeluarkan input yang berisi seluruh jawaban puzzle, total kata yang ditemukan, waktu eksekusi program, dan total perbandingan huruf yang dilakukan.

## Format File Input
File input berupa file teks yang berisi matriks huruf di dalam puzzle (antar huruf dipisahkan oleh spasi), diikuti satu baris kosong, dan daftar kata-kata yang akan dicari di dalam puzzle. Satu baris satu kata.  
Contoh:  
```
J S O L U T I S
S U N A R U U A
N E P T U N E T
S O N I E I S U
R C E V T R E R
A H T R A E S N
M M E R C U R Y

EARTH
JUPITER
MARS
MERCURY
NEPTUNE
SATURN
URANUS
VENUS
```
## Requirement Program
- g++ untuk compile
- library:
  - iostream
  - fstream
  - vector
  - chrono

## Instalasi
Clone repositori ini dengan command ini pada terminal:  
```
git clone https://github.com/FelineJTD/Word-Search-with-Brute-Force.git
```

## Menjalankan Program
### Menggunakan Source Code
- Masuk ke dalam folder hasil clone
- Compile terlebih dahulu program menggunakan g++, kemudian jalankan program dengan nama file txt yang berisi puzzle sebagai argumen. Gunakan command:  
```
g++ ./src/main.cpp && ./a.out [NAMA_FILE.txt]
```  
### Menggunakan Executable
- Masuk ke dalam folder hasil clone
- Jalankan command ini:
```
./bin/main [NAMA_FILE.txt]
```

## Author
Felicia Sutandijo - 13520050