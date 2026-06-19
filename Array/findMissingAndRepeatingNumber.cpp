#include <iostream>
#include <vector>
using namespace std;

// Function to find the repeating and missing number
pair<int, int> findMissingAndRepeating(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // Let:
    // x = repeating number
    // y = missing number
    //
    // We know:
    //
    // x - y = (Actual Sum - Expected Sum)
    //
    // and
    //
    // x² - y² = (Actual Square Sum - Expected Square Sum)
    //
    // Since:
    //
    // x² - y² = (x - y)(x + y)
    //
    // We can find:
    //
    // x + y
    //
    // Then solve:
    //
    // x = ((x+y) + (x-y)) / 2
    // y = (x+y) - x

    long long n = arr.size();

    // Expected sum of numbers from 1 to n
    long long expectedSum = (n * (n + 1)) / 2;

    // Expected sum of squares
    long long expectedSquareSum =
        (n * (n + 1) * (2 * n + 1)) / 6;

    long long actualSum = 0;
    long long actualSquareSum = 0;

    // Calculate actual sums
    for (int num : arr)
    {
        actualSum += num;
        actualSquareSum += 1LL * num * num;
    }

    // x - y
    long long val1 = actualSum - expectedSum;

    // x² - y²
    long long val2 = actualSquareSum - expectedSquareSum;

    // x + y
    val2 = val2 / val1;

    // x = repeating
    long long repeating = (val1 + val2) / 2;

    // y = missing
    long long missing = val2 - repeating;

    return {repeating, missing};
}

int main()
{
    vector<int> arr = {4, 3, 6, 2, 1, 1};

    // Only function call
    pair<int, int> ans = findMissingAndRepeating(arr);

    cout << "Repeating Number: " << ans.first << endl;
    cout << "Missing Number  : " << ans.second << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Suppose:

x = repeating
y = missing

--------------------------------------

Equation 1:

x - y

=

Actual Sum

-

Expected Sum

--------------------------------------

Equation 2:

x² - y²

=

Actual Square Sum

-

Expected Square Sum

But,

x² - y²

=

(x - y)(x + y)

So,

x + y

=

(x² - y²) / (x - y)

--------------------------------------

Now solve:

x = ((x+y) + (x-y)) / 2

y = (x+y) - x

--------------------------------------

Example:

Array:

[4,3,6,2,1,1]

Repeating = 1

Missing = 5

--------------------------------------

Time Complexity : O(n)

Space Complexity : O(1)

Memory Trick:

Find:

x - y

and

x + y

Then solve the two equations.
*/