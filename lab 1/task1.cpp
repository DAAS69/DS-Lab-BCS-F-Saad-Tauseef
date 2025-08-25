#include <iostream>
using namespace std;

class BankAccount {
private:
    double account_balance;

public:
    BankAccount() {
        account_balance = 0.0;
    }

    BankAccount(double initial_balance) {
        account_balance = initial_balance;
    }

    BankAccount(const BankAccount &other_account) {
        account_balance = other_account.account_balance;
    }

    void deduct_amount(double amount) {
        cout << "deducting amount..." << endl;
        account_balance -= amount;
    }

    double get_balance() {
        return account_balance;
    }
};

int main() {
    BankAccount account1;
    cout << "Balance of account 1: " << account1.get_balance() << endl;

    BankAccount account2(1000.0);
    cout << "Balance of account 2: " << account2.get_balance() << endl;

    BankAccount account3(account2);
    account3.deduct_amount(200.0);
    cout << "Balance of account 3: " << account3.get_balance() << endl;
    cout << "Balance of account 2 is still: " << account2.get_balance() << endl;

}
