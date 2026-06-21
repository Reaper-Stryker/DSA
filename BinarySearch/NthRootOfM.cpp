#include <iostream>
using namespace std;

// Helper function to compare mid^n with m
int power(int mid, int n, int m)
{
    /*
    Returns:
    1  -> if mid^n == m
    0  -> if mid^n < m
    2  -> if mid^n > m

    We multiply one by one to avoid overflow.
    If the product exceeds m at any point,
    we immediately return 2.
    */

    long long ans = 1;

    for (int i = 1; i <= n; i++)
    {
        ans *= mid;

        if (ans > m)
            return 2;
    }

    if (ans == m)
        return 1;

    return 0;
}

// Function to find the nth root of m
int findNthRoot(int n, int m)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We need to find an integer x such that:

            x^n = m

    Example:
        n = 3, m = 27

        3^3 = 27
        Answer = 3

    Observation:
    - As x increases, x^n also increases.
    - This monotonic property allows Binary Search.

    Binary Search:
    - If mid^n == m:
          Found the answer.
    - If mid^n < m:
          Search on the RIGHT.
    - If mid^n > m:
          Search on the LEFT.

    If no integer satisfies x^n = m,
    return -1.
    */

    int low = 1;
    int high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int check = power(mid, n, m);

        if (check == 1)
            return mid;

        else if (check == 0)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n = 3;
    int m = 27;

    cout << "Nth Root = " << findNthRoot(n, m) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example 1:

n = 3
m = 27

Check:
1^3 = 1
2^3 = 8
3^3 = 27

Answer = 3

--------------------------------------

Example 2:

n = 2
m = 16

4^2 = 16

Answer = 4

--------------------------------------

Example 3:

n = 3
m = 20

2^3 = 8
3^3 = 27

No integer cube root exists.

Answer = -1

--------------------------------------

Time Complexity :
O(log m * n)

(Binary Search performs O(log m) iterations,
and each iteration computes mid^n in O(n).)

Space Complexity :
O(1)

Memory Trick:

1. x^n increases as x increases.
2. Apply Binary Search on x.
3. If mid^n == m -> return mid.
4. If mid^n < m -> move RIGHT.
5. If mid^n > m -> move LEFT.
6. Compute powers carefully to avoid overflow.
*/