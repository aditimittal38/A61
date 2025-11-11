#include <iostream>
#include <vector>
#include <string>

using namespace std;

int find_string(const vector<string>& arr, const string& target) {
    if (arr.empty()) {
        return -1;
    }

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid].empty()) {
            int left = mid - 1;
            int right = mid + 1;
            
            while (true) {
                if (left < low && right > high) {
                    return -1;
                }
                if (left >= low && !arr[left].empty()) {
                    mid = left;
                    break;
                }
                if (right <= high && !arr[right].empty()) {
                    mid = right;
                    break;
                }
                left--;
                right++;
            }
        }

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<string> arr = {"at", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    string target;

    cout<< "The input array is: ";
    for(int i=0 ; i<arr.size(); i++){
        cout << arr[i]<< " ";
    }
    cout << endl;
    cout << "Enter target string: " << target << endl;
    cin>>target;

    int index = find_string(arr, target);
    if (index != -1) {
        cout << "Target found at index: " << index << " \n";
    } else {
        cout << target << " not found in the array.\n";
    }

    return 0;
}