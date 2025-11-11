/*
The country of Byteland consists of n cities. Between any 2 cities it is possible to have a railway track and a road. Railway tracks are bidirectional, meaning if there exists a railway track between u and v then you can take a train from u to v as well as from v to u. Similarly, roads are bidirectional, meaning if there exists a route between u and v then you can drive from u to v as well as from v to u.

2 cities, u and v are called railway-connected if it is possible to travel between u and v using railway tracks.

2 cities, u and v are called road-connected if it is possible to travel between u and v using roads.The transportation network is called balanced if for all pairs of cities u, v:
u,v are railway-connected if and only if u,v are road-connected.

Initially, there are n cities and no roads or railways in Byteland. You will be given q instructions asking you to build either a railway track or a road between some 2 cities. After each instruction, you must report whether the transportation network is balanced.

Input format

The first line of input will contain 2 integers, n and q. q lines will follow. Each line will contain 3 space-separated integers in one of the following formats:

1 u v : build a railway track between u and v

2 u v : build a road between u and v

Output format

You must print q lines. The ith line contains an answer to the question whether the transport network is balanced after the ith instruction. If it is balanced print "YES" (without quotes) otherwise print "NO" (without quotes)
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int flag, vector<int>& comp, vector<vector<int>>& adj) {
    comp[node] = flag;
    for (int neighbour : adj[node]) {
        if (comp[neighbour] == -1)
            dfs(neighbour, flag, comp, adj);
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> railway(n+1), road(n+1);

    for (int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) {
            railway[u].push_back(v);
            railway[v].push_back(u);
        } else {
            road[u].push_back(v);
            road[v].push_back(u);
        }
        
        // For railway: connected components
        vector<int> comp_rail(n+1, -1);
        int flag = 0;
        for (int j = 1; j <= n; j++) {
            if (comp_rail[j] == -1) {
                dfs(j, flag, comp_rail, railway);
                flag++; 
            }
        }

        // For road: connected components
        vector<int> comp_road(n+1, -1);
        flag = 0;
        for (int j = 1; j <= n; j++) {
            if (comp_road[j] == -1) {
                dfs(j, flag, comp_road, road);
                flag++;
            }
        }

        // Check if network is balanced
        bool balanced = true;
        for (int j = 1; j <= n; j++) {
            if (comp_rail[j] != comp_road[j]) {
                balanced = false;
                break;
            }
        }

        cout << (balanced ? "YES" : "NO") << endl;
    }

    return 0;
}




// class cityNetwork{
// public:
//     int u; //1st city
//     int v; //2nd city
//     bool road; // whther road exists (road exists, road = 1, else 0)
//     bool railway; // whether railway exists. if road=0, railways can not be 1

//     cityNetwork(int u = -1, int v = -1, bool road = 0, bool railway = 0 ){
//         // as initially there are n cities and no roads or railways between them.
//         this->u = u;
//         this->v = v;
//         if(road == 1){
//             this->road = 1;
//             if(this->railway == 0){
//                 this->railway = railway;
//             }
//         }
//         if(railway == 1){
//             this->railway = 1;
//             if(this->road == 0){
//                 this->road = road;
//             }
//         }
        
       
//     }
// };

// int main(){
//     // input format:
//     int n, q;
//     cin >> n >> q;



//     vector<cityNetwork> cities;
//     for(int i=0;i<q;i++){
//         //q instructions:
//         //instruction format
//         int road_or_railway, u, v;        
//         // railways psbl only if road exists
//         // i.e. if between u and v road_or_railway!=2 (no road) road_or_railway can not be 1.
//         cin >> road_or_railway >> u >> v;
//         if(road_or_railway == 2){ //road_or_railway = 2 if road
//             cities[i] = cityNetwork(u, v, 1, 0);
//         }
//         else if(road_or_railway == 1){ // road_or_railway = 1 if railway
//             cities[i] = cityNetwork(u, v, 0, 1);
//         }
//         // now to check if the transport is balanced
//         for(int j =0; j<n; j++){
//             // balanced if
//             // no roads no railways
//             // roads but no railways
//             // roads and railways

//             // unbalanced if railway but no road
//             if(cities[j].railway && !cities[j].road){
//                 cout << "Not balanced" << endl;
//             } 
//             else{
//                 cout << "Balanced" << endl;
//             }
//         }
        

//     }

// }


// if(this->road == 0){
//             this->road = road; // update road argument only if it doesnt previosuly exist
//         }
// if(this->road == 0){ //if road does not exist
//     if (railway == 1){
//         cout << "Road does not exists between" << u << " and  " << v;
//         cout << "Railway can not thus be estabkished here." << endl; 

//     }
//     this->railway = 0;
// }
// else{
//         this->railway = railway;
// }