#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to check if allocation is possible
int countPainters(vector<int> &boards, int maxWork)
{
    /*
    Count the minimum number of painters needed
    if one painter can paint at most 'maxWork' units.

    We assign contiguous boards only.
    */

    int painters = 1;
    int workDone = 0;

    for (int board : boards)
    {
        if (workDone + board <= maxWork)
        {
            workDone += board;
        }
        else
        {
            painters++;
            workDone = board;
        }
    }

    return painters;
}

// Function to find the minimum possible maximum work
int paintersPartition(vector<int> &boards, int k)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We need to divide the boards among k painters
    such that:

    1. Every board is assigned.
    2. Boards assigned to a painter are contiguous.
    3. Minimize the maximum work assigned
       to any painter.

    Observation:
    - If a workload X is possible,
      then any workload > X is also possible.
    - If X is not possible,
      then any workload < X is also impossible.

    Hence Binary Search on the answer.

    Search Space:
    low  = largest board
    high = sum of all boards

    Check:
    Count how many painters are needed
    for the current workload.

    If painters needed <= k:
        -> Possible
        -> Try a smaller answer.

    Else:
        -> Need more workload.
        -> Increase answer.
    */

    if (k > boards.size())
        return -1;

    int low = *max_element(boards.begin(), boards.end());

    int high = 0;
    for (int board : boards)
        high += board;

    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int paintersNeeded = countPainters(boards, mid);

        if (paintersNeeded <= k)
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
    vector<int> boards = {10, 20, 30, 40};
    int painters = 2;

    cout << "Minimum Maximum Work = "
         << paintersPartition(boards, painters) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

boards = [10, 20, 30, 40]
painters = 2

Try maxWork = 50

Painter 1:
10 + 20 = 30

30 + 30 > 50

Painter 2:
30

30 + 40 > 50

Painter 3:
40

Need 3 painters.
Not possible.

Increase workload.

--------------------------------------

Try maxWork = 60

Painter 1:
10 + 20 + 30 = 60

Painter 2:
40

Only 2 painters needed.

Possible.

Try smaller answer.

--------------------------------------

Eventually,
Answer = 60.

--------------------------------------

Time Complexity:
O(n * log(sum(boards)))

Space Complexity:
O(1)

Memory Trick:

1. Binary Search on the ANSWER.
2. low = maximum board.
3. high = sum of boards.
4. Greedily assign contiguous boards.
5. If paintersNeeded <= k:
      save answer and move LEFT.
6. Else:
      move RIGHT.
*/