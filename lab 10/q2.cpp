#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int val){
		data=val;
		next=nullptr;
	}
};
void insertBucket(Node *&head,int val){
	Node *newNode=new Node(val);
	if(head==nullptr){
		head=newNode;
		return;
	}
	Node *temp=head;
	while(temp->next!=nullptr){
		temp=temp->next;
	}
	temp->next=newNode;
}
void deleteBucket(Node *&head){
	Node *temp=head;
	Node *next=nullptr;
	while(temp!=nullptr){
		next=temp->next;
		delete temp;
		temp=next;
	}
}
int getMax(int arr[],int size){
	int max=arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
void increasingRadixSort(int arr[],int size){
	int max=getMax(arr,size);
	int exp=1;
	Node *bucket[10];
	while(max/exp>0){
	for(int i=0;i<10;i++){
		bucket[i]=nullptr;
	}
	for(int i=0;i<size;i++){
		int dig=(arr[i]/exp)%10;
		insertBucket(bucket[dig],arr[i]);
	}
	int id=0;
	for(int i=0;i<10;i++){
		Node *temp=bucket[i];
		while(temp!=nullptr){
			arr[id++]=temp->data;
			temp=temp->next;
		}
		deleteBucket(bucket[i]);
	}
	exp *=10;
	}
}
void decreasingRadixSort(int arr[],int size){
	int max=getMax(arr,size);
	int exp=1;
	Node *bucket[10];
	while(max/exp>0){
	for(int i=0;i<10;i++){
		bucket[i]=nullptr;
	}
	for(int i=0;i<size;i++){
		int dig=(arr[i]/exp)%10;
		insertBucket(bucket[dig],arr[i]);
	}
	int id=0;
	for(int i=9;i>=0;i--){
		Node *temp=bucket[i];
		while(temp!=nullptr){
			arr[id++]=temp->data;
			temp=temp->next;
		}
		deleteBucket(bucket[i]);
	}
	exp *=10;
	}
}
int main(){
int arr[]={36,987,654,2,20,99,456,957,555,420,66,3};
increasingRadixSort(arr,12);
cout<<"Increasing Order : "<<endl;
for(int i=0;i<12;i++){
	cout<<arr[i]<<" ";
}
cout<<endl;
cout<<"Decreasing Order : "<<endl;
decreasingRadixSort(arr,12);
for(int i=0;i<12;i++){
	cout<<arr[i]<<" ";
}
}