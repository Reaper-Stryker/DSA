#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the median of two sorted arrays
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We partition both arrays into LEFT and RIGHT halves.

    Goal:
    - Number of elements on the LEFT =
      Number of elements on the RIGHT
      (or LEFT has one extra for odd length).

    Correct Partition Condition:

        max(left1, left2) <= min(right1, right2)

    Visualization:

        nums1 : [ 1  3 | 8  9 ]
                     ^
        nums2 : [ 7 11 18 | 19 21 ]
                          ^

        Left Part :
        [1,3,7,11,18]

        Right Part:
        [8,9,19,21]

    If
        leftMax <= rightMin

    then partition is valid.

    Median:
    - Odd length:
          max(left1, left2)

    - Even length:
          (max(left1,left2) + min(right1,right2))/2

    Binary Search is performed ONLY on
    the smaller array.
    */

    int n1 = nums1.size();
    int n2 = nums2.size();

    // Always binary search on the smaller array
    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);

    int low = 0;
    int high = n1;

    while (low <= high)
    {
        int cut1 = low + (high - low) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            // Correct partition found

            if ((n1 + n2) % 2 == 0)
            {
                return (max(left1, left2) +
                        min(right1, right2)) /
                       2.0;
            }
            else
            {
                return max(left1, left2);
            }
        }
        else if (left1 > right2)
        {
            // Move partition left
            high = cut1 - 1;
        }
        else
        {
            // Move partition right
            low = cut1 + 1;
        }
    }

    return 0.0;
}

int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << "Median = "
         << findMedianSortedArrays(nums1, nums2)
         << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example 1:

nums1 = [1, 3]
nums2 = [2]

Merged:
[1, 2, 3]

Median = 2

--------------------------------------

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

Merged:
[1, 2, 3, 4]

Median =
(2 + 3) / 2
= 2.5

--------------------------------------

Partition Example:

nums1 = [1, 3]
nums2 = [2]

Partition:

nums1 : [1 | 3]
nums2 : [2 | ]

Left :
1 2

Right :
3

Left size = Right size + 1

Median = max(left)
       = 2

--------------------------------------

Time Complexity:
O(log(min(n1, n2)))

Space Complexity:
O(1)

Memory Trick:

1. Always Binary Search on the SMALLER array.

2. Maintain:

   max(left1, left2)
          <=
   min(right1, right2)

3. If left1 > right2:
      move LEFT.

4. Else:
      move RIGHT.

5. Odd length:
      answer = max(left).

6. Even length:
      answer =
      (max(left) + min(right)) / 2.

This is one of Striver's most important
Binary Search on Partition problems.
*/