#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr1, vector<int>& arr2, int m, int n) {
        int gap = (m + n + 1) / 2; // initial gap

        while (gap > 0) {
            int i = 0, j = gap;

            while (j < (m + n)) {
                // get elements
                int a = get(arr1, arr2, m, i);
                int b = get(arr1, arr2, m, j);

                // swap if out of order
                if (a > b) {
                    set(arr1, arr2, m, i, b);
                    set(arr1, arr2, m, j, a);
                }

                i++;
                j++;
            }

            if (gap == 1) break;
            gap = (gap + 1) / 2; // reduce gap
        }
    }

private:
    // Helper: get value from index across arr1+arr2
    int get(vector<int>& arr1, vector<int>& arr2, int m, int idx) {
        if (idx < m) return arr1[idx];
        return arr2[idx - m];
    }

    // Helper: set value in arr1/arr2
    void set(vector<int>& arr1, vector<int>& arr2, int m, int idx, int val) {
        if (idx < m) arr1[idx] = val;
        else arr2[idx - m] = val;
    }
};

int main() {
    Solution sol;

    // 🔹 Test Case 1
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};
    sol.merge(arr1, arr2, arr1.size(), arr2.size());
    cout << "Test Case 1:\narr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << "\n\n";

    // 🔹 Test Case 2
    arr1 = {10, 12, 14};
    arr2 = {1, 3, 5};
    sol.merge(arr1, arr2, arr1.size(), arr2.size());
    cout << "Test Case 2:\narr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << "\n\n";

    // 🔹 Test Case 3
    arr1 = {2, 3, 8};
    arr2 = {4, 6, 10};
    sol.merge(arr1, arr2, arr1.size(), arr2.size());
    cout << "Test Case 3:\narr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << "\n\n";

    // 🔹 Edge Case 1: Smallest arrays
    arr1 = {1};
    arr2 = {2};
    sol.merge(arr1, arr2, arr1.size(), arr2.size());
    cout << "Edge Case 1:\narr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << "\n\n";

    // 🔹 Edge Case 2: Already sorted (no swaps needed)
    arr1 = {1, 2, 3};
    arr2 = {4, 5, 6};
    sol.merge(arr1, arr2, arr1.size(), arr2.size());
    cout << "Edge Case 2:\narr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << "\n\n";

    // 🔹 Edge Case 3: One array much smaller
    arr1 = {1};
    arr2 = {2, 3, 4, 5, 6};
    sol.merge(arr1, arr2, arr1.size(), arr2.size());
    cout << "Edge Case 3:\narr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << "\n";

    return 0;
}
