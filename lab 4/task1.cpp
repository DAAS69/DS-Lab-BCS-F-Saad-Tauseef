#include <iostream>
using namespace std;

int main(){
	
	
	int *arr;
	int unknown;
	int temp;
	int num;
	bool flag=false;
	
	cout << "how many elements you want in the array: ";
	cin >> num;
	
	arr = new int[num];
	
	for (int i=0;i<num;i++){
		cout << "Enter Value "<< i+1 << ": ";
		cin >> arr[i];
	}
	cout <<"Enter value to find:";
	cin >> unknown;
	
	for (int i=0;i<num;i++){
		if(arr[i]==unknown){
			temp = i;
			flag =  true;
			break;
		}
	}

	if (flag == true){
		cout <<"Value found at Index: " << temp << endl;
	}
	else{
		cout <<"value not found" << endl;
	}
	cout <<"array: ";
	for (int i=0;i<num;i++){
		cout << arr[i] << ", ";
	}
}
