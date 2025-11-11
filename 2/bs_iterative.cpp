#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int key){
    int left = 0;
    int right = n - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];  
    }
    int key;
    cout << "Enter element to be searched: ";
    cin >> key;
    int index = binary_search(arr, n, key);     
    if(index != -1){
        cout << "Element found at index: " << index << endl;
    }
    else{
        cout << "Element not found" << endl;
    }
}