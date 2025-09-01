#include <iostream>
using namespace std;

int main() {
    int num_categories;
    cout << "Enter number of categories to store: ";
    cin >> num_categories;

    int *num_books = new int[num_categories];
    int **books = new int*[num_categories];

    for (int i = 0; i < num_categories; i++) {
        cout << "Enter number of books in Category " << i + 1 << ": ";
        cin >> num_books[i];

        books[i] = new int[num_books[i]];

        for (int j = 0; j < num_books[i]; j++) {
            cout << "Enter Book ID for Category " << i + 1 
                 << ", Book " << j + 1 << ": ";
            cin >> books[i][j];
        }
    }

    int search_id;
    cout << "\nEnter Book ID to search: ";
    cin >> search_id;

    bool found = false;
    for (int i = 0; i < num_categories; i++) {
        for (int j = 0; j < num_books[i]; j++) {
            if (books[i][j] == search_id) {
                cout << "Book ID " << search_id 
                     << " found in Category " << i + 1 << endl;
                found = true;
                break; 
            }
        }
    }

    if (!found) {
        cout << "Book ID " << search_id 
             << " not found in any category." << endl;
    }

    // Freeing memory
    for (int i = 0; i < num_categories; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] num_books;
}
