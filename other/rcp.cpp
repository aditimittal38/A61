#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of pieces: ";
    cin >> n;

    vector<int> price(n);
    cout << "Enter the prices of pieces of length 1 to " << n << ":\n";
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    vector<int> dp(n+1, 0); // dp[i] = max profit for rod of length i

    for (int i = 1; i <= n; i++) {      // rod length
        for (int j = 1; j <= i; j++) {  // first cut length
            dp[i] = max(dp[i], price[j-1] + dp[i-j]);
        }
    }

    cout << "Maximum profit: " << dp[n] << endl;
    return 0;
}
