#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to calculate days required for a given ship capacity
int daysRequired(vector<int> &weights, int capacity)
{
    /*
    Traverse the weights one by one.

    If adding the current package exceeds the ship capacity,
    start a new day and load the package there.

    Count how many days are needed for this capacity.
    */

    int days = 1;
    int currentLoad = 0;

    for (int weight : weights)
    {
        if (currentLoad + weight <= capacity)
        {
            currentLoad += weight;
        }
        else
        {
            days++;
            currentLoad = weight;
        }
    }

    return days;
}

// Function to find the least ship capacity
int shipWithinDays(vector<int> &weights, int days)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We need the MINIMUM ship capacity such that
    all packages can be shipped within 'days'.

    Observation:
    - If capacity is increased,
      fewer days are needed.
    - If capacity is decreased,
      more days are needed.

    This monotonic behaviour allows Binary Search
    on the answer.

    Search Space:
    - Minimum capacity = maximum package weight
      (otherwise that package can't be shipped).
    - Maximum capacity = sum of all weights
      (ship everything in one day).

    Binary Search:
    - Compute days needed for current capacity.
    - If required days <= given days:
          -> Capacity works.
          -> Try a smaller capacity.
    - Else:
          -> Capacity too small.
          -> Increase it.
    */

    int low = *max_element(weights.begin(), weights.end());
    int high = 0;

    for (int weight : weights)
        high += weight;

    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int requiredDays = daysRequired(weights, mid);

        if (requiredDays <= days)
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
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    cout << "Least Ship Capacity = "
         << shipWithinDays(weights, days) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

weights = [1,2,3,4,5,6,7,8,9,10]
days = 5

Try capacity = 15

Day 1 -> 1 + 2 + 3 + 4 + 5 = 15
Day 2 -> 6 + 7 = 13
Day 3 -> 8
Day 4 -> 9
Day 5 -> 10

Exactly 5 days.
This capacity works.

Can we reduce it?
Binary Search tries smaller capacities.

Final Answer = 15.

--------------------------------------

Another Example:

weights = [3,2,2,4,1,4]
days = 3

Capacity = 6

Day 1 -> 3 + 2 = 5
Day 2 -> 2 + 4 = 6
Day 3 -> 1 + 4 = 5

Answer = 6

--------------------------------------

Time Complexity:
O(n * log(sum(weights)))

where:
n = number of packages

Space Complexity:
O(1)

Memory Trick:

1. Binary Search on the SHIP CAPACITY.
2. low = maximum weight.
3. high = sum of all weights.
4. Simulate shipping:
      If current load exceeds capacity,
      start a new day.
5. If required days <= given days:
      save answer and move LEFT.
6. Else:
      move RIGHT.
*/
