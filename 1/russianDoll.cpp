#include <iostream>
#include <algorithm>
using namespace std;

struct Person {
    int height;
    int weight;
};

bool compare(Person a, Person b) {
    if(a.height == b.height)
        return a.weight < b.weight;
    return a.height < b.height;
}

int main() {
    int n;
    cout << "Enter number of people: ";
    cin >> n;

    Person people[n]; 
    cout << "Enter height and weight for each person:\n";
    for(int i = 0; i < n; i++) {
        cin >> people[i].height >> people[i].weight;
    }
    // 56 90
    // 65 100
    // 70 150
    // 75 190
    // 60 95
    // 68 110

    sort(people, people + n, compare);

    int dp[n]; 
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(people[j].weight < people[i].weight) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxTower = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] > maxTower) maxTower = dp[i];
    }

    cout << "Length of the longest tower: " << maxTower << endl;

    cout << "Tower sequence from top to bottom:" << endl;
    int tower[maxTower];
    int idx = maxTower - 1;
    int lastWeight = 1e9;
    for(int i = n-1; i >= 0 && idx >= 0; i--) {
        if(dp[i] == idx + 1 && people[i].weight < lastWeight) {
            tower[idx--] = i;
            lastWeight = people[i].weight;
        }
    }

    for(int i = 0; i < maxTower; i++) {
        cout << "(" << people[tower[i]].height << ", " << people[tower[i]].weight << ") ";
    }
    cout << endl;

    return 0;
}


/*
Time Complexity:

Sorting: O(n log n)

DP for LIS: O(n²)

Max finding + reconstruction: O(n)

Total: O(n²) (dominant term is DP)

Space Complexity:

dp[n] + tower[maxTower] + people[n] → O(n)
*/