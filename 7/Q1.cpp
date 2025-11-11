/*
LIS:
Let dp[i] = length of the longest increasing subsequence ending at index i
For each i, check all previous elements j < i:
If a[j] < a[i], we can extend dp[j]
Update: dp[i] = max(dp[i], dp[j] + 1)
The answer = max of all dp[i]
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = *max_element(dp.begin(), dp.end());
    cout << "The longest increasing subsequence:" << ans << endl;
    return 0;
}



//https://www.youtube.com/watch?v=Xq3hlMvhrkE