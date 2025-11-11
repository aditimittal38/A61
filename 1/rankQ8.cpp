#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int,int> freq;

void track(int x) {
    freq[x]++;
}

int getRankOfNumber(int x) {
    int rank = 0;
    for (auto &p : freq) {
        if (p.first <= x) rank += p.second;
    }
    return rank - 1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        track(arr[i]);
    }

    int q;
    cout << "Enter number to find rank of: ";
    cin >> q;
    cout << "Rank of " << q << " is: " << getRankOfNumber(q) << endl;

    return 0;
}

//time: O(1) insertion
// O(k) rank
// O(k) space


/*
#include <iostream>
using namespace std;

struct Node {
    int val;
    int leftCount;   // number of nodes in the left subtree
    Node *left, *right;

    Node(int v) {
        val = v;
        leftCount = 0;
        left = right = nullptr;
    }
};

// Insert number x into the BST
Node* track(Node* root, int x) {
    if (root == nullptr) 
        return new Node(x);

    if (x <= root->val) {
        root->left = track(root->left, x);
        root->leftCount++; // increase left count because new value goes left
    } else {
        root->right = track(root->right, x);
    }
    return root;
}

// Get rank of number x (count of numbers <= x)
int getRankOfNumber(Node* root, int x) {
    if (root == nullptr)
        return 0;

    if (x == root->val)
        return root->leftCount; // all nodes in left subtree are smaller
    else if (x < root->val)
        return getRankOfNumber(root->left, x);
    else
        // include leftCount + 1 (for root) + rank in right subtree
        return root->leftCount + 1 + getRankOfNumber(root->right, x);
}

int main() {
    Node* root = nullptr;
    int stream[] = {5, 1, 4, 4, 5, 9, 7, 13, 3};
    int n = sizeof(stream)/sizeof(stream[0]);

    for (int i = 0; i < n; i++) {
        root = track(root, stream[i]);
    }

    cout << "getRankOfNumber(1) = " << getRankOfNumber(root, 1) << endl;
    cout << "getRankOfNumber(3) = " << getRankOfNumber(root, 3) << endl;
    cout << "getRankOfNumber(4) = " << getRankOfNumber(root, 4) << endl;

    return 0;
}

*/

//Time: O(log n)
//Space: O(n)















// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter number of elements in the stream: ";
//     cin >> n;

//     int arr[n];
//     cout << "Enter the stream of numbers:\n";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int q;
//     cout << "Enter number of queries: ";
//     cin >> q;

//     cout << "Enter numbers to get their rank:\n";
//     for (int i = 0; i < q; i++) {
//         int x;
//         cin >> x;
//         int rank = 0;
//         for (int j = 0; j < n; j++) {
//             if (arr[j] <= x) {
//                 rank++;
//             }
//         }
//         cout << "getRankOfNumber(" << x << ") = " << rank-1 << endl;
//     }

//     return 0;
// }
