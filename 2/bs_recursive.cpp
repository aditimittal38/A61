#include <iostream>
using namespace std;

int binary_search(int arr[],int low, int high, int key){
    int mid = low + (high - low) / 2;
    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid] < key){
        return binary_search(arr, mid+1, high, key);
    }
    else{
        return binary_search(arr, low, mid-1, key);
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
    int index = binary_search(arr, 0, n-1, key);     
    if(index != -1){
        cout << "Element found at index: " << index << endl;
    }
    else{
        cout << "Element not found" << endl;
    }
}

//O(logn)
//O(1)