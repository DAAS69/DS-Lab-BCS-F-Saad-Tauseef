#include <iostream>
using namespace std;

class Node{
	
	public:
		
		int data;
		Node* next;
		
	
	Node(int val){
		data = val;
		next= nullptr;
	}
	
};

Node * merge_lists(Node * l1,Node *l2){
	
		if (l1==NULL||l2==NULL){
			if (l1==NULL){
				return l2;
			}
			else{
				return l1;
			}
		}

        if (l1->data<=l2->data){
			
			l1->next = merge_lists(l1->next,l2);
			return l1;
		}
		
		else{

            l2->next = merge_lists(l1,l2->next);
			return l2;
		}
}



class LinkedList{
	
	
	
	public:
		Node* head;
	Node* tail;
		LinkedList(){
			
			head= nullptr;
			tail = nullptr;
		}
	
		void push_front(int val){
			
			Node* newNode = new Node(val);
			
			if (head==nullptr){
				head = newNode;
				tail = newNode;
			}
			else{
				newNode->next = head; 
				head= newNode;
				
			}
		}
		
		void push_back(int val){
			
			Node * newNode = new Node(val);
			
			if (head == nullptr){
				
				head=newNode;
				tail = newNode;
				
			}
			
			else{
				tail->next = newNode;
				tail = newNode;
				
			}
		} 
		
		
		
		void pop_front(){
			
			if (head==nullptr){
				cout <<"Linked list is empty"<<endl;
				return;
			}
			else{
				Node *temp = head;
				head = head->next;
				temp->next = nullptr;
				
				delete temp;
				
				
			}
		}
		
		void pop_back(){
			
			if (head==nullptr){
				cout <<"linked list is empty"<<endl;
				return;
			}
			else{
				Node * prevNode = head;
				
				while (prevNode->next != tail){
					
					prevNode=prevNode->next;
					
					
				}
				prevNode->next = nullptr;
				delete tail;
				tail = prevNode;
			}
		}
		
		
		void insert(int val,int pos){
			if (pos<0){
				cout <<"Invalid Pos"<<endl;
				return;
			}
			else if (pos==0){
				push_front(val);
			}
			else{
				
				Node* temp= head;
				for (int i=0;i<pos-1;i++){
					temp = temp->next;
					if (temp== nullptr){
						cout<<"Invalid Pos, out of bouund"<<endl;
						return;
						
					}	
					
				}
				
				
				Node * newNode = new Node(val);
				newNode->next = temp->next;
				temp->next = newNode;
			}
		}
		void print_list(){
			Node* temp = head;
			
			while (temp!=nullptr){
				
				cout <<  temp->data<<"-> ";
				
				temp = temp->next;
			}
			cout <<"NULL"<<endl;
		}
		
		
		int search(int find){
			Node * temp = head;
			int index=0;
			while(temp!=nullptr){
				if (temp->data == find){
					return index;
				}
				else{
					temp = temp->next;
					index++;
				}
			}
			return -1;
			
		}
		
		
	void reverse_list(){
		
		Node * prev = NULL;
		Node * curr = head;
		Node * next = NULL;
		
		while(curr!=NULL){
			next =curr->next;
			curr->next = prev;
			
			prev= curr;
			curr= next;
		}
		head = prev;
	}
		
		 
};


int main(){
	LinkedList list1;
	
	list1.push_front(5);
	list1.push_front(3);
	list1.push_front(1);
	list1.print_list();

  LinkedList list2;
	cout <<endl;
	list2.push_front(6);
	list2.push_front(4);
	list2.push_front(2);
	list2.print_list();
	
	cout << "printing merged list" << endl;
	LinkedList list3;
	Node* temp=merge_lists(list1.head,list2.head);
	list3.head= temp;
	list3.print_list();
}
	
	
