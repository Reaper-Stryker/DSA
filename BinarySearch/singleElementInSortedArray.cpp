#include <iostream>
#include <vector>
using namespace std;

// Function to find the single element in a sorted array
int singleNonDuplicate(vector<int> &arr)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    Observation:
    - Every element appears exactly twice except one element.
    - Before the single element:
          First occurrence -> Even index
          Second occurrence -> Odd index

      Example:
      [1, 1, 2, 2, 3, 4, 4, 5, 5]
                ^
              Single = 3

      Pairs:
      (0,1), (2,3)

    - After the single element, this pattern breaks:
          First occurrence -> Odd index
          Second occurrence -> Even index

    Binary Search Trick:
    --------------------
    If mid is EVEN:
        - If arr[mid] == arr[mid + 1]
              -> Single element lies on the RIGHT.
        - Else
              -> Single element lies on the LEFT (including mid).

    If mid is ODD:
        - If arr[mid] == arr[mid - 1]
              -> Single element lies on the RIGHT.
        - Else
              -> Single element lies on the LEFT (including mid).

    We keep shrinking the search space until low == high.
    */

    int n = arr.size();

    // Edge Cases
    if (n == 1)
        return arr[0];

    if (arr[0] != arr[1])
        return arr[0];

    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Found the single element
        if (arr[mid] != arr[mid - 1] &&
            arr[mid] != arr[mid + 1])
            return arr[mid];

        // Check parity
        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
            (mid % 2 == 1 && arr[mid] == arr[mid - 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5, 5};

    cout << "Single Element: "
         << singleNonDuplicate(arr) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

arr = [1, 1, 2, 2, 3, 4, 4, 5, 5]

Indices:
         0  1  2  3  4  5  6  7  8

Before single element:
(0,1), (2,3)
Even -> First
Odd  -> Second

After single element:
(5,6), (7,8)
Odd  -> First
Even -> Second

The parity flips exactly after the single element.

--------------------------------------

Example:

arr = [1,1,2,3,3,4,4]

mid points to 3.

Since parity pattern is broken,
the single element lies on the LEFT.

Answer = 2.

--------------------------------------

Time Complexity : O(log n)

Space Complexity : O(1)

Memory Trick:

1. Before single:
      Even -> First occurrence
      Odd  -> Second occurrence

2. After single:
      Odd  -> First occurrence
      Even -> Second occurrence

3. If parity is "correct",
      move RIGHT.

4. If parity is "broken",
      move LEFT.

5. When low == high,
      that's the single element.
*/