/**
 * Grid Paths
 *
 * You are given a description of a path which may also contain characters ? (any direction). Your task is to calculate the number of paths that match the description.
 *
 * Explore the entire grid using recursive backtracking. If at any point the direction is specified, only go that direction.
 *
 * Exit early if we made it to the lower left (goal square) before depth 48, or if splitting the board with unsolved on both sides.
 *
 * https://cses.fi/problemset/task/1625/
 */

#include<iostream>

#define DIM 7
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j) FOR(i, 0, j, 1)
using namespace std;
bool board[DIM+2][DIM+2] = {{false}};
int sequence[DIM*DIM-1];
int successful_boards;

// up, down, left, right
int row_movements[] = {-1, 1, 0, 0};
int col_movements[] = {0, 0, -1, 1};

void rec(int row, int col, int depth) {
    if (row == 7 && col == 1) {
        if (depth == 48)
            ++successful_boards;
        return;
    }
    if (depth == 48)
        return;

    // if dividing the board in two with both the side directions not visited
    if ((board[row+1][col] && board[row-1][col]) && (!board[row][col-1] && !board[row][col+1]))
        return;
    if ((board[row][col-1] && board[row][col+1]) && (!board[row-1][col] && !board[row+1][col]))
        return;

    int newC, newR, d(depth+1);
    int dir = sequence[depth];
    board[row][col] = true;

    // if direction already specified
    if (dir < 4) {
        newR = row + row_movements[dir];
        newC = col + col_movements[dir];
        if (!board[newR][newC]) rec(newR, newC, d);
    } else {
        // otherwise check all four directions
        REP(i, 4) {
            newR = row + row_movements[i];
            newC = col + col_movements[i];
            if (!board[newR][newC]) rec(newR, newC, d);
        }
    }
    board[row][col] = false;
}

int main() {
    successful_boards = 0;
    char tmp;
    REP(i, DIM*DIM-1) {
        cin >> tmp;
        if (tmp == 'U') sequence[i] = 0;
        else if (tmp == 'D') sequence[i] = 1;
        else if (tmp == 'L') sequence[i] = 2;
        else if (tmp == 'R') sequence[i] = 3;
        else sequence[i] = 4;
    }
    // mark the outside of board as visited
    REP(i, DIM+2) {
        board[0][i] = true;
        board[DIM+1][i] = true;
        board[i][0] = true;
        board[i][DIM+1] = true;
    }
    rec(1, 1, 0);
    cout << successful_boards << endl;

    return 0;
}