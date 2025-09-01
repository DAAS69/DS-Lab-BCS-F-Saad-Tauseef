#include <iostream>
using namespace std;
void showarray(int** arr, int row, int column){
    for(int i=0; i<row; i++){
        for (int j =0; j< column; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}
int main() {
    int** arr;
    int row;
    cout << "please enter the number of rows in classroom: " << endl;
    cin >> row;
    int column;
    cout << "please enter the number of columns in each row: " << endl;
    cin >> column;
   
    arr = new int*[row];
    for(int i =0; i<row;i++){
        arr[i] = new int[column];

    }

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            arr[i][j] = 0;
        }
    }
    cout << "list of current seats available " << endl;
    showarray(arr, row, column);
   
    cout << "how many seats do you want to occupy? ";
    int seats;
    cin >> seats;
    if(seats>(row*column)){
        cout << "we have only " << row*column << " seats available in this class. please go to other class"<< endl;
        return 0;
    }
    int n,m;
    for (int i=0; i< seats; i++){
        cout << "enter row number you want to sit in: ";
        cin >> n;
        cout << "enter column number of that seat: ";
        cin >> m;
        arr[n-1][m-1] = 1;
        cout << "done." << endl;
    }
        cout << "list of current seats available " << endl;

        showarray(arr, row, column);

   
    // freeing memory
    for(int i =0; i<row;i++){
        delete[] arr[i];

    }
    delete[] arr;



}
