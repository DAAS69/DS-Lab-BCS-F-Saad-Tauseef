#include <iostream>
using namespace std;

class node
{
public:
    int key;
    node* left;
    node* right;
    int height;
    node(int k){ key=k; left=0; right=0; height=1;}
};

int height(node* n){ return n? n->height:0;}
int getBalance(node* n){ return n? height(n->left)-height(n->right):0;}

node* rightRotate(node* y){ node* x=y->left; node* t=x->right; x->right=y; y->left=t; y->height=max(height(y->left),height(y->right))+1; x->height=max(height(x->left),height(x->right))+1; return x;}
node* leftRotate(node* x){ node* y=x->right; node* t=y->left; y->left=x; x->right=t; x->height=max(height(x->left),height(x->right))+1; y->height=max(height(y->left),height(y->right))+1; return y;}

node* insert(node* root,int key)
{
    if(root==0) return new node(key);
    if(key<root->key) root->left=insert(root->left,key);
    else if(key>root->key) root->right=insert(root->right,key);
    else return root;
    root->height=1+max(height(root->left),height(root->right));
    int balance=getBalance(root);
    if(balance>1 && key<root->left->key) return rightRotate(root);
    if(balance<-1 && key>root->right->key) return leftRotate(root);
    if(balance>1 && key>root->left->key){ root->left=leftRotate(root->left); return rightRotate(root);}
    if(balance<-1 && key<root->right->key){ root->right=rightRotate(root->right); return leftRotate(root);}
    return root;
}

void inorder(node* root, int arr[], int &i)
{
    if(root==0) return;
    inorder(root->left,arr,i);
    arr[i++]=root->key;
    inorder(root->right,arr,i);
}

int kthSmallest(node* root,int k)
{
    int arr[100]; int i=0;
    inorder(root,arr,i);
    return arr[k-1];
}

int kthLargest(node* root,int k)
{
    int arr[100]; int i=0;
    inorder(root,arr,i);
    return arr[i-k];
}

int main()
{
    node* root=0;
    int arr[]={50,30,70,20,40,60,80};
    for(int i=0;i<7;i++) root=insert(root,arr[i]);

    int k; cout << "enter k: "; cin >> k;

    cout << k << "th smallest: " << kthSmallest(root,k) << endl;
    cout << k << "th largest: " << kthLargest(root,k) << endl;

    cout << "left height of root: " << height(root->left) << endl;
    cout << "right height of root: " << height(root->right) << endl;

    return 0;
}
