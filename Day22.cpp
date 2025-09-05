#include <bits/stdc++.h>
using namespace std;

int firstElementKTimes(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    for (int num : arr)
        freq[num]++;
    for (int num : arr) {
        if (freq[num] == k)
            return num;
    }
    return -1;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter k: ";
    cin >> k;

    int result = firstElementKTimes(arr, k);
    cout << "First element occurring exactly " << k << " times: " << result << endl;

    return 0;
}
