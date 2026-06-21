#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to count how many gas stations are needed
int numberOfGasStationsRequired(vector<int> &stations, double maxDist)
{
    /*
    For every adjacent pair of stations:

        gap = stations[i] - stations[i - 1]

    Number of new stations needed:

        stationsNeeded = floor(gap / maxDist)

    But if gap is exactly divisible by maxDist,
    one station is counted extra, so subtract 1.
    */

    int count = 0;

    for (int i = 1; i < stations.size(); i++)
    {
        double gap = stations[i] - stations[i - 1];

        int stationsNeeded = (int)(gap / maxDist);

        if (gap == stationsNeeded * maxDist)
            stationsNeeded--;

        count += stationsNeeded;
    }

    return count;
}

// Function to minimize the maximum distance
double minimizeMaxDistance(vector<int> &stations, int k)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We have to place k extra gas stations such that
    the maximum distance between adjacent stations
    becomes minimum.

    Observation:
    - If a maximum distance D is achievable,
      then any value > D is also achievable.
    - If D is NOT achievable,
      then any value < D is also NOT achievable.

    This monotonic property allows Binary Search
    on the answer.

    Search Space:
    low  = 0
    high = maximum existing gap

    Check:
    For every gap,
    compute how many stations are required so that
    each sub-gap <= maxDist.

    If total required stations <= k:
        -> Possible
        -> Try a smaller distance.

    Else:
        -> Need a larger distance.
    */

    double low = 0.0;
    double high = 0.0;

    for (int i = 1; i < stations.size(); i++)
    {
        high = max(high, (double)(stations[i] - stations[i - 1]));
    }

    double diff = 1e-6;

    while ((high - low) > diff)
    {
        double mid = (low + high) / 2.0;

        int required = numberOfGasStationsRequired(stations, mid);

        if (required > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return high;
}

int main()
{
    vector<int> stations = {1, 2, 3, 4, 5};
    int k = 4;

    cout << "Minimum Possible Maximum Distance = "
         << minimizeMaxDistance(stations, k) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

stations = [1, 2, 3, 4, 5]
k = 4

Current maximum gap = 1

Suppose another example:

stations = [1, 10]
k = 2

Gap = 9

Place 2 stations:

1 ---- 4 ---- 7 ---- 10

Maximum distance = 3

This is optimal.

--------------------------------------

Binary Search:

Try maxDist = 2

Gap = 9

Need:
9 / 2 = 4 intervals

Need 4 stations (> k)

Not possible.

Increase maxDist.

--------------------------------------

Try maxDist = 3

Need only 2 stations.

Possible.

Try even smaller.

--------------------------------------

Time Complexity:
O(n * log(MaxGap / 1e-6))

where:
n = number of existing stations

Space Complexity:
O(1)

Memory Trick:

1. Binary Search on the ANSWER
   (maximum allowed distance).

2. For every gap:
      stationsNeeded = floor(gap / maxDist)

3. If gap is exactly divisible:
      subtract one.

4. Sum all required stations.

5. If required <= k:
      move LEFT.
   Else:
      move RIGHT.

Binary Search on doubles stops when:

    high - low <= 1e-6
*/