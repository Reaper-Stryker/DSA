#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of the longest subarray with sum = k
int longestSubarrayWithSumK(vector<int> &arr, int k)
{
    // -------------------- INTUITION --------------------
    //
    // Use Sliding Window (Two Pointers).
    //
    // left  -> start of window
    // right -> end of window
    //
    // Expand the window by moving right.
    // If sum becomes greater than k,
    // shrink the window from the left.
    //
    // Whenever sum == k,
    // update the maximum length.

    int left = 0;
    int right = 0;

    long long sum = arr[0];
    int maxLen = 0;

    while (right < arr.size())
    {
        // Shrink the window until sum <= k
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        // Found a valid subarray
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        // Expand the window
        right++;

        if (right < arr.size())
        {
            sum += arr[right];
        }
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 9};
    int k = 10;

    // Only function call
    cout << "Longest Length: "
         << longestSubarrayWithSumK(arr, k);

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Works ONLY for positive numbers.

Use Sliding Window:

left  -> window start
right -> window end

Rules:

1. Expand by moving right.
2. If sum > k:
      keep removing arr[left]
      and move left forward.
3. If sum == k:
      update answer.

Example:

arr = [2,3,5,1,9]
k = 10

Window:
[2,3,5] -> sum = 10
Length = 3

Answer = 3

Time Complexity : O(n)
Space Complexity: O(1)

Memory Trick:
Grow the window.
If sum becomes too large,
shrink from the left.
*/