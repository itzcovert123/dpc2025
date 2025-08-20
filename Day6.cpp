#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    int n = arr.size();
    long long prefixSum = 0;

                                                          // Map: prefixSum -> all indices where this prefix appeared
    unordered_map<long long, vector<int>> prefixMap;

                                                          // Special case: prefix sum = 0 from beginning
    prefixMap[0].push_back(-1);

    vector<pair<int, int>> result;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];                               // update running sum

                                                            // If this prefixSum was seen before
        if (prefixMap.find(prefixSum) != prefixMap.end()) {
            for (int startIndex : prefixMap[prefixSum]) {
                result.push_back({startIndex + 1, i});
            }
        }

                                                          // Store this index for the prefixSum
        prefixMap[prefixSum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};

    auto result = findZeroSumSubarrays(arr);

    cout << "Subarrays with sum 0:\n";
    for (auto &p : result) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
