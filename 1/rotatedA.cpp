#include <iostream>
using namespace std;

int find_in_rotated_array(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        // we assume here that the left half is sorted
        if (arr[low] <= arr[mid]) {
            if (target >= arr[low] && target < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // we assume here that the right half is sorted
        else {
            if (target > arr[mid] && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;  
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n]; 
    cout << "Enter elements of the rotated sorted array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // 15 18 2 3 6 12

    int target;
    cout << "Enter element to be searched: ";
    cin >> target;

    int index = find_in_rotated_array(arr, n, target);

    if (index != -1) {
        cout << target << " found at index " << index << endl;
    } else {
        cout << target << " not found in the array.\n";
    }

    return 0;
}

//Time: O(log n)
//Space:O(1)
