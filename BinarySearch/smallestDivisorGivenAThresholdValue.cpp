#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to calculate the sum after dividing by 'divisor'
int calculateSum(vector<int> &nums, int divisor)
{
    /*
    For every element:
        contribution = ceil(nums[i] / divisor)

    To avoid using ceil():
        ceil(a / b) = (a + b - 1) / b
    */

    int sum = 0;

    for (int num : nums)
    {
        sum += (num + divisor - 1) / divisor;
    }

    return sum;
}

// Function to find the smallest divisor
int smallestDivisor(vector<int> &nums, int threshold)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We need the SMALLEST divisor such that:

        Σ ceil(nums[i] / divisor) <= threshold

    Observation:
    - As divisor INCREASES,
      the overall sum DECREASES.
    - As divisor DECREASES,
      the overall sum INCREASES.

    Hence, the answer space is MONOTONIC,
    making Binary Search applicable.

    Search Space:
    - Minimum divisor = 1
    - Maximum divisor = max(nums)

    Binary Search:
    - Compute the sum using current divisor.
    - If sum <= threshold:
          -> This divisor works.
          -> Try to find a smaller divisor.
    - Else:
          -> Divisor is too small.
          -> Increase it.
    */

    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int currentSum = calculateSum(nums, mid);

        if (currentSum <= threshold)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << "Smallest Divisor = "
         << smallestDivisor(nums, threshold) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

nums = [1, 2, 5, 9]
threshold = 6

Try divisor = 5

ceil(1/5) = 1
ceil(2/5) = 1
ceil(5/5) = 1
ceil(9/5) = 2

Total = 1 + 1 + 1 + 2 = 5 <= 6

This divisor works.
Try to find an even smaller divisor.

--------------------------------------

Try divisor = 3

ceil(1/3) = 1
ceil(2/3) = 1
ceil(5/3) = 2
ceil(9/3) = 3

Total = 7 > 6

Too large a sum.
Increase the divisor.

--------------------------------------

Final Answer = 5

--------------------------------------

Time Complexity:
O(n * log(max(nums)))

where:
n = number of elements

Space Complexity:
O(1)

Memory Trick:

1. Binary Search on the DIVISOR.
2. Compute:
      sum += ceil(nums[i] / divisor)
3. If sum <= threshold:
      save answer and move LEFT
      (try a smaller divisor).
4. Else:
      move RIGHT
      (need a larger divisor).
5. Use:
      ceil(a / b) = (a + b - 1) / b
   to avoid floating-point operations.
*/