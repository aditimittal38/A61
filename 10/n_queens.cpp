#include <bits/stdc++.h>
using namespace std;

// Check if placing a queen at (row, column) is safe
bool isSafe(vector<string> &board, int row, int column, int n) {
    // Check column above
    for (int i = 0; i < row; i++)
        if (board[i][column] == 'Q')
            return false;

    // Check upper left diagonal
    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // Check upper right diagonal
    for (int i = row, j = column; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

// Recursive backtracking function
void nqueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
    if (row == n) {
        ans.push_back(board); // Found a valid solution
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q';
            nqueens(board, row + 1, n, ans);
            board[row][j] = '.'; // Backtrack
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> results;

    nqueens(board, 0, n, results);

    // Print all solutions
    for (auto &board : results) {
        for (auto &row : board)
            cout << row << endl;
        cout << endl;
    }
}


// TC = O(n!*n)
// SC = O(n^2)