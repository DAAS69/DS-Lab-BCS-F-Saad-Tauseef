#include <iostream>
using namespace std;

int main() {
    int **matrix;
    int non_zero = 0;
    int num_rows, num_cols;

    cout << "Enter number of rows: ";
    cin >> num_rows;

    cout << "Enter number of columns: ";
    cin >> num_cols;

    matrix = new int*[num_rows];
    for (int i = 0; i < num_rows; i++) {
        matrix[i] = new int[num_cols];
    }

    cout << "Enter Values for the Matrix." << endl;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            cout << "Enter Value for (" << i << "," << j << "): ";
            cin >> matrix[i][j];
            if (matrix[i][j] != 0) {
                non_zero++;
            }
        }
    }

    int **compressed = new int*[non_zero];
    for (int i = 0; i < non_zero; i++) {
        compressed[i] = new int[3];  // row, col, value
    }

    cout << "\nNormal Matrix:" << endl;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            cout << " " << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int count = 0;
    cout << "\nCompressed Form (row, col, value):" << endl;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (matrix[i][j] != 0) {
                compressed[count][0] = i;
                compressed[count][1] = j;
                compressed[count][2] = matrix[i][j];
                count++;
            }
        }
    }

    for (int i = 0; i < non_zero; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << compressed[i][j] << " ";
        }
        cout << endl;
    }

    // Freeing memory
    for (int i = 0; i < num_rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < non_zero; i++) {
        delete[] compressed[i];
    }
    delete[] compressed;
}
