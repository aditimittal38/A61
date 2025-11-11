#include <iostream>
using namespace std;

int main() {
    int s, p, o, t;

    cout << "Enter rows and columns for matrix A: ";
    cin >> s >> p;
    cout << "Enter rows and columns for matrix B: ";
    cin >> o >> t;

    if (p != o) {
        cout << "Incompatible dimensions" << endl;
        return 0;
    }

    int A[s][p], B[o][t], D[s][t];

    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < p; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < t; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < t; j++) {
            D[i][j] = 0;
            for (int k = 0; k < p; k++) {
                D[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant matrix D:" << endl;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < t; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//O(n^3)