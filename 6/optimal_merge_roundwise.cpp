/*
5. Multi-Server Log Merging – Optimal Merge
A company has 20 log files with sizes from 5MB to 500MB. Logs arrive in rounds.
Input:
Round 1: [40, 120, 200, 10]
Round 2: [30, 15, 250, 90, 60]
Round 3: [100, 75, 35, 55, 85, 45]
Round 4: [500, 300, 150, 25, 70]
*/

//roundwise optimal merge

#include <iostream>
#include <queue>
using namespace std;

int main(){
    // number of records = 20
    int num_of_records;
    cout << "Enter number of records: ";
    cin >> num_of_records;
    //number of rounds here = 4
    int num_of_rounds;
    cout << "Enter number of rounds:";
    cin >> num_of_rounds;
    // we create a priority queue to store the records by minimum file size
    // min heap
    // priority queue is max heap by default
    priority_queue<int, vector<int>, greater<int>> records;
    int record;
    int r1, r2, sum, total_movements = 0;
    cout <<endl;
    for(int i = 0; i< num_of_rounds; i++){
        // we add new records to the priority queue
        cout << "Round " << i+1 << " input records: " << endl;
        for(int j = 0; j < num_of_records/num_of_rounds; j++){
            // we take input of records for current round
            cin >> record;
            records.push(record);
        }
        // we sort and merge records of the particular round
        while(records.size()>1){
            r1 = records.top(); records.pop();
            r2 = records.top(); records.pop();
            sum = r1 + r2;
            records.push(sum);
            total_movements+=sum;
        }
        // now we proceed for teh next round

    }
    cout << "Total record movements = " << total_movements << endl;

    return 0;
}


// Time Complexity: O(n log n)
// → Each merge operation (using a min-heap) takes O(log n), and there are n elements total across all rounds.

// Space Complexity: O(n)
// → For storing all log sizes in the min-heap.