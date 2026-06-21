#include <bits/stdc++.h>
using namespace std;

int findCeil(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;   // If ceil doesn't exist

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            ans = arr[mid];
            high = mid - 1;   // Try to find a smaller valid ceil
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 6, 8, 10};
    int target = 5;

    cout << "Ceil = " << findCeil(arr, target) << endl;

    return 0;
}