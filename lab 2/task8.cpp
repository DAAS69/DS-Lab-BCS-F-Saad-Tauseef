#include <iostream>
using namespace std;

int main() {
    int num_days;

    float** data;
    int* num_readings;
    float* avg_days;

    cout << "Enter Number of Days: ";
    cin >> num_days;

    num_readings = new int[num_days];
    data = new float*[num_days];
    avg_days = new float[num_days];

    for (int i = 0; i < num_days; i++) {
        cout << "Enter Number of Readings for Day " << i+1 << ": ";
        cin >> num_readings[i];
        data[i] = new float[num_readings[i]];
    }

    for (int i = 0; i < num_days; i++) {
        for (int j = 0; j < num_readings[i]; j++) {
            cout << "Enter Temp For Day " << i+1 << " Reading " << j+1 << ": ";
            cin >> data[i][j];
        }
    }

    cout << "Printing Data for All Days." << endl;
    float total = 0.0;

    for (int i = 0; i < num_days; i++) {
        for (int j = 0; j < num_readings[i]; j++) {
            total = total + data[i][j];
            cout << " " << data[i][j] << " ";
        }
        avg_days[i] = total / num_readings[i];
        total = 0.0;
        cout << endl;
    }

    float highest_avg = 0;
    int hottest_index;
    int coldest_index;
    float lowest_avg = 999;

    for (int i = 0; i < num_days; i++) {
        if (avg_days[i] > highest_avg) {
            highest_avg = avg_days[i];
            hottest_index = i;
        }

        if (avg_days[i] < lowest_avg) {
            lowest_avg = avg_days[i];
            coldest_index = i;
        }
    }

    cout << "Hottest Day was Day " << hottest_index+1 
         << " with avg temp of : " << highest_avg << "C" << endl;

    cout << "Coldest Day was Day " << coldest_index+1 
         << " with avg temp of : " << lowest_avg << "C" << endl;

    for (int i = 0; i < num_days; i++) {
        delete[] data[i];
    }

    delete[] data;
    delete[] num_readings;
    delete[] avg_days;
}
