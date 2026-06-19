#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // -------------------- INTUITION --------------------
    //
    // Step 1:
    // Sort intervals based on starting time.
    //
    // Step 2:
    // If current interval overlaps with the last
    // interval in the answer, merge them.
    //
    // Otherwise, start a new interval.

    vector<vector<int>> ans;

    // Sort according to starting time
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++)
    {
        // If answer is empty OR
        // current interval doesn't overlap,
        // simply add it.
        if (ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            // Overlapping interval found.
            // Extend the ending time.
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    // Only function call
    vector<vector<int>> ans = mergeIntervals(intervals);

    // Print merged intervals
    for (auto &interval : ans)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Goal:
Merge all overlapping intervals.

--------------------------------------

Example:

Input:

[1,3]
[2,6]
[8,10]
[15,18]

After sorting:

[1,3]
[2,6]
[8,10]
[15,18]

--------------------------------------

Compare with last interval
stored in answer.

Current:
[2,6]

Last:
[1,3]

Since:

2 <= 3

They overlap.

Merge:

[1, max(3,6)]

↓

[1,6]

--------------------------------------

If:

Current Start >
Last End

No overlap.

Push current interval.

--------------------------------------

Final Answer:

[1,6]
[8,10]
[15,18]

--------------------------------------

Time Complexity :

Sorting : O(n log n)

Traversal : O(n)

Overall : O(n log n)

Space Complexity :

O(n)
(for storing answer)

Memory Trick:

Sort first.

Compare with LAST merged interval.

If overlap:
    extend end.

Else:
    push new interval.
*/