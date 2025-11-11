/*
6. Huffman Coding for IoT Sensor Data
IoT network with 20 sensors, each with weightsuency (occurrence per hour) and importance factor (1–5).
Input:
Sensors with (weightsuency × Importance):
Temp(400), Humidity(300), Pressure(600), Light(150), Gas(120), Motion(200), Smoke(100), Vibration(250), Sound(350), CO2(450), pH(80), Toxic(60), Voltage(220), Current(180), Wind(140), Rain(200), GPS(90), UV(70),
Dust(160), Salinity(110)
Expected Output:
Shortest Codes → Pressure=‘0’, CO2=‘10’, Temp=‘110’, … Longest Codes → Toxic=‘1111110’, pH=‘1111111’ Average Code Length ≈ 5.3 bits
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <map>
using namespace std;

struct SensorNode {
    string sensor;
    int weight;
    SensorNode* left;
    SensorNode* right;
    SensorNode(string s, int w) : sensor(s), weight(w), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(SensorNode* a, SensorNode* b) {
        return a->weight > b->weight; // min-heap
    }
};

void getCodes(SensorNode* root, string code, map<string,string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->sensor] = code;
    }
    getCodes(root->left, code + "0", codes);
    getCodes(root->right, code + "1", codes);
}

int main() {
    int n;
    cout << "Enter number of sensors: ";
    cin >> n;

    vector<pair<string,int>> sensors(n);
    cout << "Enter sensor name and weight for each sensor:\n";
    for (int i = 0; i < n; i++) {
        cin >> sensors[i].first >> sensors[i].second;
    }

    priority_queue<SensorNode*, vector<SensorNode*>, Compare> pq;

    for (auto s : sensors) {
        pq.push(new SensorNode(s.first, s.second));
    }

    while (pq.size() > 1) {
        SensorNode* a = pq.top(); pq.pop();
        SensorNode* b = pq.top(); pq.pop();
        SensorNode* parent = new SensorNode("", a->weight + b->weight);
        parent->left = a;
        parent->right = b;
        pq.push(parent);
    }

    SensorNode* root = pq.top();

    map<string,string> codes;
    getCodes(root, "", codes);

    cout << "\nHuffman Codes for sensors:\n";
    for (auto s : sensors) {
        cout << s.first << " : " << codes[s.first] << endl;
    }

    int totalWeight = 0;
    double avg = 0;
    for (auto s : sensors) {
        int len = codes[s.first].size();
        avg += len * s.second;
        totalWeight += s.second;
    }
    avg /= totalWeight;
    cout << "\nAverage code length ≈ " << avg << " bits\n";

    return 0;
}

// Time Complexity: O(n log n) — building the Huffman tree involves repeatedly extracting and inserting nodes into a min-heap.
// Space Complexity: O(n) — for storing the tree nodes, heap, and code mappings.