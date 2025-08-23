#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";           
        if (strs.size() == 1) return strs[0];                              // Edge case: single string

        string prefix = strs[0];  // Start with the first string as reference

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {      // Compare current string with prefix
                j++;
            }
                                                                            
            prefix = prefix.substr(0, j);                                // Reduce prefix to common part
            if (prefix.empty()) return "";                                // Early stop if no common prefix
        }

        return prefix;
    }
};

int main() {
    Solution sol;
    
    vector<vector<string>> testCases = {
        {"flower", "flow", "flight"},
        {"dog", "racecar", "car"},
        {"apple", "ape", "april"},
        {""},
        {"alone"},
        {}  
    };
    
    for (auto &tc : testCases) {
        cout << "Input: ";
        for (auto &s : tc) cout << s << " ";
        cout << "\nOutput: \"" << sol.longestCommonPrefix(tc) << "\"\n\n";
    }
    return 0;
}
