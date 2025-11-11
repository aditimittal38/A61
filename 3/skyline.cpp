#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeSkylines(vector<vector<int>> &leftSkyline, vector<vector<int>> &rightSkyline) {
    vector<vector<int>> result;
    int i = 0, j = 0;
    int leftHeight = 0, rightHeight = 0, currHeight = 0;

    while (i < leftSkyline.size() && j < rightSkyline.size()) {
        int x;
        if (leftSkyline[i][0] < rightSkyline[j][0]) {
            x = leftSkyline[i][0];
            leftHeight = leftSkyline[i][1];
            i++;
        } else if (rightSkyline[j][0] < leftSkyline[i][0]) {
            x = rightSkyline[j][0];
            rightHeight = rightSkyline[j][1];
            j++;
        } else {
            x = leftSkyline[i][0];
            leftHeight = leftSkyline[i][1];
            rightHeight = rightSkyline[j][1];
            i++; j++;
        }
        int maxHeight = max(leftHeight, rightHeight);
        if (currHeight != maxHeight) {
            result.push_back({x, maxHeight});
            currHeight = maxHeight;
        }
    }

    while (i < leftSkyline.size()) {
        if (currHeight != leftSkyline[i][1]) {
            result.push_back(leftSkyline[i]);
            currHeight = leftSkyline[i][1];
        }
        i++;
    }
    while (j < rightSkyline.size()) {
        if (currHeight != rightSkyline[j][1]) {
            result.push_back(rightSkyline[j]);
            currHeight = rightSkyline[j][1];
        }
        j++;
    }

    return result;
}


vector<vector<int>> findSkyLine(vector<vector<int>> &buildings, int start, int end) {
    if (start > end) return {};
    if (start == end) {
        // (left, height), (right, 0)
        return {{buildings[start][0], buildings[start][2]},
                {buildings[start][1], 0}};
    }

    int mid = (start + end) / 2;
    vector<vector<int>> leftSkyline = findSkyLine(buildings, start, mid);
    vector<vector<int>> rightSkyline = findSkyLine(buildings, mid + 1, end);
    return mergeSkylines(leftSkyline, rightSkyline);
}

int main() {
    int n;
    cout << "Enter number of buildings: ";
    cin >> n;

    vector<vector<int>> buildings(n, vector<int>(3));
    cout << "Enter buildings as: left right height\n";
    for (int i = 0; i < n; i++) {
        cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];
    }


    // 1 5 11
    // 2 7 6
    // 3 9 13
    // 12 16 7
    // 14 25 3
    // 19 22 18
    // 23 29 13
    // 24 28 4

    sort(buildings.begin(), buildings.end());
    vector<vector<int>> result = findSkyLine(buildings, 0, n - 1);

    cout << "\nSkyline: \n";
    for (auto &point : result) {
        cout << point[0] << " " << point[1] << "\n";
    }
}
