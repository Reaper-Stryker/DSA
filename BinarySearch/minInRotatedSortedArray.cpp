#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the minimum element in a rotated sorted array
int findMinimum(vector<int> &arr)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    Observation:
    - The array was originally sorted.
    - After rotation, at least one half (left or right) is always sorted.
    - The minimum element always lies in the UNSORTED half.
    - If an entire range is already sorted (arr[low] <= arr[high]),
      then arr[low] is the minimum in that range.

    Algorithm:
    1. If current search space is sorted:
         -> Update answer with arr[low].
         -> Break.
    2. If left half is sorted:
         -> arr[low] is the smallest in that half.
         -> Store it and search the right half.
    3. Otherwise, right half is sorted:
         -> arr[mid] is the smallest in that half.
         -> Store it and search the left half.

    This keeps reducing the search space by half.
    */

    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        // Entire search space is sorted
        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }

        int mid = low + (high - low) / 2;

        // Left half is sorted
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // Right half is sorted
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

    cout << "Minimum Element: " << findMinimum(arr) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

arr = [4, 5, 6, 7, 0, 1, 2]

Iteration 1:
low = 0, high = 6
mid = 3

Left half = [4, 5, 6, 7] (sorted)
Minimum in left half = 4
Store 4 and move right.

Iteration 2:
low = 4, high = 6

Current search space = [0, 1, 2]
Already sorted.

Minimum = arr[low] = 0.

Answer = 0

--------------------------------------

Example:

arr = [1, 2, 3, 4, 5]

Entire array is already sorted.

Return arr[0] = 1.

--------------------------------------

Time Complexity : O(log n)

Space Complexity : O(1)

Memory Trick:

1. If arr[low] <= arr[high],
      current range is sorted,
      answer = arr[low].

2. If left half is sorted,
      store arr[low],
      search right.

3. Else,
      right half is sorted,
      store arr[mid],
      search left.

Minimum always lies in the unsorted half
(or at the beginning of a sorted half).
*/