#include <iostream>
#include <vector>
using namespace std;

using Matrix = vector<vector<int>>;

Matrix make_matrix(int n) {
    return Matrix(n, vector<int>(n, 0));
}

void add_matrices(int n, const Matrix &A, const Matrix &B, Matrix &C) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub_matrices(int n, const Matrix &A, const Matrix &B, Matrix &C) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] - B[i][j];
}

void multiply_matrices(int n, const Matrix &A, const Matrix &B, Matrix &C) {
    if(n == 1){
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n/2;
    Matrix A11 = make_matrix(k), A12 = make_matrix(k), A21 = make_matrix(k), A22 = make_matrix(k);
    Matrix B11 = make_matrix(k), B12 = make_matrix(k), B21 = make_matrix(k), B22 = make_matrix(k);
    Matrix P = make_matrix(k), Q = make_matrix(k), R = make_matrix(k), S = make_matrix(k),
           T = make_matrix(k), U = make_matrix(k), V = make_matrix(k);
    Matrix C11 = make_matrix(k), C12 = make_matrix(k), C21 = make_matrix(k), C22 = make_matrix(k);
    Matrix temp1 = make_matrix(k), temp2 = make_matrix(k);

    // Split matrices
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++){
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+k];
            A21[i][j]=A[i+k][j];
            A22[i][j]=A[i+k][j+k];
            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+k];
            B21[i][j]=B[i+k][j];
            B22[i][j]=B[i+k][j+k];
        }

    // Strassen’s algorithm
    add_matrices(k,A11,A22,temp1);
    add_matrices(k,B11,B22,temp2);
    multiply_matrices(k,temp1,temp2,P);

    add_matrices(k,A21,A22,temp1);
    multiply_matrices(k,temp1,B11,Q);

    sub_matrices(k,B12,B22,temp1);
    multiply_matrices(k,A11,temp1,R);

    sub_matrices(k,B21,B11,temp1);
    multiply_matrices(k,A22,temp1,S);

    add_matrices(k,A11,A12,temp1);
    multiply_matrices(k,temp1,B22,T);

    sub_matrices(k,A21,A11,temp1);
    add_matrices(k,B11,B12,temp2);
    multiply_matrices(k,temp1,temp2,U);

    sub_matrices(k,A12,A22,temp1);
    add_matrices(k,B21,B22,temp2);
    multiply_matrices(k,temp1,temp2,V);

    add_matrices(k,P,S,temp1);
    sub_matrices(k,temp1,T,temp2);
    add_matrices(k,temp2,V,C11);

    add_matrices(k,R,T,C12);
    add_matrices(k,Q,S,C21);
    add_matrices(k,P,R,temp1);
    sub_matrices(k,temp1,Q,temp2);
    add_matrices(k,temp2,U,C22);

    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++){
            C[i][j]=C11[i][j];
            C[i][j+k]=C12[i][j];
            C[i+k][j]=C21[i][j];
            C[i+k][j+k]=C22[i][j];
        }
}

int main(){
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int size = 1;
    while(size < n) size *= 2; // he we check if the value of n is not a power of 2, we add the padding here 

    Matrix A = make_matrix(size);
    Matrix B = make_matrix(size);
    Matrix C = make_matrix(size);

    cout << "Enter elements of matrix A:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> A[i][j];

    cout << "Enter elements of matrix B:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> B[i][j];

    multiply_matrices(size,A,B,C);

    cout << "Resultant matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    return 0;
}








































// #include <iostream>
// #include <cmath>
// using namespace std;

// void add_matrices(int n, int A[][64], int B[][64], int C[][64]) {
//     for(int i=0;i<n;i++)
//         for(int j=0;j<n;j++)
//             C[i][j] = A[i][j] + B[i][j];
// }

// void sub_matrices(int n, int A[][64], int B[][64], int C[][64]) {
//     for(int i=0;i<n;i++)
//         for(int j=0;j<n;j++)
//             C[i][j] = A[i][j] - B[i][j];
// }

// void multiply_matrices(int n, int A[][64], int B[][64], int C[][64]) {
//     if(n==1){
//         C[0][0] = A[0][0]*B[0][0];
//         return;
//     }
//     int k = n/2;
//     int A11[64][64], A12[64][64], A21[64][64], A22[64][64];
//     int B11[64][64], B12[64][64], B21[64][64], B22[64][64];
//     int P[64][64], Q[64][64], R[64][64], S[64][64], T[64][64], U[64][64], V[64][64];
//     int C11[64][64], C12[64][64], C21[64][64], C22[64][64];
//     int temp1[64][64], temp2[64][64];

//     for(int i=0;i<k;i++)
//         for(int j=0;j<k;j++){
//             A11[i][j]=A[i][j];
//             A12[i][j]=A[i][j+k];
//             A21[i][j]=A[i+k][j];
//             A22[i][j]=A[i+k][j+k];
//             B11[i][j]=B[i][j];
//             B12[i][j]=B[i][j+k];
//             B21[i][j]=B[i+k][j];
//             B22[i][j]=B[i+k][j+k];
//         }

//     add_matrices(k,A11,A22,temp1);
//     add_matrices(k,B11,B22,temp2);
//     multiply_matrices(k,temp1,temp2,P);

//     add_matrices(k,A21,A22,temp1);
//     multiply_matrices(k,temp1,B11,Q);

//     sub_matrices(k,B12,B22,temp1);
//     multiply_matrices(k,A11,temp1,R);

//     sub_matrices(k,B21,B11,temp1);
//     multiply_matrices(k,A22,temp1,S);

//     add_matrices(k,A11,A12,temp1);
//     multiply_matrices(k,temp1,B22,T);

//     sub_matrices(k,A21,A11,temp1);
//     add_matrices(k,B11,B12,temp2);
//     multiply_matrices(k,temp1,temp2,U);

//     sub_matrices(k,A12,A22,temp1);
//     add_matrices(k,B21,B22,temp2);
//     multiply_matrices(k,temp1,temp2,V);

//     add_matrices(k,P,S,temp1);
//     sub_matrices(k,temp1,T,temp2);
//     add_matrices(k,temp2,V,C11);

//     add_matrices(k,R,T,C12);
//     add_matrices(k,Q,S,C21);
//     add_matrices(k,P,R,temp1);
//     sub_matrices(k,temp1,Q,temp2);
//     add_matrices(k,temp2,U,C22);

//     for(int i=0;i<k;i++)
//         for(int j=0;j<k;j++){
//             C[i][j]=C11[i][j];
//             C[i][j+k]=C12[i][j];
//             C[i+k][j]=C21[i][j];
//             C[i+k][j+k]=C22[i][j];
//         }
// }

// int main(){
//     int n;
//     cout << "Enter size of square matrix: ";
//     cin >> n;

//     int size = 1;
//     while(size < n) size *= 2; //here we are checking for power of 2
//     //if it is not a power of 2, we are automatically adding padding while initializing matrices

//     int A[64][64] = {0}, B[64][64] = {0}, C[64][64] = {0};

//     cout << "Enter elements of matrix A:\n";
//     for(int i=0;i<n;i++)
//         for(int j=0;j<n;j++)
//             cin >> A[i][j];

//     cout << "Enter elements of matrix B:\n";
//     for(int i=0;i<n;i++)
//         for(int j=0;j<n;j++)
//             cin >> B[i][j];

//     multiply_matrices(size,A,B,C);

//     cout << "Resultant matrix:\n";
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++)
//             cout << C[i][j] << " ";
//         cout << endl;
//     }
//     return 0;
// }
