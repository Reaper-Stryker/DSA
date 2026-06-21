#include <iostream>
#include <vector>
using namespace std;

// Function to find the K-th missing positive number
int findKthPositive(vector<int> &arr, int k)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    Observation:
    The array is sorted and contains positive integers.

    At index i (0-based), if no numbers were missing,
    the expected value would be (i + 1).

    Missing numbers till index i are:

        missing = arr[i] - (i + 1)

    Example:
    arr = [2, 3, 4, 7, 11]

    Index :   0  1  2  3   4
    Value :   2  3  4  7  11
    Expect:   1  2  3  4   5

    Missing:
    2-1 = 1
    3-2 = 1
    4-3 = 1
    7-4 = 3
    11-5 = 6

    We Binary Search for the FIRST index where
    missing >= k.

    After the search:
        high points to the last index where
        missing < k.

    Final Answer:
        k + high + 1
    */

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int missing = arr[mid] - (mid + 1);

        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return k + high + 1;
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << "K-th Missing Positive Number = "
         << findKthPositive(arr, k) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

arr = [2, 3, 4, 7, 11]
k = 5

Missing numbers:
1, 5, 6, 8, 9, 10, ...

5th missing = 9

--------------------------------------

Binary Search Walkthrough:

mid = 2

arr[mid] = 4

Missing till here:
4 - (2 + 1) = 1

Only 1 number missing.
Need 5.
Move RIGHT.

Eventually:

high = 3

Answer = k + high + 1
       = 5 + 3 + 1
       = 9

--------------------------------------

Another Example:

arr = [1, 2, 3, 4]
k = 2

Missing numbers:
5, 6, 7, ...

Answer = 6

Formula:
high = 3

2 + 3 + 1 = 6

--------------------------------------

Time Complexity : O(log n)

Space Complexity : O(1)

Memory Trick:

1. Missing till index i:
      arr[i] - (i + 1)

2. Binary Search for the first index
   where missing >= k.

3. Final Answer:
      k + high + 1

(Equivalent to k + low, since low = high + 1
after the binary search ends.)
*/