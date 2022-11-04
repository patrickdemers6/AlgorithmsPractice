/**
 * Chessboard and Queens
 *
 * Your task is to place eight queens on a chessboard so that no two queens are attacking each other.
 * As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares.
 * However, the reserved squares do not prevent queens from attacking each other.
 *
 * How many possible ways are there to place the queens?
 *
 * Approach: Each row needs one queen. Explore all possible combinations by recursively traversing down the chess board.
 * Before placing a queen, check if the proposed position has a queen that can attack it.
 *
 * https://cses.fi/problemset/task/1624/
 */
#include <iostream>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define DIM 8
using namespace std;
int completed_board_count;
char board[DIM][DIM];

bool check_valid_placement(int row, int col) {
    if (board[row][col] != '.')
        return false;
    REP(i, DIM) {
        if (board[row][i] == '+' || board[i][col] == '+')
            return false;
    }
    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == '+')
            return false;
    }
    for (int r = row, c = col; r < DIM && c < DIM; r++, c++) {
        if (board[r][c] == '+')
            return false;
    }
    for (int r = row, c = col; r >= 0 && c < DIM; r--, c++) {
        if (board[r][c] == '+')
            return false;
    }
    for (int r = row, c = col; r < DIM && c >= 0; r++, c--) {
        if (board[r][c] == '+')
            return false;
    }
    return true;
}

void solve(int row) {
    if (row == DIM) {
        ++completed_board_count;
        return;
    }

    REP(i, DIM) {
        if (check_valid_placement(row, i)) {
            board[row][i] = '+';
            solve(row + 1);
            board[row][i] = '.';
        }
    }
}

int main() {
    completed_board_count = 0;
    REP(i, DIM) {
        REP(j, DIM) {
            cin >> board[i][j];
        }
    }

    solve(0);
    cout << completed_board_count << endl;

    return 0;
}