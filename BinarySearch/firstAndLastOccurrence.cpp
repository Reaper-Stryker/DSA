#include <iostream>
#include <vector>
using namespace std;

// Function to find first occurrence of target
int firstOccurrence(vector<int> &arr, int target)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We need the LEFTMOST index where target appears.

    Binary Search Modification:
    - If arr[mid] == target:
        -> This can be our answer.
        -> But there might be another occurrence on the LEFT.
        -> Store mid and move high = mid - 1.
    - If arr[mid] < target:
        -> Target can only be on the right.
        -> Move low = mid + 1.
    - Otherwise:
        -> Move left (high = mid - 1).

    At the end, we get the first occurrence.
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

// Function to find last occurrence of target
int lastOccurrence(vector<int> &arr, int target)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We need the RIGHTMOST index where target appears.

    Binary Search Modification:
    - If arr[mid] == target:
        -> This can be our answer.
        -> But there might be another occurrence on the RIGHT.
        -> Store mid and move low = mid + 1.
    - If arr[mid] < target:
        -> Move right.
    - Otherwise:
        -> Move left.

    At the end, we get the last occurrence.
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

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    cout << "First Occurrence Index: " << firstOccurrence(arr, target) << endl;
    cout << "Last Occurrence Index: " << lastOccurrence(arr, target) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

arr = [1, 2, 2, 2, 3, 4, 5]
target = 2

First Occurrence:
- Find target.
- Don't stop.
- Search LEFT for an earlier occurrence.
- Answer = 1.

Last Occurrence:
- Find target.
- Don't stop.
- Search RIGHT for a later occurrence.
- Answer = 3.

--------------------------------------

Time Complexity : O(log n)
Space Complexity : O(1)

Memory Trick:

FIRST OCCURRENCE:
arr[mid] == target
=> Save answer and move LEFT (high = mid - 1)

LAST OCCURRENCE:
arr[mid] == target
=> Save answer and move RIGHT (low = mid + 1)
*/