#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(const string &expr) {
    stack<int> st;
    stringstream ss(expr);
    string token;
    
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else st.push(a / b); // integer division truncates toward 0
        } else {
            st.push(stoi(token)); // convert operand to int and push
        }
    }
    
    return st.top();
}

int main() {
    cout << evaluatePostfix("2 1 + 3 *") << endl;                                 
    cout << evaluatePostfix("15 7 1 1 + - / 3 * 2 1 1 + + -") << endl;
    cout << evaluatePostfix("5") << endl;                         
    return 0;
}
