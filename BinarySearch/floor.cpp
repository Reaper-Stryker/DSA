#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;   // If floor doesn't exist

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target) {
            ans = arr[mid];
            low = mid + 1;    // Try to find a larger valid floor
        } else {
            high = mid - 1;
        }
    }

    return ans;
}
int main() {
    vector<int> arr = {1, 2, 4, 6, 8, 10};
    int target = 5;

    cout << "Floor = " << findFloor(arr, target) << endl;

    return 0;
}