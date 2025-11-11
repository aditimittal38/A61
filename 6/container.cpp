/*
Emergency Evacuation – Container Loading
Evacuating 200 families with varying luggage weights onto a bus with a capacity of 5000 kg. Input sample:
Bus Capacity = 5000
Families’ luggage = [45, 120, 300, 150, 90, 600, 75, 430, 250, 500,
60, 100, 700, 85, 95, 200, 320, 180, 150, 275, ...]
Implement container loading problem.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    // number of families (luggages)
    int number_of_luggages;
    cout << "Enter number of luggages: ";
    cin >> number_of_luggages;
    //capacity of bus
    int capacity;
    cout << "Enter bus capacity: ";
    cin >> capacity;
    // number of lugages loaded
    int num_loaded = 0;
    vector<int> luggages(number_of_luggages);
    for(int i = 0; i<number_of_luggages; i++){
        cin >> luggages[i];
    }
    sort(luggages.begin(), luggages.end());
    int i = 0;
    cout << endl << "Luggages loaded: "<< endl;
    while(i<number_of_luggages && capacity>0){
        if(luggages[i]<=capacity){
            capacity -= luggages[i];
            cout << luggages[i] << "  ";
            num_loaded += 1;
            i++;
        }
        else{
            break;
        }
        
    }
    cout << endl;
    cout << "Number of luggages loaded: " << num_loaded << endl;
    return 0;
}