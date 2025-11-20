#include <iostream>
using namespace std;


void heapify_down(int *arr,int i,int n){
	int l=2*i+1;
	int r=2*i+2;
	int largest =i;
	
	if (l<n && arr[l]>arr[largest]){
			largest = l;
			}
	if(r<n && arr[r]>arr[largest]){
			largest = r;
			}
			
	if (largest != i){
			swap(arr[i],arr[largest]);
			heapify_down(arr,largest,n);
			}
}

void MinToMax(int *arr, int n){
	
	int lastparent = (n-2)/2;
	
	for (int i=lastparent;i>=0;i--){
		heapify_down(arr,i,n);
	}
}

int main(){
	int arr[]={3,5,9,6,8,20,10,12,18,9};
	int n = 10;
	
	MinToMax(arr,n);
	
	for (int i=0;i<n;i++){
		cout <<arr[i]<<" ";
	}
	cout <<endl;
}