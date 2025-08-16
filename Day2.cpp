#include <iostream>
#include <vector>
using namespace std;

// Function 
int findMissingNumber(vector<int> arr) {
    int n = arr.size() + 1;                     // +1 for missing num
    int expectedSum = n * (n + 1) / 2; 
    int actualSum = 0;

    
    for (int i = 0; i < arr.size(); i++) {    // sum of elements in array
        actualSum = actualSum + arr[i];
    }

    
    return expectedSum - actualSum;          // difference is missing number
}

int main() {
    // Test case 1
    vector<int> arr1 = {1, 2, 4, 5};
    cout << "Missing number: " << findMissingNumber(arr1) << endl;

    // Test case 2
    vector<int> arr2 = {2, 3, 4, 5};
    cout << "Missing number: " << findMissingNumber(arr2) << endl;

    // Test case 3
    vector<int> arr3 = {1, 2, 3, 4};
    cout << "Missing number: " << findMissingNumber(arr3) << endl;

    // Test case 4
    vector<int> arr4 = {1};
    cout << "Missing number: " << findMissingNumber(arr4) << endl;

    // Test case 5 (big input, but same logic)
    vector<int> arr5;
    for (int i = 1; i <= 999999; i++) {
        arr5.push_back(i);
    }
    cout << "Missing number: " << findMissingNumber(arr5) << endl;

    return 0;
}
