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

void convertToMaxheap(int *arr, int n){
	
	int lastparent = (n-2)/2;
	
	for (int i=lastparent;i>=0;i--){
		heapify_down(arr,i,n);
	}
}

int findKthlargest(int *arr,int n,int k){
	convertToMaxheap(arr,n);
	for (int i=1;i<k;i++){
		swap(arr[0],arr[n-i]);
		// heapify down
		heapify_down(arr,0,n-i);
	}
	
	return  arr[0];
}

int main() {
    int arr1[] = {1, 23, 12, 9, 30, 2, 50};
    int n1 = 7;
    int k1 = 3;
	cout <<"Input Array: [ ";
	for (int i=0;i<n1;i++){
		cout <<arr1[i]<<" ";
	}
	cout <<"]"<<endl;
    cout << "K-th largest element: " << findKthlargest(arr1, n1, k1) << endl << endl;


    return 0;
}