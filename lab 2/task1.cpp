#include <iostream>
using namespace std;
void showarray(int* arr, int size){
    for(int i=0; i<size; i++){
        cout << "element: " << i << " is: " << arr[i] << endl;
    }
}
int main() {
    int* arr;
    int size;
    cout << "please enter the size of array: " << endl;
    cin >> size;
    arr = new int[size];
    for(int i=0; i<size; i++){
        arr[i] = 0;
    }
    showarray(arr,size);
    cout << "which element will you like to change in the array: ";
    int n;
    cin >> n;
    if(n> size){
        cout << "cannot acces that elment as it is out of bound" << endl;
        return 0;
    }
   
    cout << "please enter the new value: " ;
    int m;
    cin >> m;
     arr[n] = m;
     
        showarray(arr,size);

    delete[] arr;
   

}
