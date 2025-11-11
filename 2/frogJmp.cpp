#include <iostream>
using namespace std;
int main(){
    int X, Y, s, T;
    cout << "Enter X, Y, s and T: ";
    cin >> X >> Y >> s >> T;

    int count = 0;
    for(int x = X; x <= X + s; x++){
        for(int y = Y; y <= Y + s; y++){
            if((x + y) <= T){           
                count++;
            }
        }
    }
    cout << "Number of valid points with integer coordinates: " << count << endl;
    return 0;
}
