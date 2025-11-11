#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int,int> freq;

void track(int x) {
    freq[x]++;
}

int getRankOfNumber(int x) {
    int rank = 0;
    for (auto &p : freq) {
        if (p.first <= x) rank += p.second;
    }
    return rank - 1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        track(arr[i]);
    }

    int q;
    cout << "Enter number to find rank of: ";
    cin >> q;
    cout << "Rank of " << q << " is: " << getRankOfNumber(q) << endl;

    return 0;
}


























// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter number of elements in the stream: ";
//     cin >> n;

//     int arr[n];
//     cout << "Enter the stream of numbers:\n";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int q;
//     cout << "Enter number of queries: ";
//     cin >> q;

//     cout << "Enter numbers to get their rank:\n";
//     for (int i = 0; i < q; i++) {
//         int x;
//         cin >> x;
//         int rank = 0;
//         for (int j = 0; j < n; j++) {
//             if (arr[j] <= x) {
//                 rank++;
//             }
//         }
//         cout << "getRankOfNumber(" << x << ") = " << rank-1 << endl;
//     }

//     return 0;
// }
