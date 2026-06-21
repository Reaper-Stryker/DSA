#include <iostream>
#include <vector>
using namespace std;

// Function to search target in a rotated sorted array with duplicates
bool searchInRotatedArray(vector<int> &arr, int target)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    In the unique elements case, one half is always sorted.

    But with duplicates, consider:
    arr = [1, 0, 1, 1, 1]

    low = 0, mid = 2, high = 4

    arr[low] == arr[mid] == arr[high] == 1

    Here, we CANNOT determine which half is sorted.

    Trick:
    - If arr[low] == arr[mid] == arr[high],
      simply shrink the search space:
            low++
            high--

    Otherwise, proceed exactly like the unique elements case.

    Worst Case:
    Due to repeated shrinking, complexity can degrade to O(n).
    */

    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return true;

        // Cannot determine the sorted half
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }

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

    return false;
}

int main()
{
    vector<int> arr = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    if (searchInRotatedArray(arr, target))
        cout << "Target Found";
    else
        cout << "Target Not Found";

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example 1:

arr = [2, 5, 6, 0, 0, 1, 2]
target = 0

mid eventually reaches 0.
Answer = true.

--------------------------------------

Example 2:

arr = [1, 0, 1, 1, 1]
target = 0

Initially:
low = 0, mid = 2, high = 4

arr[low] = arr[mid] = arr[high] = 1

Cannot decide which half is sorted.

Shrink:
low++
high--

Now the ambiguity is removed and binary search continues.

--------------------------------------

Time Complexity:
Average Case : O(log n)
Worst Case   : O(n)
(when many duplicates force repeated shrinking)

Space Complexity : O(1)

Memory Trick:

1. If arr[mid] == target → return true.
2. If arr[low] == arr[mid] == arr[high]:
      low++, high--.
3. Else identify the sorted half.
4. Check whether the target lies in that half.
5. Repeat until found or search space becomes empty.
*/