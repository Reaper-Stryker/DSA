#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    cout << sol.searchInsert(nums, target) << endl; // expected 2

    target = 2;
    cout << sol.searchInsert(nums, target) << endl; // expected 1

    target = 7;
    cout << sol.searchInsert(nums, target) << endl; // expected 4

    return 0;
}