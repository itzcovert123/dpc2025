#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Edge case: odd length cannot be valid
        if (s.size() % 2 != 0) return false;

        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false; // no matching opener
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty(); // valid only if no unmatched open brackets remain
    }
};

int main() {
    Solution sol;
    cout << boolalpha; 
    cout << sol.isValid("()") << endl;       
    cout << sol.isValid("([)]") << endl;     
    cout << sol.isValid("[{()}]") << endl;   
    cout << sol.isValid("") << endl;         
    cout << sol.isValid("{[}") << endl;      
}
