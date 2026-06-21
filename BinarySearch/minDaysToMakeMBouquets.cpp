#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to check if it's possible to make m bouquets
bool canMakeBouquets(vector<int> &bloomDay, int day, int m, int k)
{
    /*
    Count consecutive flowers that have bloomed
    on or before 'day'.

    Whenever consecutive count reaches k,
    we can make one bouquet and reset the count.
    */

    int bouquets = 0;
    int flowers = 0;

    for (int bloom : bloomDay)
    {
        if (bloom <= day)
        {
            flowers++;

            if (flowers == k)
            {
                bouquets++;
                flowers = 0;
            }
        }
        else
        {
            flowers = 0;
        }
    }

    return bouquets >= m;
}

// Function to find the minimum day
int minDays(vector<int> &bloomDay, int m, int k)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We need the MINIMUM day on which we can
    make exactly m bouquets.

    Each bouquet requires k ADJACENT flowers.

    Observation:
    - If we can make m bouquets on day X,
      then we can also make them on any day > X.
    - If we cannot make them on day X,
      then we also cannot make them on any day < X.

    This is a monotonic property.

    Hence, Binary Search on the ANSWER (day).

    Search Space:
    - Minimum possible day = minimum bloom day.
    - Maximum possible day = maximum bloom day.

    Feasibility Check:
    - Traverse the array.
    - Count consecutive bloomed flowers.
    - Every k consecutive flowers form one bouquet.
    - Reset the count after forming a bouquet.

    IMPORTANT:
    If m * k > total flowers,
    it's impossible to make m bouquets.
    Return -1.
    */

    long long required = 1LL * m * k;

    if (required > bloomDay.size())
        return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canMakeBouquets(bloomDay, mid, m, k))
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
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    cout << "Minimum Days = "
         << minDays(bloomDay, m, k) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example 1:

bloomDay = [1,10,3,10,2]
m = 3
k = 1

Day = 3

Bloomed flowers:
[1, X, 3, X, 2]

We have flowers at indices:
0, 2, 4

Can make 3 bouquets.

Answer = 3.

--------------------------------------

Example 2:

bloomDay = [7,7,7,7,12,7,7]
m = 2
k = 3

Day = 7

Bloomed:
[7,7,7,7,X,7,7]

Consecutive groups:
First group -> 4 flowers -> 1 bouquet
Second group -> 2 flowers -> 0 bouquet

Only 1 bouquet.

Need 2 bouquets.

Increase the day.

--------------------------------------

Time Complexity:
O(n * log(maxBloomDay))

where
n = number of flowers

Space Complexity:
O(1)

Memory Trick:

1. Binary Search on DAYS.
2. Check if current day can produce m bouquets.
3. Count CONSECUTIVE bloomed flowers.
4. Every k consecutive flowers => 1 bouquet.
5. If possible:
      save answer and move LEFT.
   Else:
      move RIGHT.

IMPORTANT CHECK:

if (1LL * m * k > bloomDay.size())
    return -1;

This handles impossible cases immediately.
*/