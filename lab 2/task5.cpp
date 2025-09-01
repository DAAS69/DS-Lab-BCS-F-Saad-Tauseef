#include <iostream>
using namespace std;

int** add_matrix(int** matrix_1, int row_1, int col_1, int** matrix_2, int row_2, int col_2) {
    if (row_1 == row_2 && col_1 == col_2) {
        int** result = new int*[row_1];
        for (int i = 0; i < row_1; i++) {
            result[i] = new int[col_1];
        }

        cout << "Adding Both Matrix." << endl;

        for (int i = 0; i < row_1; i++) {
            for (int j = 0; j < col_1; j++) {
                result[i][j] = matrix_1[i][j] + matrix_2[i][j];
            }
        }

        cout << "Printing Resultant Matrix." << endl;

        for (int i = 0; i < row_1; i++) {
            for (int j = 0; j < col_1; j++) {
                cout << " " << result[i][j] << " ";
            }
            cout << endl;
        }

        return result;
    } else {
        cout << "Both Matrix does not have same dimensions!" << endl;
        cout << "Cannot Do Addition!" << endl;
        return nullptr;
    }
}

int** sub_matrix(int** matrix_1, int row_1, int col_1, int** matrix_2, int row_2, int col_2) {
    if (row_1 == row_2 && col_1 == col_2) {
        int** result = new int*[row_1];
        for (int i = 0; i < row_1; i++) {
            result[i] = new int[col_1];
        }

        cout << "Subtracting Both Matrix." << endl;

        for (int i = 0; i < row_1; i++) {
            for (int j = 0; j < col_1; j++) {
                result[i][j] = matrix_1[i][j] - matrix_2[i][j];
            }
        }

        cout << "Printing Resultant Matrix." << endl;

        for (int i = 0; i < row_1; i++) {
            for (int j = 0; j < col_1; j++) {
                cout << " " << result[i][j] << " ";
            }
            cout << endl;
        }

        return result;
    } else {
        cout << "Both Matrix does not have same dimensions!" << endl;
        cout << "Cannot Do Subtraction!" << endl;
        return nullptr;
    }
}

int main() {
    int** arr_1;
    int row_1, row_2, col_1, col_2;
    int** arr_2;
    int** result;

    cout << "Enter Rows and Columns for Matrix 1: ";
    cin >> row_1 >> col_1;

    cout << "Enter Rows and Columns for Matrix 2: ";
    cin >> row_2 >> col_2;

    arr_1 = new int*[row_1];
    arr_2 = new int*[row_2];

    for (int i = 0; i < row_1; i++) {
        arr_1[i] = new int[col_1];
    }

    for (int i = 0; i < row_2; i++) {
        arr_2[i] = new int[col_2];
    }

    cout << "Enter Data for Matrix 1." << endl;
    for (int i = 0; i < row_1; i++) {
        for (int j = 0; j < col_1; j++) {
            cout << "Enter Data for Position: (" << i+1 << "," << j+1 << "): ";
            cin >> arr_1[i][j];
        }
    }

    cout << "Enter Data for Matrix 2." << endl;
    for (int i = 0; i < row_2; i++) {
        for (int j = 0; j < col_2; j++) {
            cout << "Enter Data for Position: (" << i+1 << "," << j+1 << "): ";
            cin >> arr_2[i][j];
        }
    }

    cout << "2 Matrices are Made. Printing both." << endl;
    cout << "Matrix 1" << endl;
    for (int i = 0; i < row_1; i++) {
        for (int j = 0; j < col_1; j++) {
            cout << " " << arr_1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix 2" << endl;
    for (int i = 0; i < row_2; i++) {
        for (int j = 0; j < col_2; j++) {
            cout << " " << arr_2[i][j] << " ";
        }
        cout << endl;
    }

    result = add_matrix(arr_1, row_1, col_1, arr_2, row_2, col_2);
    if (result) {
        for (int i = 0; i < row_1; i++) {
            delete[] result[i];
        }
        delete[] result;
    }

    result = sub_matrix(arr_1, row_1, col_1, arr_2, row_2, col_2);
    if (result) {
        for (int i = 0; i < row_1; i++) {
            delete[] result[i];
        }
        delete[] result;
    }

    for (int i = 0; i < row_1; i++) {
        delete[] arr_1[i];
    }
    delete[] arr_1;

    for (int i = 0; i < row_2; i++) {
        delete[] arr_2[i];
    }
    delete[] arr_2;
}
