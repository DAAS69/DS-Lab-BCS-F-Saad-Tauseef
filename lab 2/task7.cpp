#include <iostream>
using namespace std;

int main() {
    float** arr;
    int num_departments;

    cout << "Enter Total Number of Departments: ";
    cin >> num_departments;

    int num_emps[num_departments];
    float avg_depart[num_departments];

    arr = new float*[num_departments];

    for (int i = 0; i < num_departments; i++) {
        cout << "Enter Number of Employees for Department " << i+1 << ": ";
        cin >> num_emps[i];
        arr[i] = new float[num_emps[i]];
    }

    cout << "Enter Employee Salary Department Wise." << endl;

    for (int i = 0; i < num_departments; i++) {
        for (int j = 0; j < num_emps[i]; j++) {
            cout << "Enter Salary of Employee " << j+1 << " from Department " << i+1 << " : ";
            cin >> arr[i][j];
        }
    }

    cout << "Printing Data for All Employees." << endl;

    for (int i = 0; i < num_departments; i++) {
        for (int j = 0; j < num_emps[i]; j++) {
            cout << " " << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < num_departments; i++) {
        float highest_salary = 0.0;
        float total_salary = 0.0;
        int pos_x, pos_y;
        for (int j = 0; j < num_emps[i]; j++) {
            total_salary = total_salary + arr[i][j];
            if (arr[i][j] > highest_salary) {
                highest_salary = arr[i][j];
                pos_x = i;
                pos_y = j;
            }
        }
        avg_depart[i] = total_salary / num_emps[i];

        cout << "Highest Salary for Department " << i+1 
             << " was: RS " << highest_salary 
             << " at position (" << pos_x+1 << "," << pos_y+1 << ")" << endl;

        total_salary = 0;
        highest_salary = 0;
    }

    float highest_avg_depart = 0;
    int depart_index;
    for (int i = 0; i < num_departments; i++) {
        if (avg_depart[i] > highest_avg_depart) {
            highest_avg_depart = avg_depart[i];
            depart_index = i;
        }
    }

    cout << "Department with Highest Average Salary was Department No: " 
         << depart_index+1 << " with Avg Salary of RS " << highest_avg_depart;

    for (int i = 0; i < num_departments; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
