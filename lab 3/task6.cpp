#include <iostream>
using namespace std;

class Node{
	
	public:
		
		int data;
		Node* next;
		Node * child;
			
	Node(int val){
		data = val;
		next= nullptr;
		child = NULL;
	}
	
};



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
				cout <<"linked list is empty"<<endl;
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
				Node * previous = head;
				
				while (previous->next != tail){
					
					previous=previous->next;
					
					
				}
				previous->next = nullptr;
				delete tail;
				tail = previous;
			}
		}
		
		
		void insert(int val,int pos){
			if (pos<0){
				cout <<"Invalid Position"<<endl;
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
						cout<<"Invalid Position, out of bounds"<<endl;
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
		
		Node * find(int val){
			Node * temp = head;
			while (temp!=NULL){
				if(temp->data == val)
				return temp;
			temp = temp -> next;
			}
		return NULL;
		}
		
		
		Node * gethead(){
			return head;
		}
		
 
};




Node * flatten_list(Node *head){
	
	if (head==NULL){
		return head;
	}
	
	Node *current = head;
	while(current!=NULL){
		if (current->child!=NULL){			
			Node * next = current->next;
			current->next= flatten_list(current->child);
			current->child = NULL;
			
			while (current->next!=NULL){
				current = current->next;
				
			}
					
			
			if (next!=NULL){
				current->next = next;
			}
			
		}
		
		current =  current->next;
		
	}
	return head;
}

void traverse(Node *head){
	 Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

	
}


int main(){
  
	LinkedList l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
		
	LinkedList l2;
	l2.push_back(5);
	l2.push_back(6);

	LinkedList l3;
	l3.push_back(7);
	l3.push_back(8);
	
	Node * node2 = l1.find(2);
	node2->child = l2.gethead();
	
	Node * node6 = l2.find(6);
	node6->child = l3.gethead();

	cout <<"Flattened List: "<<endl;
	 	
	Node * final = flatten_list(l1.gethead());
	traverse(final);
}
