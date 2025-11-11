#include <iostream>
using namespace std;

void towerOfHanoi(char source, char destination, char auxillary, int numOfDisks){
    if (numOfDisks == 1){
        cout<< "Move Disk "<< numOfDisks << " from "<< source << " to " <<destination<< endl;
        return;
    }
    else{
        towerOfHanoi(source, auxillary, destination, numOfDisks-1);
        cout<< "Move Disk "<< numOfDisks << " from "<< source << " to " <<destination<< endl;
        towerOfHanoi(auxillary, destination, source, numOfDisks-1); 
    }
}

int main(){
    // we use recursion
    // move n-1 disks from source to auxillary
    // move nth disk to destination
    // move n-1 disks from auxillary to destination
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    char source = 'A';
    char auxillary = 'B';
    char destination = 'C';

    towerOfHanoi(source, destination, auxillary, n);


}