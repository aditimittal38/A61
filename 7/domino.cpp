/*
2×N grid of integers
Cover all cells using dominos (either vertical or two horizontal ones)
Each tile’s score = difference between its two covered numbers
Goal → maximize total score

dp[i] = maximum achievable score from column i to N−1

vertical = |top[i] - bottom[i]| + dp[i+1]
horizontal = |top[i] - top[i+1]| + |bottom[i] - bottom[i+1]| + dp[i+2]
dp[i] = max(vertical, horizontal)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> top(N), bottom(N);
    for(int i = 0; i < N; i++) cin >> top[i];
    for(int i = 0; i < N; i++) cin >> bottom[i];

    vector<int> dp(N + 2, 0); // dp[i] = max score from column i to end

    for(int i = N - 1; i >= 0; i--) {
        // option 1: vertical tile
        int score = abs(top[i] - bottom[i]) + dp[i+1];

        // option 2: horizontal tiles (need i+1 < N)
        if(i + 1 < N) {
            int horizontalScore = abs(top[i] - top[i+1]) + abs(bottom[i] - bottom[i+1]) + dp[i+2];
            score = max(score, horizontalScore);
        }

        dp[i] = score;
    }

    cout << dp[0] << endl; // max score for whole grid
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)