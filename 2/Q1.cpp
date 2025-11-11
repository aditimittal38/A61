// You are an IT company's manager. Based on their performance over the last N working days,
//  you must rate your employee. You are given an array of N integers called workload, where
//   workload[i] represents the number of hours an employee worked on an ith day. The employee
//    must be evaluated using the following criteria: ∙ 
// Rating = the maximum number of consecutive working days when the employee has worked more
//  than 6 hours. 
// You are given an integer N where N represents the number of working days. You are given an
//  integer array workload where workload[i] represents the number of hours an employee worked on an ith day. 

#include <iostream>
using namespace std;

int main(){
    int N;
    cout<<"Enter number of days: ";
    cin>> N;
    int workload[N];
    cout<<"Enter workload of employee for "<< N <<" days: ";
    for(int i = 0; i<N; i++){
        cin>> workload[i];
    }
    int maxConsecutiveDays = 0;
    int rating = 0;
    for (int i = 0; i<N; i++){
        if(workload[i]<=6){
            rating = max(rating, maxConsecutiveDays);
            maxConsecutiveDays = 0;
        }
        else{
            maxConsecutiveDays++;
        }
        rating = max(rating, maxConsecutiveDays);

    }
    cout<<"Rating of employee = "<< rating<<endl;

}
