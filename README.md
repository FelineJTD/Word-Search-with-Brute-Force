# Penyelesaian Word Search Puzzle dengan Algoritma Brute Force
*Author: Felicia Sutandijo - 13520050*

## Word Search Puzzle
Word search puzzle adalah permainan kata dimana pemain harus menemukan beberapa kata
tersembunyi dalam kumpulan huruf acak. Kumpulan huruf tersebut biasa diletakkan pada “papan”
berbentuk segi empat atau dapat disebut juga matriks huruf. Kata-kata pada matriks huruf ini dapat
ditemukan dalam delapan arah yang mungkin, yaitu, vertikal ke atas, vertikal ke bawah, horizontal
ke kanan, horizontal ke kiri, diagonal ke kanan atas, diagonal ke kanan bawah, diagonal ke kiri
atas, dan diagonal ke kiri bawah. Word search puzzle pertama kali dibuat oleh Noeman E. Gibat.
Puzzle ini dipublikasikan dalam the Selenby Digest pada 1 Maret 1968 di Norman, Oklahoma.
Setelah itu word search puzzle mulai terkenal di daerahnya. Kemudian beberapa guru meminta
salinannya untuk digunakan sebagai alat mengajar. Akhirnya permainan itu tersebar setelah
seorang guru mengirimkan salinannya kepada teman-teman di kota lain. Sekarang word search
puzzle bisa ditemukan dengan mudah di koran, majalah, bahkan internet (Paragraf di atas dikutip
dari sini: https://informatika.stei.itb.ac.id/~rinaldi.munir/Stmik/2016-2017/Makalah2017/Makalah-IF2211-2017-077.pdf).

## Algoritma Brute Force
Berikut adalah algoritma brute force yang digunakan dalam penyelesaian word search puzzle pada repositori ini:
1.	Input diproses. Input yang diterima berupa file txt yang berisi puzzle serta daftar kata-kata yang perlu dicari dalam puzzle. Data tersebut diekstraksi menjadi matriks karakter yang berisi puzzle dan array string yang berisi daftar kata-kata.
2.	Pencarian dimulai dari huruf pertama (kiri atas) dari puzzle, kemudian dilanjutkan ke arah kanan lalu bawah.
3.	Huruf yang sedang diperiksa pada puzzle akan dibandingkan dengan huruf depan seluruh kata-kata yang hendak dicari.
4.	Bila ditemukan huruf depan sebuah kata yang cocok, algoritma akan mencari huruf-huruf selanjutnya dari kata tersebut ke 8 arah, yaitu atas, kanan atas, kanan, kanan bawah, bawah, kiri bawah, kiri, dan kiri atas.
5.	Bila panjang kata (dikurangi 1 huruf depan yang telah diperiksa) melebihi jarak dari titik yang sedang diperiksa ke ujung matriks (sesuai arah), maka pencarian dianggap out of bounds dan tidak dilanjutkan karena kata tidak mungkin ditemukan. Pencarian dilanjutkan ke arah yang selanjutnya.
6.	Bila huruf kedua dari kata ditemukan, algoritma akan mencocokkan huruf ketiga pada arah yang sama, begitu seterusnya hingga seluruh huruf pada kata cocok. Bila ditemukan huruf yang tidak cocok, pencarian dihentikan dan dilanjutkan ke arah berikutnya.
7.	Bila kata ditemukan, solusi akan langsung dicetak dan pencarian diteruskan ke arah berikutnya.
8.	Bila semua kemungkinan 8 arah tersebut telah diperiksa, pencarian dilanjutkan ke kata berikutnya dalam daftar kata-kata yang harus dicari, namun masih membandingkan dengan huruf yang sama pada puzzle.
9.	Bila seluruh kata dalam daftar telah dibandingkan huruf depannya dengan huruf yang sedang diperiksa pada puzzle, pencarian dilanjutkan ke huruf selanjutnya (sebelah kanan huruf yang sedang diperiksa, bila tidak ada akan memeriksa huruf pertama satu baris di bawah huruf yang sedang diperiksa) pada puzzle (Kembali ke langkah 3).
10.	Bila seluruh huruf dalam puzzle telah diperiksa, pencarian selesai. Output akhir (total kata yang ditemukan, total waktu yang diperlukan, serta total perbandingan yang dilakukan) ditampilkan. Program selesai.

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
## Instalasi
Clone repositori ini dengan command ini pada terminal: `git clone https://github.com/FelineJTD/Word-Search-with-Brute-Force.git`

## Menjalankan Program
- Masuk ke dalam folder hasil clone
- Compile terlebih dahulu program menggunakan g++, kemudian jalankan program dengan nama file txt yang berisi puzzle sebagai argumen. Gunakan command:  
`g++ main.cpp && ./a.out [NAMA_FILE.txt]`  
Untuk mencoba menggunakan file sample:  
`g++ main.cpp && ./a.out sample.txt`