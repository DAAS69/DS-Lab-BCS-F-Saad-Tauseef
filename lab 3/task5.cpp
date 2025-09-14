#include <iostream>
using namespace std;

class Node{
	
    public: 
    
	    int data; 
	    Node *next;
	
	    Node(int val){
	        data = val; 
	        next = NULL;
	    }
};


class Circular{
	
    public:
    	
	    int data;
	    Circular *next;
	
	    Circular(int val){
	        data = val;
	        next = NULL;
	    }
};


class Doubly{
    public: 
	    int data; 
	    Doubly *next;
	    Doubly *prev;
	
	    Doubly(int val){
	        data = val; 
	        next = NULL;
	        prev = NULL;
	    }
};


class LinkedList{
    public: 
	    Node *head;
	    Node *tail;
	
	    public: 
	    LinkedList(){
	        head = NULL;
			tail = NULL;
	    }
	
	    void pust_front(int val){
	    	
	        Node *newNode = new Node(val);
	        
	        if(head == NULL){
	        	
	            head =newNode;
		   		tail = newNode;
		   		
	            return;
	        }
	        else{ 
	        
	            newNode->next = head;
	            head = newNode;
	        }
	    }
	
	    void print(){ 
	    
	            Node *temp = head;
	
	            while(temp != NULL){
	            	
	                cout << temp->data << "  ->  ";
	                temp = temp->next;
	            }
	            
	            cout << "null " << endl;
	        }
	 
};

class DoubleLinkedList{

    public:
	    Doubly *head;
	    Doubly *tail;
	
	    public:
	    	
	    DoubleLinkedList(){
	    	
	        head = NULL;
			tail = NULL; 
	    }
	
	    void pust_front(int val){
	    	
	        Doubly *newDnode = new Doubly(val); 
	
	        if(head == NULL){
	        	
	            head = newDnode;
				 
				tail = newDnode;
	        }
	
	        else{
	        	
	            newDnode->next = head; 
	            head->prev = newDnode; 
	            head = newDnode; 
	        }
	    }
	
	    void print(){
	        Doubly *temp = head;
	
	        while(temp != NULL){
	        	
	            cout << temp->data << " <=> ";
	            temp = temp->next;
	        }
	        cout << "NULL" << endl;
	    }
	
	    DoubleLinkedList doubly_conversion(LinkedList &y){
	    	
	        Node *temp = y.head;
	        DoubleLinkedList result;
	        
	        while (temp != NULL){
	        	
	            result.pust_front(temp->data); 
	            temp = temp -> next;
	        }
	        return result;
	    }
};

class circularList{
    	public:
    	
   		Circular *head;
    	Circular *tail;

    	circularList(){
        	head = NULL;
			tail = NULL;
    }

    void pust_front(int val){
    	
        Circular *newCNode = new Circular(val);

        if(head == NULL){
        	
        	
            head =newCNode;
			 tail = newCNode;
            tail->next = newCNode;
            
        }
        else
		{
			
            newCNode->next = head;
            head = newCNode;
            tail->next = head;
        }
    }

    void print(){
    	
        if(head == NULL){
            cout << "EMPTY LIST" << endl;
            return;
        }
        
        cout << " -> ";
        cout << head->data << " -> ";
        Circular *temp = head->next;


        while(temp != head){
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << " -> " << endl;
    }


    circularList circular_conversion(LinkedList &l){
    	
    	
        Node *temp = l.head;
         circularList result;

        while(temp != NULL){
            result.pust_front(temp->data);
            temp = temp->next;
        }

        return result;
    }
};


int main(){

    LinkedList l1;
    DoubleLinkedList dl1;
    circularList cl1; 
    l1.pust_front(1);
    l1.pust_front(2);
    l1.pust_front(3);
    l1.pust_front(4);
    cout << "Singly linked list: ";
    l1.print();

    cout << "Circular linked list: ";
    cl1 = cl1.circular_conversion(l1);
    cl1.print();
    

    cout << "Doubly linked list: ";
    dl1 = dl1.doubly_conversion(l1);
    dl1.print();

}
