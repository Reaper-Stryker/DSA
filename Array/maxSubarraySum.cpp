#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum subarray sum
int maxSubArraySum(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // Keep extending the current subarray as long as
    // it contributes positively to the sum.
    //
    // If the current sum becomes negative,
    // discard it and start a new subarray.
    //
    // Why?
    // Because adding a negative sum to future elements
    // will only decrease the total sum.

    int maxi = INT_MIN; // Stores the maximum sum found so far
    int sum = 0;        // Stores the current subarray sum

    for (int i = 0; i < arr.size(); i++)
    {
        // Extend the current subarray
        sum += arr[i];

        // Update maximum sum if needed
        maxi = max(maxi, sum);

        // If current sum becomes negative,
        // start a new subarray from the next element.
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxi;
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Only function call
    cout << "Maximum Subarray Sum: " << maxSubArraySum(arr);

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Goal:
Find the contiguous subarray having
the maximum possible sum.

Core Idea:

If the running sum becomes NEGATIVE,
it will only reduce the sum of any
future subarray.

So,
if (sum < 0)
    sum = 0;

Example:

arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Running Sum:

-2 -> reset to 0
 1 -> max = 1
-2
 4 -> max = 4
 3
 5
 6 -> max = 6
 1
 5

Answer = 6

Maximum subarray:
[4, -1, 2, 1]

Time Complexity : O(n)
Space Complexity: O(1)

Memory Trick:

Keep adding elements.

If running sum < 0
    -> Throw it away (sum = 0)

Keep track of the maximum sum seen so far.
*/