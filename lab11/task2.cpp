#include <iostream>
#include <string>
using namespace std;

class Node{
	public:
		string key;
		string value;
		Node* next;
		Node(string k,string v){
		key=k;
		value=v;
		next=NULL;
}
};

class Dictionary{
	private:
	static const int SIZE=100;
	Node* table[SIZE];
	
	int hashFunction(string s){
	int sum=0;
	for(int i=0;i<s.length();i++) sum+=(int)s[i];
	return sum%SIZE;
}

	public:
	Dictionary(){
		for(int i=0;i<SIZE;i++) table[i]=NULL;
	}
	
	void Add_Record(string key,string value){
		int index=hashFunction(key);
		Node* n=new Node(key,value);
		n->next=table[index];
		table[index]=n;
	}
	
	void Word_Search(string key){
		int index=hashFunction(key);
		Node* c=table[index];
		while(c!=NULL){
		if(c->key==key){
		cout<<"search key "<<key<<": "<<c->value<<endl;
		return;
	}
	c=c->next;}
	cout<<"Error: word not found!"<<endl;	}
	
	void Delete_Word(string key){
		int index=hashFunction(key);
		Node* c=table[index];
		Node* p=NULL;
		while(c!=NULL){
		if(c->key==key){
		if(p==NULL) table[index]=c->next;
		else p->next=c->next;
		delete c;
		cout<<"key "<<key<<" deleted successfully !"<<endl;
	return;	}
	
	p=c;
	c=c->next;
	}
	
	cout<<"Error: key not found!"<<endl;
	}
	
	void Print_Dictionary(){
		for(int i=0;i<SIZE;i++){
		Node* c=table[i];
		if(c!=NULL){
		cout<<"index "<<i<<": ";
		while(c!=NULL){
		cout<<"("<<c->key<<", "<<c->value<<") ";
		c=c->next;	}
		
	cout<<endl;	}
	
	}
	}
};

int main(){
	Dictionary d;
	
	d.Add_Record("AB","FASTNU");
	d.Add_Record("CD","CS");
	d.Add_Record("EF","EE");
	
	d.Word_Search("AB");
	
	d.Delete_Word("EF");
	
	d.Print_Dictionary();

return 0;
}
