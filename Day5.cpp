#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int>& arr) {             // Function 
    int n = arr.size();
    vector<int> leaders;
    
                                                        // Step 1: Last element is always a leader
    int maxRight = arr[n-1];
    leaders.push_back(maxRight);
    
                                                        // Step 2: Traverse array from right to left
    for (int i = n-2; i >= 0; i--) {
                                                        // If current element is >= maximum seen so far
        if (arr[i] >= maxRight) {
            leaders.push_back(arr[i]);                  // It is a leader
            maxRight = arr[i];                          // Update maxRight
        }
    }
    
                                                      // Step 3: Leaders are collected in reverse order → fix it
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    
    vector<int> ans = findLeaders(arr);
    
    cout << "Leaders: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}
