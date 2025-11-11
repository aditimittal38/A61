#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<string> sort_anagrams(vector<string>& arr) {
    map<string, vector<string>> anagram_groups;

    for (int i = 0; i < arr.size(); i++) {
        string sorted_s = arr[i];
        sort(sorted_s.begin(), sorted_s.end());
        anagram_groups[sorted_s].push_back(arr[i]);
    }

    vector<string> result;
    for (const auto& pair : anagram_groups) {
        for (const string& s : pair.second) {
            result.push_back(s);
        }
    }

    return result;
}

int main() {
    vector<string> words = {"listen", "silent", "hello", "world", "ehllo", "drwol", "apple", "pleap"};

    vector<string> sorted_words = sort_anagrams(words);
    cout << "Array after sorting anagrams:\n";
    for (const string& word : sorted_words) {
        cout << word << " ";
    }
    cout << endl;
}




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