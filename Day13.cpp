#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0, maxLen = 1;

        for (int center = 0; center < n; center++) {
            // Odd length palindrome
            expand(s, center, center, start, maxLen);
            // Even length palindrome
            expand(s, center, center + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expand(string &s, int left, int right, int &start, int &maxLen) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter string: ";
    cin >> input;

    cout << "Longest Palindromic Substring: " 
         << sol.longestPalindrome(input) << endl;

    return 0;
}
