// You're monitoring signal strengths over time using an array signal[]. A drop is defined as a strictly decreasing subsequence for at least 3 consecutive readings. 
// Task: Find the number of such "signal drops" in the array. 
// Input: signal = [5, 4, 3, 6, 7, 4, 3, 2] 
// Output: 2 (drops: 5→4→3 and 7→4→3→2)

#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];  
    }
    int consecutive = 0;
    int count = 0;
    for(int i = 0; i < n-1; i++){
        if(arr[i]>arr[i+1]){
            consecutive++;
        }
        else{
            if(consecutive >= 2){
                count++;
            }
            consecutive = 0;
        }
    }    
    if(consecutive >= 2){
        count++;
    }

    cout << "Number of signal drops: " << count << endl;
    return 0;
}