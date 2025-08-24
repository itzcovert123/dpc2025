#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto &p : groups) {
            result.push_back(p.second);
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res1 = sol.groupAnagrams(strs1);
    for (auto &group : res1) {
        cout << "[";
        for (size_t i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i != group.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    // Test case 2
    vector<string> strs2 = {""};
    vector<vector<string>> res2 = sol.groupAnagrams(strs2);
    for (auto &group : res2) {
        cout << "[";
        for (size_t i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i != group.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    // Test case 3
    vector<string> strs3 = {"a"};
    vector<vector<string>> res3 = sol.groupAnagrams(strs3);
    for (auto &group : res3) {
        cout << "[";
        for (size_t i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i != group.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
