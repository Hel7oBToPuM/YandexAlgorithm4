#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


std::vector<int> board;
int count, N;


bool check(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    return true;
}

void put_queen(int row) {
    if (row == N) {
        count++;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (check(row, col)) {
            board[row] = col;
            put_queen(row + 1);
        }
    }
}

int main() {
    std::cin >> N;
    board = std::vector<int>(N);
    put_queen(0);
    cout << count << endl;
    return 0;
}