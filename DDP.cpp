#include <iostream>

using namespace std;

// Berfungsi untuk menampilkan papan Tic Tac Toe
void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] <<"|";
            
        }
        cout << endl;
    }
}

// Berfungsi untuk memeriksa apakah seorang pemain telah menang
bool checkWin(char board[3][3], char player) {
    // Periksa baris dan kolom
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Periksa diagonal
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Berfungsi untuk melakukan pergerakan pada papan
void makeMove(char board[3][3], int row, int col, char player) {
    board[row][col] = player;
}

int main() {
    // Inisialisasi papan
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    char currentPlayer = 'X'; // Pemain 'X' memulai permainan

    while (true) {
        // Menampilkan status papan saat ini
        displayBoard(board);

        // Dapatkan gerakan pemain
        int row, col;
        cout << "Pemain " << currentPlayer << ", masukkan baris dan kolom: ";
        cin >> row >> col;

        // Validasi masukan
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "gagal, silahkan coba lagi." << endl;
            continue;
        }

        // Lakukan gerakan di papan
        makeMove(board, row, col, currentPlayer);

        // Periksa apakah pemain saat ini telah menang
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "pemain " << currentPlayer << " menang!" << endl;
            break;
        }

        // Beralih ke pemain lain untuk giliran berikutnya
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

