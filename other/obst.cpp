#include <bits/stdc++.h>
using namespace std;

int optimalBST(vector<int>& keys, vector<float>& freq) {
    int n = keys.size();
    vector<vector<float>> dp(n, vector<float>(n, 0));

    for (int i = 0; i < n; i++) dp[i][i] = freq[i];

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n-len; i++) {
            int j = i + len - 1;
            dp[i][j] = FLT_MAX;

            float sumFreq = 0;
            for (int k = i; k <= j; k++) sumFreq += freq[k];

            for (int r = i; r <= j; r++) {
                float cost = (r > i ? dp[i][r-1] : 0) + (r < j ? dp[r+1][j] : 0) + sumFreq;
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    vector<int> keys = {10, 12, 20};
    vector<float> freq = {0.34, 0.08, 0.58};
    cout << "Minimum cost of OBST: " << optimalBST(keys, freq) << endl;
    return 0;
}
