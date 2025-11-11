//You are working on the city construction project. You have A houses in the city. You have to divide these houses into B localities such that every locality has at least one house. Also, every house in a locality should have a telephone connection wire with each of the other houses in the locality.You are given integers A and B.

// Task

// Print the minimum and the maximum number of telephone connections possible if you design the city accordingly.


#include <iostream>
using namespace std;
int main(){
    int A; // number of houses
    int B; // number of localities
    cout << "Enter number of houses: ";
    cin >> A;
    cout << "Enter number of localities: ";
    cin >> B;
    int maxConnections = 0;
    int minConnections = 0;
    //max
    //max connections can be made using:
    // 1 locality with max number of houses and 
    // B-1 localities with 1 house each
    // thus total number of connections:
    // B-1 localities: 1 house each: 0 connections
    // 1 locality with A-(B-1) houses: nC2 connections between them

    maxConnections = (B-1)*0 + (A-(B-1))* (A-(B-1) - 1) / 2;

    //min
    //min connections can be made using:
    // all houses with roughly equal houses i.e. A/B houses
    int quotient = A/B; // by default will return floor int value for the division
    int remainder = A%B; // will return the remaining houses;
    // now we have "remainder" number of LOCALITIES with "quotient+1" houses 
    // and "B-remainder" number of localities with "quotient" houses
    minConnections = remainder * ((quotient + 1) * (quotient + 1 - 1)/2) + (B-remainder)* (quotient * (quotient - 1) / 2);
    cout<<"Maximum number of connections: " << maxConnections<< endl;
    cout<<"Minimum number of connections: " << minConnections << endl;
    
    return 0;
}

// Time Complexity:
// O(1) — All operations are simple arithmetic calculations (no loops or recursion).

// Space Complexity:
// O(1) — Only a few integer variables (A, B, maxConnections, minConnections, etc.) are used, independent of input size.