#include <iostream>
using namespace std;

class SafePointer {
	
	private:
		
    	int* ptr;
    
	public:
		
	    SafePointer() {
	        ptr = new int;
	    }
    
	    void set_value(int value) {
	        *ptr = value;
	    }
	    
	    int get_value() {
	        return *ptr;
	    }
	    
	    void release() {
	        delete ptr;
	        ptr = nullptr;
	    }
	    
	    ~SafePointer() {
	        if (ptr != nullptr) {
	            delete ptr;
	        }
	    }
};

int main() {
    int num_std = 5;
    SafePointer* marks = new SafePointer[num_std];

    for (int i = 0; i < num_std; i++) {
        int student_marks;
        cout << "Enter marks for Student " << i + 1 << ": ";
        cin >> student_marks;
        marks[i].set_value(student_marks);
    }

    cout << "Recorded Marks:" << endl;

    for (int i = 0; i < num_std; i++) {
        cout << "Student " << i + 1 << ": " << marks[i].get_value() << endl;
    }

    for (int i = 0; i < num_std; i++) {
        marks[i].release();
    }

    delete[] marks;
}
