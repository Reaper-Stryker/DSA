#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to check if we can place all cows
bool canPlaceCows(vector<int> &stalls, int cows, int minDistance)
{
    /*
    Place the first cow at the first stall.

    Then greedily place the next cow in the
    leftmost stall whose distance from the
    previously placed cow is at least minDistance.

    If we can place all cows, return true.
    */

    int placedCows = 1;
    int lastPlaced = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPlaced >= minDistance)
        {
            placedCows++;
            lastPlaced = stalls[i];

            if (placedCows == cows)
                return true;
        }
    }

    return false;
}

// Function to find the largest minimum distance
int aggressiveCows(vector<int> &stalls, int cows)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We need to maximize the minimum distance
    between any two cows.

    Observation:
    - If we can place all cows with distance = d,
      then we can also place them with any distance < d.
    - If we cannot place them with distance = d,
      then we also cannot place them with any distance > d.

    This is a monotonic property.

    Hence, Binary Search on the ANSWER.

    Search Space:
    - Minimum distance = 1
    - Maximum distance = last stall - first stall

    Binary Search:
    - If we can place all cows with 'mid' distance,
      save it and try a larger distance.
    - Otherwise, reduce the distance.
    */

    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();

    int ans = 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, cows, mid))
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
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;

    cout << "Largest Minimum Distance = "
         << aggressiveCows(stalls, cows) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

stalls = [1, 2, 4, 8, 9]
cows = 3

Sorted stalls:
[1, 2, 4, 8, 9]

Try distance = 3

Place first cow at 1.

Next possible:
4 (distance = 3)

Next possible:
8 (distance = 4)

Placed all 3 cows.

Distance 3 is possible.
Try a larger distance.

--------------------------------------

Try distance = 4

Place at 1.

Next:
8 (distance = 7)

Need third cow:
9 - 8 = 1 < 4

Cannot place.

So answer = 3.

--------------------------------------

Time Complexity:
O(n * log(maxDistance))

where:
n = number of stalls

Space Complexity:
O(1)

Memory Trick:

1. Sort the stalls first.
2. Binary Search on the MINIMUM DISTANCE.
3. Greedily place cows from left to right.
4. If placement is possible:
      save answer and move RIGHT
      (try a bigger minimum distance).
5. Else:
      move LEFT.
*/