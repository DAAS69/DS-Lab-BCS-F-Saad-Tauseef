#include <iostream>
using namespace std;


void selection_sort(int* arr,int size){
	
	
	for (int i=0;i<size-1;i++){
		int x = i;

		for (int j = i+1; j < size; j++) {

			if (arr[j] < arr[x]) {
				x = j;
			}
		}
		
		int temp;
		temp = arr[i];
		arr[i] = arr[x];
		arr[x] = temp;

	}
}

void print_array(int* arr,int size){
	
	for (int i=0;i<size;i++){
		cout << arr[i] << " ";
	
	}

	cout << endl;
}
int main(){
	
	int num;
	int *array;
	cout << "How many elements do you want in the array: ";
	cin >> num;
	
	array = new int[num];
	
	for(int i=0;i<num;i++){
		cout << "Enter Value " << i+1 << ": ";
		cin >> array[i];
	}
	
	cout << "Unsorted Array:" << endl;
	print_array(array,num);

	selection_sort(array,num);

	cout << "Sorted Array:" << endl;

	print_array(array,num);
	
}
