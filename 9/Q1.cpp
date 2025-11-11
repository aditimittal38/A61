#include <iostream>
#include <vector>
#include <iomanip> // for std::setprecision
using namespace std;

int main() {
    int n;
    cout << "Enter number of insertions: ";
    cin >> n;

    int capacity = 1;      // initial capacity
    int size = 0;          // current number of elements
    long long totalCost = 0;

    cout << left << setw(10) << "Operation" 
         << setw(12) << "ActualCost" 
         << setw(12) << "TotalCost" 
         << setw(15) << "AmortizedCost" << endl;

    for (int i = 1; i <= n; i++) {
        int actualCost;

        if (size < capacity) {
            // space available, cost = 1
            actualCost = 1;
        } else {
            // capacity full → double capacity
            capacity *= 2;
            actualCost = size + 1; // cost = copy old elements + insert
        }

        size++; // insert element
        totalCost += actualCost;
        double amortized = (double)totalCost / size;

        cout << left << setw(10) << ("Insert " + to_string(i))
             << setw(12) << actualCost
             << setw(12) << totalCost
             << setw(15) << fixed << setprecision(2) << amortized
             << endl;
    }

    return 0;
}
