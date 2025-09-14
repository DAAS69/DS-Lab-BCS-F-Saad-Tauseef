#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(int val) {
        Node* new_node = new Node(val);

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
    }

    void push_back(int val) {
        Node* new_node = new Node(val);

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "Linked list is empty" << endl;
            return;
        } else {
            Node* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }
    }

    void pop_back() {
        if (head == nullptr) {
            cout << "Linked list is empty" << endl;
            return;
        } else {
            Node* prev_node = head;

            while (prev_node->next != tail) {
                prev_node = prev_node->next;
            }
            prev_node->next = nullptr;
            delete tail;
            tail = prev_node;
        }
    }

    void insert(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position" << endl;
            return;
        } else if (pos == 0) {
            push_front(val);
        } else {
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
                if (temp == nullptr) {
                    cout << "Invalid position, out of bound" << endl;
                    return;
                }
            }

            Node* new_node = new Node(val);
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    void print_ll() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int search(int value) {
        Node* temp = head;
        int index = 0;

        while (temp != nullptr) {
            if (temp->data == value) {
                return index;
            } else {
                temp = temp->next;
                index++;
            }
        }
        return -1;
    }

    Node* reverse_new() {
        Node* new_head = nullptr;
        Node* temp = head;

        while (temp != nullptr) {
            int val = temp->data;
            Node* new_node = new Node(val);

            new_node->next = new_head;
            new_head = new_node;
            temp = temp->next;
        }
        return new_head;
    }

    void is_palin() {
        Node* rev = reverse_new();
        Node* org = head;

        while (rev != nullptr && org != nullptr) {
            if (rev->data != org->data) {
                cout << "Is not palindrome." << endl;
                return;
            }
            rev = rev->next;
            org = org->next;
        }
        cout << "Is palindrome." << endl;
    }

    Node* get_head() {
        return head;
    }

    void set_head(Node* temp) {
        head = temp;
    }
};

int main() {
    LinkedList list1;

    list1.push_front(100);
    list1.push_front(500);
    list1.push_front(10);
    list1.push_front(500);
    list1.push_front(100);
    list1.print_ll();

    list1.is_palin();

    LinkedList list2;

    list2.push_front(10);
    list2.push_front(20);
    list2.push_front(30);
    list2.push_front(40);
    list2.push_front(50);
    list2.print_ll();

    list2.is_palin();

    return 0;
}
