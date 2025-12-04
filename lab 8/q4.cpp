#include <iostream>
using namespace std;

class node
{
public:
    int key;
    node* left;
    node* right;
    node(int k)
    {
        key = k;
        left = 0;
        right = 0;
    }
};

class bst
{
private:
    node* root;

    node* insert(node* current, int k)
    {
        if(current == 0) return new node(k);
        if(k < current->key) current->left = insert(current->left, k);
        else current->right = insert(current->right, k);
        return current;
    }

    node* search(node* current, int k)
    {
        if(current == 0) return 0;
        if(current->key == k) return current;
        if(k < current->key) return search(current->left, k);
        return search(current->right, k);
    }

    void inorder(node* current)
    {
        if(current == 0) return;
        inorder(current->left);
        cout << current->key << " ";
        inorder(current->right);
    }

public:
    bst() { root = 0; }

    void insert(int k) { root = insert(root, k); }
    bool search(int k) { return search(root, k) != 0; }
    void inorder() { inorder(root); cout << endl; }
};

int main()
{
    bst tree;

    tree.insert(40);
    tree.insert(20);
    tree.insert(60);
    tree.insert(10);
    tree.insert(30);
    tree.insert(50);
    tree.insert(70);

    cout << "current tree inorder: ";
    tree.inorder();

    int val;
    cout << "enter value to search: ";
    cin >> val;

    if(tree.search(val))
        cout << val << " found in the tree" << endl;
    else
    {
        cout << val << " not found, inserting..." << endl;
        tree.insert(val);
        cout << "new tree inorder: ";
        tree.inorder();
    }

    return 0;
}
