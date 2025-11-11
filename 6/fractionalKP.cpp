/*
4. Disaster Relief Supply Drop – Fractional Knapsack
Helicopter capacity = 1000 kg, 100 supply items (divisible & indivisible).
Input sample:
Capacity = 1000 
Supplies =
Rice(100, value=500), 
Medicine(50, value=400, indivisible), 
Water(200, value=600), 
Blankets(150, value=450, indivisible), 
Tents(300, value=800, indivisible), 
Wheat(120, value=300), 
Sugar(80, value=250), 
Oxygen(60, value=700, indivisible), 
Milk(90, value=350), 
FirstAid(40, value=500, indivisible), ...

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

class article{
public:
    string article_name;
    int weight;
    int value;
    bool divisible;
    double weight_used;
    double profit;
    int cap_remaining;
    article(string article_name = "", int weight = 0, int value = 0, bool divisible = 1){
        this->article_name = article_name;
        this->weight = weight;
        this->value = value;
        this->divisible = divisible;
        this->weight_used = 0;
        this->profit = 0;
        this->cap_remaining = 0;
    }
};

//custom comparator
bool customSort(const article &A1, const article &A2){
    double r1 = (double)A1.value / A1.weight;
    double r2 = (double)A2.value / A2.weight;
    return r1 > r2;
}

int main(){
    double capacity = 1000;
    double profit = 0;
    cout << " Enter number of supplies: ";
    int n;
    cin >> n;
    string article_name;
    int weight, value, divisible;
    vector<article> supplies(n);
    for(int i = 0; i < n; i++){  
        cin >> article_name >> weight >> value >> divisible;
        supplies[i] = article(article_name, weight, value, divisible);
        // divisible = 1 (true) for divisble,
        // divisible = 0 (false) for indivisible
    }
    //sorting artciles by highest profit/weight ratio to maximise profit
    sort(supplies.begin(), supplies.end(), customSort);
    // greedy method
    for (int i = 0; i < n && capacity > 0; i++) {
        if(capacity >= supplies[i].weight){
            capacity -= supplies[i].weight;
            supplies[i].profit = supplies[i].value;
            profit += supplies[i].profit;
            supplies[i].weight_used = supplies[i].weight;
        }
        else {
            // for divisible (fractional knapsack)
            if (supplies[i].divisible == 1){
                supplies[i].profit = (capacity / supplies[i].weight) * supplies[i].value;
                profit += supplies[i].profit;
                supplies[i].weight_used = capacity;
                capacity = 0;
                

            } 
            //for indivisible 0/1 knapsack: skip
            //go to the next article
        }
        supplies[i].cap_remaining = capacity;
    }
    
    //printing
    cout << fixed << setprecision(0);
    cout << endl;
    cout << left 
        << setw(12)  << "Article"
        << setw(10) << "Divisible"
        << setw(8) << "Weight"
        << setw(12) << "Used"
        << setw(8)  << "Value"
        << setw(8)  << "Profit"
        << setw(12) << "Cap_Rem"
        << endl;

    for (int i = 0; i < n; i++) {
        if (supplies[i].weight_used > 0) { // only print selected items
            cout << left
                << setw(12) << supplies[i].article_name
                << setw(10) << (supplies[i].divisible ? "Yes" : "No")
                << setw(8)  << supplies[i].weight
                << setw(12) << supplies[i].weight_used
                << setw(8)  << supplies[i].value
                << setw(8)  << supplies[i].profit
                << setw(12) << supplies[i].cap_remaining
                << endl;
        }
    }

    cout << "Thus the maximum profit is: " << profit << endl;

    return 0;
}

// Time Complexity: O(n log n) — due to sorting the supplies by value/weight ratio.
// Space Complexity: O(n) — to store the list of supply items and their attributes.