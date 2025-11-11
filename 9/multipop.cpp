#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    stack<string> st;
    long long totalActualCost = 0;
    long long totalAmortizedCost = 0;

    cout << "Operation\tActualCost\tAmortizedCost\tStackSize\n";

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "push") {
            string page;
            cin >> page;
            st.push(page);

            int actualCost = 1;          // real push cost
            int amortizedCost = 2;       // 1 for push + 1 credit for future pop
            totalActualCost += actualCost;
            totalAmortizedCost += amortizedCost;

            cout << "push(" << page << ")\t" 
                 << actualCost << "\t\t" 
                 << amortizedCost << "\t\t"
                 << st.size() << endl;
        }
        else if (op == "pop") {
            if (!st.empty()) st.pop();

            int actualCost = 1;          // real pop cost
            int amortizedCost = 0;       // use credit from push
            totalActualCost += actualCost;
            totalAmortizedCost += amortizedCost;

            cout << "pop()\t\t" 
                 << actualCost << "\t\t" 
                 << amortizedCost << "\t\t"
                 << st.size() << endl;
        }
        else if (op == "multipop") {
            int k;
            cin >> k;

            int pops = min(k, (int)st.size());
            for (int j = 0; j < pops; j++) st.pop();

            int actualCost = pops;       // each pop costs 1
            int amortizedCost = 0;       // credit pays for pop
            totalActualCost += actualCost;
            totalAmortizedCost += amortizedCost;

            cout << "multipop(" << k << ")\t" 
                 << actualCost << "\t\t" 
                 << amortizedCost << "\t\t"
                 << st.size() << endl;
        }
    }

    cout << "\nTotal Actual Cost: " << totalActualCost << endl;
    cout << "Total Amortized Cost: " << totalAmortizedCost << endl;

    return 0;
}

// Time Complexity:
// Worst-case (single multipop): O(n)
// Amortized (per operation): O(1)
// Total for n operations: O(n)
// Space Complexity: O(n)