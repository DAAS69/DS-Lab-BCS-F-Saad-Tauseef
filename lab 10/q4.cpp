#include <iostream>
using namespace std;

class Product{
	private:
		string name;
		float price;
		string desc;
		bool avb;
		
	public:
		Product(){
			
		}
		Product(string namep,float pricep,string descp,bool avbp){
			name = namep;
			price = pricep;
			desc= descp;
			avb=avbp;
		}
		
		string get_name(){
			return name;
		}
		
		float get_price(){
			return price;
		}
};


int partition(Product *arr,int start,int end){
	
	int idx=start-1;
	int pivot = arr[end].get_price();
	
	for (int j=start;j<end;j++){
		if (arr[j].get_price()<=pivot){
			idx++;
			swap(arr[j],arr[idx]);
		}
	}
	idx++;
	swap(arr[end],arr[idx]);
	return idx;
}


void quickSort(Product *arr,int start, int end){
	
	if (start <end){
		int pivIdx = partition(arr,start,end);
		quickSort(arr,start,pivIdx-1);
		quickSort(arr,pivIdx+1,end);
	}
	
}


int main(){
	Product Proc[3];
	Proc[0]=Product("Product 1",10.99,"This is Product 1.",true);
	Proc[1]=Product("Product 2",5.99,"This is Product 2.",false);
	Proc[2]=Product("Product 3",2.99,"This is Product 3.",true);
	
	quickSort(Proc,0,2);
	cout <<"Products sorted by Price:"<<endl;
	for (int i=0;i<3;i++){
		cout <<Proc[i].get_name()<<" - $"<<Proc[i].get_price()<<endl;
	}
	
}