#include<iostream>

using namespace std;

int calculate_factorial(int n){
	if(n>0){
		return n*calculate_factorial(n-1);
	}
	else return 1;
}

int main(){
	int num;
	cout << "please enter the number of which you want to calculate the factorial of: " ;
	cin >> num;
	int factorial = calculate_factorial(num);
	cout << "the factorial for " << num << " is: " << factorial << endl;
}
