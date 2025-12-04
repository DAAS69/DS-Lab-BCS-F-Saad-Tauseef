#include <iostream>
using namespace std;


int bruteforce(string text,string pattern){
	int n  = text.length();
	int m = pattern.length();
	
	for (int i=0;i<=n-m;i++){
		
		int j=0;
		while (j<m && text[i+j]== pattern[j]){
			j++;
		}
		if (j==m){
			cout <<i<<" ";
		}
	}
}
int main(){
	string text = "the quick brown fox jumps over the lazy dog";
	string pattern = "the";
	cout <<"Found at following Index: ";
	bruteforce(text,pattern);
	
	
}
