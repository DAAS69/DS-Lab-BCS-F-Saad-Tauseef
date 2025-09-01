#include <iostream>
using namespace std;
void showarray(int** arr, int row, int* column){
    for(int i=0; i<row; i++){
        for (int j =0; j< column[i]; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int** arr;
    int row;
    cout << "how many students do you have: " << endl;
    cin >> row;
    arr = new int*[row];
    int column[5]; //student can have max 5 courses

    for(int i =0; i<row;i++){
    cout << "how many courses does student " << i+1 << " has: ";
   
    cin >> column[i];
        arr[i] = new int[column[i]];
    }
   
    for(int i=0; i<row ; i++){
        cout << "enter data for student " << i+1 << endl;
        for(int j=0; j<column[i]; j++){
            cout << "please enter marks for course# " << j+1 << " :" ;
            cin >> arr[i][j];
        }
    }
   
    showarray(arr, row, column);
   
    for(int i=0; i<row; i++){
        float average = 0;
        for (int j =0; j< column[i]; j++){
            average+= arr[i][j];
        }
        average /= column[i];
        cout << "average marks of student " << i+1 << " = " << average << endl;
    }
 
    for(int i =0; i<row;i++){
        delete[] arr[i];
    }
    delete[] arr;
}
