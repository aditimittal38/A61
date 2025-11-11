
#include <iostream>
using namespace std;

void findMissingTimestamp(int* timestamp, int n){
    if (n == 1){
        cout<< "No missing Values"<< endl;
        return;
    }
    for (int i = 0; i<n-1 ; i++){
        if (!(timestamp[i+1] == timestamp[i] ||timestamp[i+1] == timestamp[i] + 1)){
            cout << "Missing timestamp is: "<< timestamp[i];
            return;
        }
    }
    cout<< "No missing Values"<< endl;

} 

int main() {
    int n;
    cin >> n;
    int timestamps[n];
    for(int i =0; i<n ;i ++){
        cin>> timestamps[i];
    }

    findMissingTimestamp(timestamps, n);

    return 0;
}
//O(n)
//O(1)