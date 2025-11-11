#include <iostream>
using namespace std;

int kthCandyBox(int N, int K) {
    if (K <= N) {
        return K; 
    }
    K = K - N;

    while (true) {
        if (K <= N - 1) {
            return N - K;
        }
        K = K - (N - 1);

        if (K <= N - 1) {
            return K + 1;
        }
        K = K - (N - 1);
    }
}

int main() {
    int N;
    cout << "Enter number of boxes: ";
    cin >> N;
    int K;
    cout << "Enter K (the candy number): "; 
    cin >> K;
    cout << "K-th candy is in box " << kthCandyBox(N, K) << endl;
}
//O(k)
//O(1)
