#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 4, 5};
    int target = 2;

    cout << lowerBound(arr, target) << endl;   // Output: 1

    return 0;
}