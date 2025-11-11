#include <iostream>
using namespace std;

void linear_search(int arr[], int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            cout << "Element found at index: " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    } 
    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;
    linear_search(arr, n, key);

}

//O(n)
//O(1)