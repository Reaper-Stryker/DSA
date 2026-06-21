#include <iostream>
using namespace std;

// Function to find the floor value of sqrt(n)
int findSquareRoot(int n)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We need to find the largest integer x such that:

            x * x <= n

    Observation:
    - As x increases, x*x also increases.
    - This monotonic property allows us to use Binary Search.

    Binary Search Idea:
    -------------------
    If mid * mid <= n:
        -> mid can be a possible answer.
        -> But there might be a larger valid value.
        -> Search on the RIGHT.

    Else:
        -> mid * mid > n.
        -> mid is too large.
        -> Search on the LEFT.

    We keep track of the latest valid answer.
    */

    int low = 1;
    int high = n;
    int ans = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n = 28;

    cout << "Floor of Square Root = "
         << findSquareRoot(n) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example 1:

n = 28

Possible square roots:

1² = 1
2² = 4
3² = 9
4² = 16
5² = 25
6² = 36 (> 28)

Largest value whose square <= 28 is 5.

Answer = 5

--------------------------------------

Example 2:

n = 36

6² = 36

Answer = 6

--------------------------------------

Example 3:

n = 1

1² = 1

Answer = 1

--------------------------------------

Time Complexity : O(log n)

Space Complexity : O(1)

Memory Trick:

1. Find the LARGEST number whose square is <= n.
2. If mid² <= n:
      -> Store mid.
      -> Move RIGHT.
3. Else:
      -> Move LEFT.
4. Always use long long for mid * mid
   to avoid integer overflow.
*/