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
				Node * previous_node = head;
				
				while (previous_node->next != tail){
					
					previous_node=previous_node->next;
					
					
				}
				previous_node->next = nullptr;
				delete tail;
				tail = previous_node;
			}
		}
		
		
		void insert(int val,int pos){
			if (pos<0){
				cout <<"Invalid Position."<<endl;
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
			
		
	Node* reverse(Node *head,int k){
		
		Node * temp = head;
		int count =0;

        while(count<k){
			if (temp==NULL){
				return head;
			}
			temp = temp->next;	
			count++;
		}		
		
        Node * previous_node =reverse(temp,k);

    
        temp = head;
        count =0;
        
        while(count<k){
            
            Node * next= temp->next;
            temp->next=  previous_node; 
            previous_node = temp; 
            temp = next; 
            count++;
        }
        
        head= previous_node; 
        return head;
		
		
		
	}
	
	Node * gethead(){
		return head;
	}
	
	void sethead(Node * temp){
		head= temp;
	}
		 
};




int main(){
	LinkedList list1;
	
	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);
	list1.push_front(4);
	list1.push_front(5);

	list1.print_list();
	
	Node* temp =list1.reverse(list1.gethead(),4);
	list1.sethead(temp);
	list1.print_list();
	


}
