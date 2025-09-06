#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int>& arr, int k) {
    deque<int> dq;          
    vector<int> result;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        
        if (!dq.empty() && dq.front() <= i - k) {              // 1. Remove indices that are out of the current window
            dq.pop_front();
        }
                                                                // 2. Remove all smaller elements (they are useless)
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
                                                                 // 3. Add current element index
        dq.push_back(i);
                                                                // 4. If we have a full window, record the max
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter window size k: ";
    cin >> k;

    vector<int> ans = slidingWindowMaximum(arr, k);

    cout << "Sliding Window Maximums: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
