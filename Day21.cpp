#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int x) {
    if(st.empty()) {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(top);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int> &st) {
    if(st.empty()) return;
    
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}

int main() {
    stack<int> st;
    vector<int> input = {1, 2, 3, 4};

  
    for(int val : input) {
        st.push(val);
    }

    reverseStack(st);
  
    cout << "Reversed Stack: [ ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "]" << endl;

    return 0;
}
