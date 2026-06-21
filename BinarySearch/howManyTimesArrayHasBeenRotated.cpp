#include <iostream>
#include <vector>
using namespace std;

// Function to find the number of times the array has been rotated
int findRotationCount(vector<int> &arr)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    Observation:
    - If a sorted array is rotated k times,
      then the MINIMUM element will be at index k.

    Example:
    Original : [1, 2, 3, 4, 5]
    Rotated  : [4, 5, 1, 2, 3]

    Minimum element = 1
    Index of 1 = 2

    Therefore, the array has been rotated 2 times.

    So, instead of counting rotations directly,
    we just find the index of the minimum element
    using Binary Search.

    At every step:
    - One half is guaranteed to be sorted.
    - The minimum lies in the unsorted half.
    */

    int low = 0, high = arr.size() - 1;
    int ans = arr[0];
    int index = 0;

    while (low <= high)
    {
        // If the current range is already sorted
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            break;
        }

        int mid = low + (high - low) / 2;

        // Left half is sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        // Right half is sorted
        else
        {
            if (arr[mid] < ans)
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

    cout << "Array has been rotated "
         << findRotationCount(arr)
         << " times." << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example 1:

arr = [4, 5, 6, 7, 0, 1, 2]

Minimum element = 0
Index = 4

Hence, array is rotated 4 times.

--------------------------------------

Example 2:

arr = [1, 2, 3, 4, 5]

Already sorted.

Minimum element = 1
Index = 0

Hence, rotation count = 0.

--------------------------------------

Example 3:

arr = [5, 1, 2, 3, 4]

Minimum element = 1
Index = 1

Hence, rotation count = 1.

--------------------------------------

Time Complexity : O(log n)

Space Complexity : O(1)

Memory Trick:

1. Rotation Count = Index of Minimum Element.
2. If current range is sorted,
      minimum is at 'low'.
3. If left half is sorted,
      store arr[low] and search right.
4. Else,
      store arr[mid] and search left.
*/