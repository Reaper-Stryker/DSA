#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to calculate total hours needed
long long calculateHours(vector<int> &piles, int speed)
{
    /*
    For a given eating speed 'speed',
    calculate how many hours Koko will take.

    Formula:
        hours = ceil(pile / speed)

    To avoid using ceil():
        ceil(a / b) = (a + b - 1) / b
    */

    long long totalHours = 0;

    for (int bananas : piles)
    {
        totalHours += (bananas + speed - 1) / speed;
    }

    return totalHours;
}

// Function to find the minimum eating speed
int minEatingSpeed(vector<int> &piles, int h)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We need the MINIMUM eating speed k such that
    Koko can finish all bananas within h hours.

    Observation:
    - If Koko eats faster, total hours decrease.
    - If Koko eats slower, total hours increase.

    This is a monotonic function:
        speed ↑  => hours ↓

    Hence, Binary Search can be applied on the answer.

    Search Space:
    - Minimum possible speed = 1 banana/hour.
    - Maximum possible speed = max(piles)
      (eating the largest pile in one hour).

    Binary Search:
    - Compute hours needed for current speed.
    - If hours <= h:
          -> This speed works.
          -> Try to minimize it by searching LEFT.
    - Else:
          -> Speed is too slow.
          -> Search RIGHT.
    */

    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long hoursNeeded = calculateHours(piles, mid);

        if (hoursNeeded <= h)
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
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << "Minimum Eating Speed: "
         << minEatingSpeed(piles, h) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

piles = [3, 6, 7, 11]
h = 8

Try speed = 4

Hours needed:
3  -> 1 hour
6  -> 2 hours
7  -> 2 hours
11 -> 3 hours

Total = 8 hours

Works!

Can we do better?
Try smaller speeds using Binary Search.

Eventually,
Minimum valid speed = 4.

--------------------------------------

Another Example:

piles = [30, 11, 23, 4, 20]
h = 5

Speed = 30

Hours:
30 -> 1
11 -> 1
23 -> 1
4  -> 1
20 -> 1

Total = 5

Answer = 30

--------------------------------------

Time Complexity:
O(n * log(maxPile))

where:
- n = number of piles
- log(maxPile) = Binary Search iterations

Space Complexity:
O(1)

Memory Trick:

1. Binary Search on the ANSWER (speed).
2. Search range:
      low = 1
      high = maximum pile
3. If hours <= h:
      save answer and move LEFT
      (try a smaller speed).
4. If hours > h:
      move RIGHT
      (need to eat faster).
5. Use:
      ceil(a / b) = (a + b - 1) / b
   to avoid floating-point operations.
*/