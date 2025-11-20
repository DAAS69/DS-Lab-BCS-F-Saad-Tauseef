#include <iostream>
using namespace std;

class Runner{
	private:
		string name;
		int times;
		
	public:
		Runner(){}
		Runner(string namep,int timesp){
			name = namep;
			times = timesp;
		}
		string get_name(){
			return name;
		}
		int get_time(){
			return times;
		}
};

void merge(Runner *arr,int start,int mid,int end){
	
	Runner temp[end-start+1];
	int index=0;
	int i=start;
	int j=mid+1;
	
	while (i<=mid && j<=end){
		
		if (arr[i].get_time()<arr[j].get_time()){
			temp[index]=arr[i];
			i++;
			index++;
		}
		else{
			temp[index]=arr[j];
			j++;
			index++;
		}
	}
	
	while (i<=mid){
		temp[index]=arr[i];
			i++;
			index++;
	}
	
	while (j<=end){
		temp[index]=arr[j];
		j++;
		index++;
		
	}
	
	for (int idx=0;idx<(end-start+1);idx++){
		arr[start+idx]=temp[idx];
		
	}
}

void mergeSort(Runner * arr,int start,int end ){
	
	if (start<end){
		int mid = start + (end-start)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}


int main(){
	string name;
	int time;
	Runner arr[10];
	for (int i=0;i<10;i++){
		cout <<"Enter Name and finish time for Runner "<<i+1<<": ";
		cin >>name;
		cin >> time;
		arr[i] = Runner(name,time);
	}
	
	mergeSort(arr,0,9);
	cout <<"Top 5 Fastest Runners: "<<endl;
	for (int i=0;i<5;i++){
		cout <<i+1<<". "<< arr[i].get_name()<<" - "<<arr[i].get_time()<<" seconds"<<endl;
	}
}