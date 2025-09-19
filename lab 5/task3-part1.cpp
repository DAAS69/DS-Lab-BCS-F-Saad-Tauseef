#include<iostream>

using namespace std;

int calculate_sum_tail(int n, int total){
	
	if(n>=1){
		total += n;
		return calculate_sum_tail(n-1,total);

	}
	else{
	return total;
	}



}

int main(){
	int num;
	cout << "please enter the number of which you want to calculate the backward sum of: " ;
	cin >> num;
	int sum = calculate_sum_tail(num,0);
	cout << "the backward sum for " << num << " is: " << sum << endl;
}
