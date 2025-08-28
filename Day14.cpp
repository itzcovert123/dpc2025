#include <bits/stdc++.h>
using namespace std;

int atMostK(const string &s, int k) {
    int n = s.size();
    vector<int> count(26, 0); // lowercase letters
    int left = 0, res = 0, distinct = 0;

    for (int right = 0; right < n; right++) {
        if (count[s[right] - 'a'] == 0) distinct++;
        count[s[right] - 'a']++;

        while (distinct > k) {
            count[s[left] - 'a']--;
            if (count[s[left] - 'a'] == 0) distinct--;
            left++;
        }

        res += (right - left + 1);
    }

    return res;
}

int substringsWithExactlyKDistinct(string s, int k) {
    return atMostK(s, k) - atMostK(s, k - 1);
}

int main() {
    string s = "pqpqs";
    int k = 2;
    cout << substringsWithExactlyKDistinct(s, k) << endl; // Output: 7
    return 0;
}
