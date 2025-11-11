#include <iostream>
#include <vector>
using namespace std;

int tile = 0;

void placeTile(int x1, int y1, int x2, int y2, int x3, int y3, vector<vector<int>> &board){
    tile++;
    board[x1][y1] = tile;
    board[x2][y2] = tile;
    board[x3][y3] = tile;
}

void tiling(int n, int row, int col, int missingX, int missingY, vector<vector<int>> &board) {
    if(n==1){
        return;
    }
    
    int mid = n / 2;
    int cx = row + mid;
    int cy = col + mid;

    int topLeftX = cx - 1, topLeftY = cy - 1;
    int topRightX = cx - 1, topRightY = cy;
    int botLeftX = cx, botLeftY = cy - 1;
    int botRightX = cx, botRightY = cy;

    //missing tile in top left quadrant 
     if (missingX < cx && missingY < cy) {
        // we need to place tile in other 3 quad
        placeTile(topRightX, topRightY, botLeftX, botLeftY, botRightX, botRightY, board);
        tiling(mid, row, col, missingX, missingY, board);
        tiling(mid, row, cy, topRightX, topRightY, board);
        tiling(mid, cx, col, botLeftX, botLeftY, board);
        tiling(mid, cx, cy, botRightX, botRightY, board);
    }
    
    else if (missingX < cx && missingY >= cy) {
        placeTile(topLeftX, topLeftY, botLeftX, botLeftY, botRightX, botRightY, board);
        tiling(mid, row, col, topLeftX, topLeftY, board);
        tiling(mid, row, cy, missingX, missingY, board);
        tiling(mid, cx, col, botLeftX, botLeftY, board);
        tiling(mid, cx, cy, botRightX, botRightY, board);
    }
    else if (missingX >= cx && missingY < cy) {
        placeTile(topLeftX, topLeftY, topRightX, topRightY, botRightX, botRightY, board);
        tiling(mid, row, col, topLeftX, topLeftY, board);
        tiling(mid, row, cy, topRightX, topRightY, board);
        tiling(mid, cx, col, missingX, missingY, board);
        tiling(mid, cx, cy, botRightX, botRightY, board);
    }
    else {
        placeTile(topLeftX, topLeftY, topRightX, topRightY, botLeftX, botLeftY, board);
        tiling(mid, row, col, topLeftX, topLeftY, board);
        tiling(mid, row, cy, topRightX, topRightY, board);
        tiling(mid, cx, col, botLeftX, botLeftY, board);
        tiling(mid, cx, cy, missingX, missingY, board);
    }
}

int main(){
    int n;
    cout << "Enter side of chess board i.e. n = 2^k: ";
    cin >> n;
    int x, y;
    cout << "Enter x y , the coordinates of the missing tile:";
    cin >> x >> y;
    vector<vector <int>> board(n, vector<int>(n, 0));
    board[x][y] = -1;
    tiling(n, 0, 0, x, y, board);
    for(int x  = 0; x < n ; x++){
        for(int y = 0; y < n ; y++){
            cout << board[x][y] << " ";
        }
        cout << endl;
    }
}

// T(n)=4T(n/2)+O(1)
// O(n^2)
// space O(n^2) for board