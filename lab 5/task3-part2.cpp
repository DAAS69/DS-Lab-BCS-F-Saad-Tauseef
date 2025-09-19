#include<iostream>

using namespace std;

int calculate_sum_nontail(int n){
	if(n>=1){
		return n+calculate_sum_nontail(n-1);

	}
	else{
		
	return n;
	}



}

int main(){
	int num;
	cout << "please enter the number of which you want to calculate the backward sum of: " ;
	cin >> num;
	int sum = calculate_sum_nontail(num);
	cout << "the backward sum for " << num << " is: " << sum << endl;
}
