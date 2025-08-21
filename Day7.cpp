#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0; // At least 3 bars needed to trap water

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                // If current bar is taller/equal, update leftMax
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left]; // Water trapped
                left++;
            } else {
                // If current bar is taller/equal, update rightMax
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right]; // Water trapped
                right--;
            }
        }
        return water;
    }
};

int main() {
    Solution sol;

    vector<int> h1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Output 1: " << sol.trap(h1) << endl; 

    vector<int> h2 = {4,2,0,3,2,5};
    cout << "Output 2: " << sol.trap(h2) << endl; 

    vector<int> h3 = {1,1,1};
    cout << "Output 3: " << sol.trap(h3) << endl; 

    vector<int> h4 = {5};
    cout << "Output 4: " << sol.trap(h4) << endl; 

    vector<int> h5 = {2,0,2};
    cout << "Output 5: " << sol.trap(h5) << endl; 

    return 0;
}
