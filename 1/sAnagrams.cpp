#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Function to group anagrams in place
void groupAnagrams(vector<string>& words) {
    map<string, vector<string>> anagramMap;

    // Step 1: Group words by their sorted key
    for (auto& word : words) {
        string key = word;
        sort(key.begin(), key.end());   // e.g. "bat" → "abt"
        anagramMap[key].push_back(word);
    }

    // Step 2: Overwrite original array so that anagrams are adjacent
    int index = 0;
    for (auto& group : anagramMap) {
        for (auto& w : group.second) {
            words[index++] = w;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; ++i)
        cin >> words[i];
    // vector<string> words = {"listen", "silent", "hello", "world", "ehllo", "drwol", "apple", "pleap"};

    // Function modifies the original array directly
    groupAnagrams(words);

    cout << "\nAnagrams grouped together:\n";
    for (auto& w : words)
        cout << w << " ";
    cout << endl;

    return 0;
}

// can use 
//#include <cctype> 
//tolower(char) for case senstivity

//time: O(N * Klogk)
//space: O(N*K)




// int n;
    // cout << "Enter number of words: ";
    // cin >> n;
    // vector<string> words;
    // cout<<"Enter array of strings: ";
    // string input;
    // for (int i = 0; i < n; i++) {
    //     getline(cin, input);
    //     words.push_back(input);
    // }