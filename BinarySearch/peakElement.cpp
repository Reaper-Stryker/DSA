#include <iostream>
#include <vector>
using namespace std;

// Function to find a peak element's index
int findPeakElement(vector<int> &arr)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    A peak element is an element that is strictly greater
    than its immediate neighbours.

    Key Observation:
    - If arr[mid] > arr[mid + 1],
      then we are on the DECREASING slope.
      A peak exists on the LEFT (including mid).

    - If arr[mid] < arr[mid + 1],
      then we are on the INCREASING slope.
      A peak exists on the RIGHT.

    Why?
    ----
    Imagine the array as a mountain.

          /\
         /  \
        /    \

    If you're climbing up, keep moving right.
    If you're going down, you've already crossed
    a peak, so move left.

    Eventually, low == high, which points to a peak.
    */

    int low = 0;
    int high = arr.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            // Increasing slope
            low = mid + 1;
        }
        else
        {
            // Decreasing slope or at peak
            high = mid;
        }
    }

    return low;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 5, 6, 4};

    int peakIndex = findPeakElement(arr);

    cout << "Peak Element Index: " << peakIndex << endl;
    cout << "Peak Element Value: " << arr[peakIndex] << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example 1:

arr = [1, 2, 3, 1]

mid = 1 (value = 2)

2 < 3
Increasing slope
Move RIGHT.

Eventually:
low = high = 2

Peak = 3

--------------------------------------

Example 2:

arr = [1, 2, 1, 3, 5, 6, 4]

mid = 3 (value = 3)

3 < 5
Move RIGHT.

Later,
mid = 5 (value = 6)

6 > 4
Move LEFT.

Finally,
low = high = 5

Peak = 6

--------------------------------------

Time Complexity : O(log n)

Space Complexity : O(1)

Memory Trick:

Think of climbing a mountain.

1. If arr[mid] < arr[mid + 1]
      -> You're climbing UP.
      -> Move RIGHT.

2. Else
      -> You're going DOWN or standing on the peak.
      -> Move LEFT (keep mid).

3. When low == high,
      that's a peak element.
*/