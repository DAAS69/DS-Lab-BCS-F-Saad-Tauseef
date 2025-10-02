#include <iostream>
using namespace std;

void printNumbers(int n){
	
	if (n==0) return;
	cout << n << endl;
	printNumbers(n-1);
	
	
}

void functionB(int n);

void functionA(int n){
	if (n==0) return;
	cout << n << endl;
	functionB(n-1);
}

void functionB(int n){

	if (n==0) return;

	cout << n << endl;
	functionA(n-1);

	
}

int main(){
	int num;
	cout << "enter any number: ";
	cin >> num;
	cout << "printing number in reversed order using direct recursion: " << endl;
	printNumbers(num);
	cout << "printing number in reversed order using indirect recursion: " << endl;
	functionB(num);
	
}
