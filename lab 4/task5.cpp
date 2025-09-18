#include <iostream>
using namespace std;

int interpolation_search(int* arr,int size,int x){
	int low = 0;
	int high = size - 1;
	while(low<=high && x >= arr[low] && x <= arr[high]){
		if(low==high){
			if(arr[low]==x){
				return low;
			}
			return -1;
		}
		int pos = low + ((x-arr[low])*(high-low)) / (arr[high]-arr[low]);
		if(arr[pos] == x){
			return pos;
		}

		if(arr[pos]<x){
			low = pos + 1;
		}


		else {
			high = pos - 1;
		}
	}
	return -1;
}
void insertion_sort(int* arr,int size){
	
	int x; // curent  
	int y; // previous
	
	
	for(int i=1;i<size;i++){
		x= arr[i];  
		y= i-1; 
		
		while(y >= 0 && arr[y] > x){ 
			arr[y+1] = arr[y]; 
			
			y--;
		
		}
		
		arr[y+1] = x; 
		
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
	int x;
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
	insertion_sort(array,num);

	print_array(array,num);

	cout << "Enter value to find: ";
	cin >> x;

	int index = interpolation_search(array,num,x);

	if (index != -1){
		cout << "Value found at index :" << index << endl;
	}
	else {
		cout << "Value Not Found in the Array." << endl;
	}
	
}
