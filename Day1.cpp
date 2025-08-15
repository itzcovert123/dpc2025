#include <bits/stdc++.h>
using namespace std;

// Dutch National Flag algorithm
void sortColors(vector<int>& arr) {
    int low = 0;               
    int mid = 0;               
    int high = arr.size() - 1; 

    while (mid <= high) {
        if (arr[mid] == 0) {        // Case 1: Current element is 0
            
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } 
        else if (arr[mid] == 1) {     // Case 2: Current element is 1
            mid++;
        } 
        else {                       // Case 3: Current element is 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 1, 0, 2, 1, 0};
    sortColors(arr);
    for (int x : arr) 
        cout << x << " ";
    return 0;
}
