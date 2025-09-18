#include <iostream>
using namespace std;

void bubble_sort(int* arr,int size){
	
	bool shift = false;
	int temp;
	
	while (!shift){
		
		shift = true;
		
		for(int i=0;i<size-1;i++){
			
			if (arr[i]>arr[i+1]){
				temp = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = temp;
				shift = false;
			}	
		}
	}
	
}

void print_array(int* arr,int size){
	
	for (int i=0;i<size;i++){
		cout << arr[i] <<" ";
	
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

	cout << "Sorted Array:" << endl;
	bubble_sort(array,num);

	print_array(array,num);	
	
}
