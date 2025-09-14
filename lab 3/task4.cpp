#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node * next;
		
		Node(int val){
			data = val;
			next = NULL;
		}
		
};

class CircularList{
	
	Node * head;
	Node * tail;
		
	public:
		
		CircularList(){
			head=NULL;
			tail = NULL;	
		}
		
		
		void push_back(int val){
			Node * newNode = new Node(val);
			
			if (head==NULL){
				head=newNode;
				tail = newNode;
				tail->next= head;
			}
			else{
				newNode->next=  head;
				tail->next = newNode;
				tail = newNode;
			}
		}
		
		void print_list(){
			
			if (head==NULL){
				cout <<"linked list is empty"<<endl;
				return ;
			}
			
			Node* temp = head;
			do {
    			cout << temp->data << "->";
    			temp = temp->next;
    			
			} while (temp != head);
			
			cout << "back to the first person" << endl;
		}
		
		
		void position(int x){
			if(head==NULL){
				cout <<"linked list is empty"<<endl;
				return;
				
			}
			if (x<=0){
				cout <<"Invalid Position."<<endl;
				return;
			}
			
			Node *temp =head;
			Node *prev= tail;
			
			
			while(head!=tail){
				
				for (int i=0;i<x-1;i++){
					prev = temp;
					temp = temp->next;
					
				}
				
				Node * value = temp;
				prev->next=  temp->next;
				temp = temp->next;
				
				if (value==head){
					head= head->next;
					
				}
				if (value == tail){
					tail = prev;
				}
				delete value;
			}
			
			cout <<"THE SURVIVOR IS "<<head->data<<endl;
		}
		
		
};


int main(){
	
	CircularList l1;
	
	int N=5;
	int k=3;
	
	l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);

	cout <<"Players are: ";
	l1.print_list();
	
	l1.position(k);
}
