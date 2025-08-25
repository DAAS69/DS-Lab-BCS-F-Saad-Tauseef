#include <iostream>
using namespace std;

class Box {
    int* box_numbers;
    int box_size;

public:
    Box(int size_value) {
        box_size = size_value;
        box_numbers = new int[box_size];
        for (int i = 0; i < box_size; i++) {
            cout << "Enter number: ";
            cin >> box_numbers[i];
        }
    }

    Box(const Box& other_box) {
        box_size = other_box.box_size;
        box_numbers = new int[box_size];
        for (int i = 0; i < box_size; i++) {
            box_numbers[i] = other_box.box_numbers[i];
        }
        cout << "Object Created Using Copy Constructor\n";
    }

    Box& operator=(const Box& other_box) {
        box_size = other_box.box_size;
        box_numbers = new int[box_size];
        for (int i = 0; i < box_size; i++) {
            box_numbers[i] = other_box.box_numbers[i];
        }
        cout << "Object Created Using Copy Assignment Operator\n";
        return *this;
    }

    ~Box() {
        delete[] box_numbers;
        cout << "Destructor called\n";
    }

    void display() {
        cout << "Box contents: ";
        for (int i = 0; i < box_size; i++) {
            cout << box_numbers[i] << " ";
        }
        cout << endl;
    }

    void set(int index_value, int new_value) {
        if (index_value >= 0 && index_value < box_size) {
            box_numbers[index_value] = new_value;
        }
    }
};

int main() {
    Box b1(3);
    b1.display();
    Box b2 = b1; 
    b2.set(0, 830); 
    b2.display();
    b1.display();
    Box b3(3); 
    b3 = b1;
    b3.set(1, 172); 
    b3.display();
    b1.display();
}
