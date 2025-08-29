#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1); 
    int n = s.size();
    int maxLen = 0, left = 0;

    for (int right = 0; right < n; right++) {
        char c = s[right];


        if (lastIndex[c] >= left) {
            left = lastIndex[c] + 1;
        }

        lastIndex[c] = right; 
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    vector<string> testCases = {"abcabcbb", "bbbbb", "pwwkew", "abcdefgh", "a"};
    for (auto &tc : testCases) {
        cout << "Input: " << tc << " -> Output: " 
             << lengthOfLongestSubstring(tc) << endl;
    }
    return 0;
}
