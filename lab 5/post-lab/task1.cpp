#include <iostream>
using namespace std;


int factorial(int x){
	
	if (x==1) return x;
	
	if (x==0) return 1;
	
	return x*factorial(x-1);
}

int main(){
	int value;
	cout <<"Enter the value to find the factorial of: ";
	cin >> value;
	int fac =  factorial(value);
	cout <<"The Factorial is: " << fac << endl;
	
}
