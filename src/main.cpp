#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

void read_file(string filename, vector<vector<char>>& board, vector<string>& words) {
  /* I.S. filename terdefinisi, board dan words sembarang
     F.S. board berisi matriks puzzle dan words berisi array kata-kata yang diambil dari file bernama filename
  */
  /* KAMUS */
  /* ALGORITMA */
  // buka file
  ifstream input;
  input.open(filename, ios::in);
  if (!input) { // file tidak ada
    cout << "No such file";
  } else { // file ada
    // baca file
    string line;
    // board
    while (getline(input, line) && line !="") {
      vector<char> current_line;
      for (int i=0; i<line.size(); i++) {
        char current_char = line[i];
        if (current_char != ' ') {
          current_line.push_back(current_char);
        }
      }
      board.push_back(current_line);
    }
    // words
    while (getline(input, line)) {
      words.push_back(line);
    }
  }
}

void check_surrounding(int i, int j, vector<vector<char>> board, string word, int &cmp, int &total) {
  /* I.S. i dan j terdefinisi, berupa koordinat posisi sekarang,
          board terdefinisi, berupa puzzle,
          word terdefinisi, berupa kata yang sedang dicari,
          cmp dan total terdefinisi, berupa total perbandingan kata dan total kata yang telah ditemukan
     F.S. bila word ditemukan, jawaban dicetak,
          cmp bertambah sebanyak jumlah perbandingan yang dilakukan,
          total bertambah 1 bila word ditemukan
  */
  /* KAMUS */
  bool found = false;
  int m = board.size();
  int n = board[0].size();
  int w = word.size();
  /* ALGORITMA */
  // iterasi sekeliling koordinat (i dari -1 hingga 1 dan j dari -1 hingga 1 relatif terhadap koordinat awal)
  for (int row = -1; row <= 1; row++) {
    for (int column = -1; column <= 1; column++) {
      // bila merupakan koordinat awal (0 dan 0 relatif dari koordinat awal), huruf tidak diperiksa
      if (!(row == 0 && column == 0)) { 
        // bila diprediksi out of bounds, huruf tidak diperiksa
        if ((-1<=i+(w*row)) && (-1<=j+(w*column)) && ((i+w*row)<=m) && ((j+w*column)<=n)) { 
          found = true;
          // lakukan perbandingan huruf per huruf dari huruf kedua kata, sambil menambahkan cmp
          for (int letter=1; letter<word.size(); letter++) {
            cmp += 1;
            // bila huruf tidak sesuai, keluar dari loop dan lanjutkan pencarian ke arah lain
            if (board[i+(row*letter)][j+(column*letter)] != word[letter]) {
              found = false;
              break;
            }
          }
          // bila kata ditemukan, cetak jawaban dan tambahkan total dengan 1
          if (found) {
            total += 1;
            // buat matriks sementara untuk menampung solusi
            char solution[m][n];
            for (int x=0; x<m; x++) {
              for (int y=0; y<n; y++) {
                solution[x][y] = '-';
              }
            }
            for (int letter=0; letter<word.size(); letter++) {
              solution[i+(row*letter)][j+(column*letter)] = word[letter];
            }
            // cetak matriks solusi
            cout << word << "\n";
            for (int x=0; x<m; x++) {
              for (int y=0; y<n; y++) {
                cout << solution[x][y] << " ";
              }
              cout << "\n";
            }
            cout << "\n";
          }
        }
      }
    }
  }
}

int main(int argc, char** argv) {
  /* KAMUS */
  vector<vector<char>> board;
  vector<string> words;
  vector<char*> solutions;
  bool found;
  int m, n;
  int cmp = 0;
  int total = 0;

  /* ALGORITMA */
  // read file
  read_file(argv[1], board, words);
  // store board row and column size
  m = board.size();
  n = board[0].size();
  // start timer
  std::chrono::steady_clock sc;
  auto start = sc.now();
  // iterate through each letter in the board
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      for (string word : words) {
        char curr_char = board[i][j];
        // check first letter of every word
        if (curr_char == word[0]) { // found a match
          cmp += 1;
          check_surrounding(i, j, board, word, cmp, total);
        }
      }
    }
  }
  // end timer
  auto end = sc.now();
  auto timeSpend = static_cast<std::chrono::duration<double>>(end-start);
  // output
  cout << "Ditemukan " << total << "/" << words.size() << " buah kata.\n";
  cout << "Waktu eksekusi program: " << timeSpend.count() << " detik.\n";
  cout << "Total perbandingan huruf: " << cmp << " kali.\n";
  return 0;
}