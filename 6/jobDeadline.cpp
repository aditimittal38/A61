/*
3. Startup Pitch Scheduling – Job Sequencing
50 startups pitching to an investor, with deadlines (1–10 slots) and profits (10–500).
Input sample:
Startups =
S1(deadline=2, profit=300), S2(1, 200), S3(3, 180), S4(2, 400),
S5(1, 250), S6(3, 100), S7(4, 500), S8(2, 150), S9(3, 220), S10(4, 330), ...
Slots Available = 10
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class job{
public:
    int id;
    int deadline;
    int profit;
    job(int id = -1, int deadline = -1, int profit = -1){
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool customComparator(const job &j1, const job &j2){
    return j1.profit > j2.profit;
}

int main(){
    // 10 deadline slots
    int num_of_slots = 10;
    // 50 startup jobs
    int n;
    cout<< "Enter number of jobs:";
    cin >> n;
    // vector to store the jobs 
    vector<job> jobs(n);
    int id, deadline, profit;
    for(int i = 0; i<n; i++){
        cin >> id >> profit >> deadline;
        jobs[i] = job(id, deadline, profit);
    }
    // vector of slots initilaised to -1
    vector <int> slots(num_of_slots,-1);
    // now we sort the jobs in decreasing order of profits
    sort(jobs.begin(), jobs.end(), customComparator);
    //variable to store profits
    int total_profit = 0;
    // now we traverse through the sorted vector of jobs
    int slot_number;
    for(int i = 0; i<n ; i++){
        // slot_number = jobs[i].deadline - 1;
        slot_number = min(jobs[i].deadline, num_of_slots) - 1;
        // this is to ensure in case the deadline given is more than the number of slots.
        while(slot_number >=0 && slots[slot_number] != -1){
            slot_number--;
        }
        if(slot_number < 0){
            continue;
        }
        slots[slot_number] = jobs[i].id;
        total_profit += jobs[i].profit;
        
    }
    //printing
    cout <<endl;
    for(int i=0; i<num_of_slots; i++){
        cout << "Slot " << i + 1 << " -> " << "Job " << slots[i] << " -> " << jobs[slots[i]-1].profit<< endl;
    }
    cout << "Total profit = " << total_profit <<endl;
    
    return 0;
}


// Time Complexity: O(n log n + n × m)
// → Sorting jobs by profit takes O(n log n),
// → Assigning jobs to available slots (up to m = number of slots) takes O(n × m) in the worst case.

// Space Complexity: O(n + m)
// → For storing jobs and the slot array.