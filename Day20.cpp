#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int value) {
    if (st.empty() || value < st.top()) {
        st.push(value);
        return;
    }
    int topValue = st.top();
    st.pop();
    insertSorted(st, value);
    st.push(topValue);
}

void sortStack(stack<int> &st) {
    if (st.empty()) return;
    int topValue = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, topValue);
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    int n, value;

    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    cout << "Enter the elements of the stack (top element first):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        st.push(value);
    }

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    cout << "Re-enter the elements for sorting:" << endl;
    stack<int> temp;
    for (int i = 0; i < n; i++) {
        cin >> value;
        temp.push(value);
    }
    st = temp;

    sortStack(st);

    cout << "Sorted Stack (top to bottom): ";
    printStack(st);

    return 0;
}
