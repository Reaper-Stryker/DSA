#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the k-th element in the merged sorted array
int kthElement(vector<int> &arr1, vector<int> &arr2, int k)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    This problem is an extension of
    "Median of Two Sorted Arrays".

    Instead of dividing the arrays into equal halves,
    we divide them such that:

        Number of elements on LEFT = k

    Then the k-th smallest element is simply:

        max(left1, left2)

    Partition Condition:

        left1 <= right2
        left2 <= right1

    If this condition is satisfied,
    we have found the correct partition.

    Otherwise:
    - If left1 > right2:
          Move partition in arr1 to the LEFT.
    - Else:
          Move partition in arr1 to the RIGHT.

    Always perform Binary Search on
    the smaller array.
    */

    int n1 = arr1.size();
    int n2 = arr2.size();

    // Always binary search on the smaller array
    if (n1 > n2)
        return kthElement(arr2, arr1, k);

    int low = max(0, k - n2);
    int high = min(k, n1);

    while (low <= high)
    {
        int cut1 = low + (high - low) / 2;
        int cut2 = k - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];

        int right1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : arr2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            return max(left1, left2);
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};

    int k = 5;

    cout << "K-th Element = "
         << kthElement(arr1, arr2, k)
         << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

arr1 = [2, 3, 6, 7, 9]
arr2 = [1, 4, 8, 10]

Merged:
[1, 2, 3, 4, 6, 7, 8, 9, 10]

k = 5

Answer = 6

--------------------------------------

Partition Idea:

Suppose

cut1 = 3
cut2 = 2

arr1:
[2 3 6 | 7 9]

arr2:
[1 4 | 8 10]

Left side:
2 3 6 1 4

Right side:
7 9 8 10

Total elements on LEFT = k = 5

Check:

left1 = 6
left2 = 4

right1 = 7
right2 = 8

Since

6 <= 8
4 <= 7

Partition is valid.

Answer = max(6, 4) = 6.

--------------------------------------

Time Complexity:
O(log(min(n1, n2)))

Space Complexity:
O(1)

Memory Trick:

1. Binary Search on the SMALLER array.

2. Keep exactly k elements
   on the LEFT side.

3. Check:

      left1 <= right2
      left2 <= right1

4. If valid:
      answer = max(left1, left2)

5. If left1 > right2:
      move LEFT.

6. Else:
      move RIGHT.

Think of this as the "Median of Two Sorted Arrays"
problem with the only change being that the LEFT
partition contains exactly k elements instead of
half the total elements.
*/