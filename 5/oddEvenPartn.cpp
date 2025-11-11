// You are working in the Data Consistency team of your company. You are allocated a task as follows:

// You have a data stream consisting of an equal number of odd and even numbers. You can make separations in the data stream but the number of odd elements should be equal to the number of even elements in both partitions after separation. Also, if you make a separation between a number x and number y, then the cost of this operation will be |x-y| coins.

// You are given the following:

// An integer N
// An array arr
// An integer K

// Task

// Determine the maximum number of separations that can be made in the array by spending no more than K coins.

/*
Question Explanation:
n-> array length
arr -> of integers where total number of odd numbers = total number of even numbers
if i make a cut between arr[i] and arr[i+1], cost = |arr[i]-arr[i+1]|
after each cut, number of odd and even numbers in both partitions should be equal
k-> max coins that can be spent
GOAL: To maximise number of cuts
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // You have a data stream consisting of an equal number of odd and even numbers.
    // implies n is a multiple of 2
    int n;
    cout << "Enter length of data stream: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of the array: ";
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int k; // max coins that can be spent
    cout << "Enter max coins that can be spent: ";
    cin >> k;
    int odd = 0;
    int even = 0;
    vector <int> partitions;
    for (int i=0; i<n-1; i++){
        if(arr[i] % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
        if (odd == even){
            int partition_cost = abs(arr[i] - arr[i+1]);
            partitions.push_back(partition_cost);
        }
        
    }
    // now we have all the possible partitions and their costs
    // to maximise partitions, sort partition costs in ascending order
    sort(partitions.begin(), partitions.end());
    int ptr = 0;
    while(k > 0 && ptr<partitions.size()){
        if(k - partitions[ptr] >= 0){
            k -= partitions[ptr];
            ptr++;
        }
        else{
            break;
        }
    }
    cout << "Maximum number of partitions that can be made: " << ptr << endl;
    return 0;
}