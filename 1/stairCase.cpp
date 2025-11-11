#include <iostream>
using namespace std;

void searchMatrix(int matrix[][100], int M, int N, int target) {
    int row = 0, col = N - 1; 
    while (row < M && col >= 0) {
        if (matrix[row][col] == target) {
            cout << "Element " << target << " found at row=" << row << ", col=" << col << "\n";
            return;
        }
        else if (matrix[row][col] > target) {
            col--; 
        }
        else {
            row++; 
        }
    }

    cout << "Element " << target << " not found in the matrix.\n";
}

int main() {
    int M, N;
    cout << "Enter number of rows M: ";
    cin >> M;
    cout << "Enter number of columns N: ";
    cin >> N;

    int matrix[M][100];
    // 1 4 7
    // 2 5 9
    // 3 6 10

    cout << "Enter the matrix row by row:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    searchMatrix(matrix, M, N, target);

    return 0;
}

//Time: O(m+n)
// Space: O(1)