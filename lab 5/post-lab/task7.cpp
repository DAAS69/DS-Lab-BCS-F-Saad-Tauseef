#include <iostream>
using namespace std;

void print_board(char board[][10], int n) {
    static int sol = 0;
    sol++;
    cout << "solution number " << sol << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool is_safe(char board[][10], int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
    
    for (int j = 0; j < n; j++) {
        if (board[row][j] == 'Q') {
            return false;
        }
    }
    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    
    return true;
}

void solve_queens(char board[][10], int row, int n) {
    if (row == n) {
        print_board(board, n);
        return;
    }
    
    for (int j = 0; j < n; j++) {
        if (is_safe(board, row, j, n)) {
            board[row][j] = 'Q';
            solve_queens(board, row + 1, n);
            board[row][j] = '*';
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    
    char board[10][10];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = '*';
    
    solve_queens(board, 0, n);
    
    return 0;
}
