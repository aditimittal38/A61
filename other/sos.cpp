#include <bits/stdc++.h>
using namespace std;

// Recursive function to find subsets that sum to target
void sumOfSubsets(vector<int> &arr, vector<int> &subset, int index, int currentSum, int target) {
    // If current sum equals target, print the subset
    if (currentSum == target) {
        for (int num : subset) cout << num << " ";
        cout << endl;
        return;
    }

    // If current sum exceeds target or index is out of bounds, stop
    if (currentSum > target || index == arr.size()) return;

    // Include arr[index] in subset
    subset.push_back(arr[index]);
    sumOfSubsets(arr, subset, index + 1, currentSum + arr[index], target);

    // Backtrack: exclude arr[index] from subset
    subset.pop_back();
    sumOfSubsets(arr, subset, index + 1, currentSum, target);
}

int main() {
    int n, target;
    cin >> n; // number of elements
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> target;

    vector<int> subset;
    sumOfSubsets(arr, subset, 0, 0, target);

    return 0;
}


//TC = O(n*2^n)
//SC = O(n)