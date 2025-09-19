#include<iostream>

using namespace std;

int print_numbers(int n){
	if(n>=1){
		cout << n << " ";
		return print_numbers(n-1);
	}



}

int main(){
	int num;
	cout << "please enter the number of which you want to print backward till 1: " ;
	cin >> num;
	print_numbers(num);

}
