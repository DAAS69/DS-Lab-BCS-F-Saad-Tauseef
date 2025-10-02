#include <iostream>
using namespace std;

const int N = 9;

bool is_valid(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) return false;
    }
    int start_row = row - row % 3, start_col = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[start_row + i][start_col + j] == num) return false;
    return true;
}

bool find_empty(int grid[N][N], int &row, int &col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0) return true;
    return false;
}

bool solve_sudoku(int grid[N][N]) {
    int row, col;
    if (!find_empty(grid, row, col)) return true;
    for (int num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int grid[N][N];
    cout << "Enter the Sudoku grid (use 0 for empty cells):" << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
    if (solve_sudoku(grid)) {
        cout << "Solved Sudoku:" << endl;
        print_grid(grid);
    } else {
        cout << "No solution exists." << endl;
    }
}
