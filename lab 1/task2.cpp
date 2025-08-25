#include <iostream>
#include <cstring>
using namespace std;

class Exam {
    char* student_name;
    string exam_date;
    int exam_score;

public:
    Exam(char* name) {
        student_name = new char[strlen(name) + 1];
        strcpy(student_name, name);
    }

    void set_date(string date_value) {
        exam_date = date_value;
        cout << "Date set to : " << exam_date << endl;
    }

    void set_score(int score_value) {
        exam_score = score_value;
        cout << "Score is set to : " << exam_score << endl;
    }

    void get_name() {
        cout << "Name : " << student_name << endl;
    }

    void get_date() {
        cout << "Date : " << exam_date << endl;
    }

    void get_score() {
        cout << "Score : " << exam_score << endl;
    }

    ~Exam() {
        delete[] student_name;
        cout << "Destructor called" << endl;
    }
};

int main() {
    Exam e1("Saad Tauseef");
  
    e1.set_date("25/08/25");
  
    e1.set_score(96);

    Exam e2 = e1;  
    e2.get_name();
    e2.get_date();
    e2.get_score();
}
