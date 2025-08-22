#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        
                                                                
        for (char c : s) {                                // Step 1: Split string into words
            if (c == ' ') {
                if (!word.empty()) {                      // Found a word
                    words.push_back(word);
                    word = "";                            // Reset for next word
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) words.push_back(word);         // Last word

                                                       
        reverse(words.begin(), words.end());      


        string result = "";                                // Step 3: Join words with a single space
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) result += " ";
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseWords("the sky is blue") << endl;      
    cout << sol.reverseWords("  hello world  ") << endl;      
    cout << sol.reverseWords("a good   example") << endl;     
    cout << sol.reverseWords("    ") << endl;                 
    cout << sol.reverseWords("word") << endl;                 

    return 0;
}
