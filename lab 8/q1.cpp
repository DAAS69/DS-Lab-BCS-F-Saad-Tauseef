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

    node* findMin(node* current)
    {
        if(current->left == 0) return current;
        return findMin(current->left);
    }

    node* remove(node* current, int k)
    {
        if(current == 0) return 0;

        if(k < current->key) current->left = remove(current->left, k);
        else if(k > current->key) current->right = remove(current->right, k);
        else
        {
            if(current->left == 0 && current->right == 0)
            {
                delete current;
                return 0;
            }
            else if(current->left == 0)
            {
                node* temp = current->right;
                delete current;
                return temp;
            }
            else if(current->right == 0)
            {
                node* temp = current->left;
                delete current;
                return temp;
            }
            else
            {
                node* temp = findMin(current->right);
                current->key = temp->key;
                current->right = remove(current->right, temp->key);
            }
        }
        return current;
    }

    void inorder(node* current)
    {
        if(current == 0) return;
        inorder(current->left);
        cout << current->key << " ";
        inorder(current->right);
    }

    void preorder(node* current)
    {
        if(current == 0) return;
        cout << current->key << " ";
        preorder(current->left);
        preorder(current->right);
    }

    void postorder(node* current)
    {
        if(current == 0) return;
        postorder(current->left);
        postorder(current->right);
        cout << current->key << " ";
    }

public:
    bst() { root = 0; }

    void insert(int k) { root = insert(root, k); }
    bool search(int k) { return search(root, k) != 0; }
    void remove(int k) { root = remove(root, k); }
    void inorder() { inorder(root); cout << endl; }
    void preorder() { preorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
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

    cout << "inorder: ";
    tree.inorder();

    cout << "preorder: ";
    tree.preorder();

    cout << "postorder: ";
    tree.postorder();

    cout << "search 30: " << (tree.search(30) ? "found" : "not found") << endl;

    tree.remove(20);
    cout << "inorder after remove 20: ";
    tree.inorder();

    return 0;
}
