#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    string key;
    string value;
    node* next;
    node(string k, string v)
    {
        key = k;
        value = v;
        next = 0;
    }
};

class hashTable
{
private:
    static const int bucketCount = 10;
    node* table[bucketCount];

    int hashFunc(string key)
    {
        int sum = 0;
        for(int i=0;i<key.length();i++) sum += key[i];
        return sum % bucketCount;
    }

public:
    hashTable()
    {
        for(int i=0;i<bucketCount;i++) table[i] = 0;
    }

    void insert(string key, string value)
    {
        int idx = hashFunc(key);
        node* n = new node(key,value);
        if(table[idx] == 0) table[idx] = n;
        else
        {
            node* temp = table[idx];
            while(temp->next != 0) temp = temp->next;
            temp->next = n;
        }
        cout << "inserted (" << key << "," << value << ") at bucket " << idx << endl;
    }

    void display()
    {
        for(int i=0;i<bucketCount;i++)
        {
            cout << "bucket " << i << ": ";
            node* temp = table[i];
            while(temp)
            {
                cout << "[" << temp->key << ":" << temp->value << "] -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    hashTable myhash;

    myhash.insert("A","aaaaa");
    myhash.insert("B","bbbbb");
    myhash.insert("C","ccccc");
    myhash.insert("A","zzzzz");

    cout << endl << "hash table contents:" << endl;
    myhash.display();

    return 0;
}
