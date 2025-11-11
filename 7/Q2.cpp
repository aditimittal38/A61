#include <bits/stdc++.h>
using namespace std;

// Each dp[mask] stores: {rides, weight_in_last_ride}
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];

    int N = 1 << n; // total number of subsets
    vector<pair<int,int>> dp(N, {n+1, 0}); // initialize with max rides
    dp[0] = {1, 0}; // base case: no one taken → 1 ride, weight 0

    for(int mask = 0; mask < N; mask++) {
        for(int i = 0; i < n; i++) {
            if(!(mask & (1<<i))) { // person i not yet included
                int nextMask = mask | (1<<i); // include person i
                auto cur = dp[mask];
                pair<int,int> nextState;

                if(cur.second + w[i] <= x) {
                    // person fits in current ride
                    nextState = {cur.first, cur.second + w[i]};
                } else {
                    // start new ride
                    nextState = {cur.first + 1, w[i]};
                }

                // keep the better (fewer rides) option
                if(nextState.first < dp[nextMask].first ||
                   (nextState.first == dp[nextMask].first && nextState.second < dp[nextMask].second)) {
                    dp[nextMask] = nextState;
                }
            }
        }
    }

    cout << "Minimum number of rides: " << dp[N-1].first << endl;
    return 0;
}
