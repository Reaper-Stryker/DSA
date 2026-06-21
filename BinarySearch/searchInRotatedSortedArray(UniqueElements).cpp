#include <iostream>
#include <vector>
using namespace std;

// Function to search target in a rotated sorted array
int searchInRotatedArray(vector<int> &arr, int target)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    Observation:
    - A rotated sorted array always has one half completely sorted.
    - At every step, either:
        1. Left half is sorted.
        2. Right half is sorted.

    Algorithm:
    - Find mid.
    - If arr[mid] == target, return mid.
    - Check which half is sorted.
    - If left half is sorted:
        -> Check if target lies within [arr[low], arr[mid]).
        -> If yes, search left.
        -> Else, search right.
    - Else (right half is sorted):
        -> Check if target lies within (arr[mid], arr[high]].
        -> If yes, search right.
        -> Else, search left.

    This eliminates half of the search space every time,
    giving O(log n) complexity.
    */

    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        // Left half is sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else
        {
            if (arr[mid] < target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int target = 3;

    int index = searchInRotatedArray(arr, target);

    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

arr = [7, 8, 9, 1, 2, 3, 4, 5, 6]
target = 3

Iteration 1:
low = 0, high = 8
mid = 4 -> arr[mid] = 2

Left half = [7, 8, 9, 1, 2] (not sorted)
Right half = [2, 3, 4, 5, 6] (sorted)

Target 3 lies in right half.
Move low = mid + 1.

Iteration 2:
low = 5, high = 8
mid = 6 -> arr[mid] = 4

Left half = [3, 4] (sorted)

Target 3 lies in left half.
Move high = mid - 1.

Iteration 3:
low = 5, high = 5
mid = 5 -> arr[mid] = 3

Found target at index 5.

--------------------------------------

Time Complexity : O(log n)

Space Complexity : O(1)

Memory Trick:

1. At least ONE HALF is always sorted.
2. Identify the sorted half.
3. Check if the target lies in that half.
4. Search there; otherwise search the other half.
*/