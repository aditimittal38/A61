/*
Bob has an array A of size N, and he is very fond of two integers X and Y.
Find the length of the longest subarray such that

it contains exactly X distinct integers, and

Y exists at least once in the subarray.

Input format

The first line contains an integer T, denoting the number of test cases.

The first line of each test case contains three space-separated integers N, X, Y,
denoting the size of array A, the value of X, and the value of Y respectively.

The second line of each test case contains N space-separated integers, the elements of array A.

Output format
For each test case, print the length of the largest subarray such that it contains exactly X distinct integers and Y exists at least once in the subarray, each answer on a new line.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin >> t;
    int n, x, y;
    for (int j = 0; j<t; j++){
        cin >> n >> x >> y;
        vector<int> arr(n);
        for(int i =0; i<n; i++){
            cin >> arr[i];
        }
        int leftptr = 0;
        int maxLength = -1;
        int distinctCount = 0;
        unordered_map<int, int> freqMap;
        for (int rightptr = 0; rightptr < n; rightptr++){
            // frequency map to store frequency of elements in current window
            if (++freqMap[arr[rightptr]] == 1){
                distinctCount++;
            }
            while (distinctCount > x){    
                //shrink window from left until distinctCount becomes x
                if(--freqMap[arr[leftptr]] == 0){
                    distinctCount--;
                } 
                leftptr++;
            }    
            
            if(distinctCount == x && freqMap[y] > 0){
                maxLength = max(maxLength, rightptr - leftptr + 1);
            }
                    
        }
        cout << maxLength << endl;
                
    }
    
            
    return 0;
}