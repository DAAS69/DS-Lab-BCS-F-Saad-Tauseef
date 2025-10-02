#include <iostream>
using namespace std;
int sumTail(int n,int total){
	if (n==0) return total;

    return sumTail(n-1,total+n);

}

int sumNonTail(int num){
	
	if (num==0) return 0;
	return num + sumNonTail(num-1);
	
}

int main(){
	int n;
	int total =0;
	cout << "enter value: ";
	cin >> n;
	cout << "Sum using Tail : " << sumTail(n,total) << endl;
	cout << "Sum Using Non Tail: " << sumNonTail(n) << endl;

}
	
