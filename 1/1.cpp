#include <iostream>
#include <vector>

using namespace std;

void merge_sorted_arrays(vector<int>& A, const vector<int>& B, int m, int n) {
    int ptrA = m - 1;
    int ptrB = n - 1;
    int ptr_merged = m + n - 1;

    while (ptrB >= 0) {
        if (ptrA >= 0 && A[ptrA] > B[ptrB]) {
            A[ptr_merged] = A[ptrA];
            ptrA--;
        } else {
            A[ptr_merged] = B[ptrB];
            ptrB--;
        }
        ptr_merged--;
    }
}

int main() {
    int m, n;
    cout << "Enter number of elements in A (excluding buffer): ";
    cin >> m;
    cout << "Enter number of elements in B: ";
    cin >> n;

    vector<int> A(m + n);
    vector<int> B(n);

    cout << "Enter " << m << " elements of sorted array A:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    cout << "Enter " << n << " elements of sorted array B:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    merge_sorted_arrays(A, B, m, n);
    cout << "Merged array A: ";
    for (int val : A) {
        cout << val << " ";
    }
    return 0;
}



// #include <iostream>
// #include <vector>
// using namespace std;
// void merge_sorted_arrays(vector<int>& A, const vector<int>& B, int m, int n) {
//     int ptrA = 0;
//     int ptrB = 0;
//     int current_m = m;


//     while (ptrB < n) {
//         if (ptrA == current_m) {
//             A[ptrA] = B[ptrB];
//             ptrA++;
//             ptrB++;
//             current_m++;
//         }
//         else if (A[ptrA] <= B[ptrB]) {
//             ptrA++;
//         }
//         else {
//             for (int i = current_m; i > ptrA; --i) {
//                 A[i] = A[i - 1];
//             }
            
//             A[ptrA] = B[ptrB];
            
//             ptrA++;
//             ptrB++;
//             current_m++;
//         }
//     }
// }

// int main() {
//     vector<int> A = {1, 5, 8, 0, 0, 0};
//     const vector<int> B = {2, 6, 9};

//     int m = 3;
//     int n = 3;

//     merge_sorted_arrays(A, B, m, n);
//     cout << "Merged array A: ";
//     for (int val : A) {
//         cout << val << " ";
//     }
//     return 0;
// }