#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum product subarray
int maxProduct(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // Negative numbers can flip the sign of the product.
    //
    // So, we traverse from BOTH directions:
    //
    // prefix -> product from left to right
    // suffix -> product from right to left
    //
    // If either becomes 0,
    // reset it to 1.
    //
    // The answer is the maximum among all
    // prefix and suffix products.

    int n = arr.size();

    long long prefix = 1;
    long long suffix = 1;

    long long ans = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        // Reset after zero
        if (prefix == 0)
            prefix = 1;

        if (suffix == 0)
            suffix = 1;

        // Compute prefix product
        prefix *= arr[i];

        // Compute suffix product
        suffix *= arr[n - i - 1];

        // Update answer
        ans = max(ans, max(prefix, suffix));
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 3, -2, 4};

    // Only function call
    cout << "Maximum Product: "
         << maxProduct(arr);

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Problem:

Find the contiguous subarray
having maximum PRODUCT.

--------------------------------------

Why not Kadane?

Because multiplication behaves
differently with negatives.

Example:

[-2, 3, -4]

Whole product:

(-2) * 3 * (-4)

= 24

--------------------------------------

Idea:

Traverse from LEFT
and RIGHT simultaneously.

Maintain:

prefix product

suffix product

If any becomes 0,
reset to 1.

Take maximum of:

prefix
suffix

--------------------------------------

Example:

arr =

[2, 3, -2, 4]

Prefix:

2
6
-12
-48

Suffix:

4
-8
-24
-48

Maximum = 6

--------------------------------------

Example:

[-1, -2, -3]

Prefix:

-1
2
-6

Suffix:

-3
6
-6

Answer = 6

--------------------------------------

Time Complexity : O(n)

Space Complexity : O(1)

Memory Trick:

Kadane for SUM ❌

For PRODUCT:

Go from BOTH SIDES.

Reset on ZERO.

Take max(prefix, suffix).
*/