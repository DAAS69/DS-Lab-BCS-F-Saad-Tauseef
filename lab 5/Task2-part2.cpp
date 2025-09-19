#include<iostream>

using namespace std;

int functionB(int n);
int functionA(int n){
	if (n>=1){
		cout << n << " ";
		return functionB(n-1);
	}
	
}

int functionB(int n){
	if (n>=1){
		cout << n << " ";
		return functionA(n-2);
	}
	
}

int main(){
	cout << "demonstrating indirect recursion" << endl << endl ;
	functionA(50);


}
