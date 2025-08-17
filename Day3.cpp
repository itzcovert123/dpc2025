#include <bits/stdc++.h>
using namespace std;
//Floyd’s Cycle Detection
int findDuplicate(vector<int>& arr) {
    int slow = arr[0];
    int fast = arr[arr[0]]; // fast starts one step ahead

    
    while (slow != fast) {                    // Step 1: Find intersection in the cycle
        slow = arr[slow];
        fast = arr[arr[fast]];
    }

                                            // Step 2: Find entrance of cycle (duplicate number)
    fast = 0;  // reset fast to start index
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    vector<int> arr = {3, 1, 3, 4, 2};
    cout << "Duplicate number: " << findDuplicate(arr) << endl;
    return 0;
}
