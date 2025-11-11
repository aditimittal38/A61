#include <iostream>
using namespace std;

int findMaximum(int arr[], int n) {
    // if there is onky one element 
    // if first element is greater than second
    if (n == 1 || arr[0] > arr[1])
        return arr[0];
    //if last element is greater than second last then: entire array is sorted
    if (arr[n - 1] > arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return arr[mid];
        if (arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return arr[high];
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    // 1 2 3 5 8 3 4
    int arr[n]; 
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Maximum element in the bitonic array: " << findMaximum(arr, n) << endl;
    return 0;
}
