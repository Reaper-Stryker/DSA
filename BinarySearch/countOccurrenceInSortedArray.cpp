#include <iostream>
#include <vector>
using namespace std;

// Function to find first occurrence
int firstOccurrence(vector<int> &arr, int target)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    To count occurrences, we first need the first position
    where the target appears.

    If arr[mid] == target:
        -> Store mid as a possible answer.
        -> Search on the LEFT for an earlier occurrence.

    Otherwise, perform normal binary search.
    */

    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

// Function to find last occurrence
int lastOccurrence(vector<int> &arr, int target)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    To count occurrences, we also need the last position
    where the target appears.

    If arr[mid] == target:
        -> Store mid as a possible answer.
        -> Search on the RIGHT for a later occurrence.
    */

    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

// Function to count occurrences
int countOccurrences(vector<int> &arr, int target)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    Number of occurrences =
        (last occurrence - first occurrence + 1)

    Example:
    arr = [1, 2, 2, 2, 3]

    first = 1
    last  = 3

    count = 3 - 1 + 1 = 3

    If target is absent, first occurrence will be -1,
    so return 0.
    */

    int first = firstOccurrence(arr, target);

    if (first == -1)
        return 0;

    int last = lastOccurrence(arr, target);

    return last - first + 1;
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    cout << "Count of " << target << " = "
         << countOccurrences(arr, target) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example 1:

arr = [1, 2, 2, 2, 3, 4, 5]
target = 2

First Occurrence = 1
Last Occurrence  = 3

Count = 3 - 1 + 1 = 3

--------------------------------------

Example 2:

arr = [1, 3, 5, 7]
target = 2

First Occurrence = -1

Target not present.
Count = 0

--------------------------------------

Time Complexity : O(log n)
(Two binary searches)

Space Complexity : O(1)

Memory Trick:

1. Find FIRST occurrence.
2. Find LAST occurrence.
3. Count = last - first + 1.
4. If first == -1, answer is 0.
*/