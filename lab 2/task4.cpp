#include <iostream>
using namespace std;

int* resize_arr(int* arr, int old_size, int new_size);

int main(){
    int* expenses;
    int total_months;
    float total_expense = 0.0, avg_expense = 0.0;
    string user_choice;

    cout << "Enter Number of Months: ";
    cin >> total_months;

    expenses = new int[total_months];
    cout << "enter month wise expense." << endl;

    for (int i = 0; i < total_months; i++) {
        cout << "Enter Expenses for Month " << i+1 << ": ";
        cin >> expenses[i];
    }

    cout << "Do you want to add more Data for More months (yes/no): ";
    cin >> user_choice;

    if (user_choice == "yes") {
        int add_months;
        cout << "How many months do you want to add? ";
        cin >> add_months;
        expenses = resize_arr(expenses, total_months, total_months + add_months);

        for (int i = total_months; i < total_months + add_months; i++) {
            cout << "Enter Expenses for Month " << i+1 << ": ";
            cin >> expenses[i];
        }
        total_months = total_months + add_months;
    }

    cout << "PRINTING DATA FOR ALL MONTHS." << endl;

    for (int i = 0; i < total_months; i++) {
        cout << "Expense for Month " << i+1 << ": $ " << expenses[i] << endl;
        total_expense = total_expense + expenses[i];
    }

    cout << "Your total Expense for all months were: $ " << total_expense << endl;
    avg_expense = total_expense / total_months;
    cout << "Your avg expense Per month was : $ " << avg_expense << endl;

    delete [] expenses;
}

int* resize_arr(int* arr, int old_size, int new_size) {
    if (old_size == new_size) {
        return arr;
    }
    int* temp = new int[new_size];
    if (old_size < new_size) {
        for (int i = 0; i < old_size; i++) {
            temp[i] = arr[i];
        }
    } else {
        for (int i = 0; i < new_size; i++) {
            temp[i] = arr[i];
        }
    }
    delete [] arr;
    return temp;
}
