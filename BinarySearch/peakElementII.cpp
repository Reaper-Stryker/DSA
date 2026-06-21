#include <iostream>
#include <vector>
using namespace std;

// Function to find a peak element in a 2D matrix
pair<int, int> findPeakGrid(vector<vector<int>> &mat)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    A peak element is one that is strictly greater
    than its LEFT, RIGHT, TOP and BOTTOM neighbours.

    Brute Force:
    Check every cell -> O(n * m)

    Optimized (Binary Search on Columns):

    Step 1:
    Pick the middle column.

    Step 2:
    Find the row having the maximum element
    in that column.

    Step 3:
    Compare it with its LEFT and RIGHT neighbours.

    - If current element is greater than both,
      we've found a peak.

    - If left neighbour is greater,
      then a peak must exist on the LEFT side.

    - Otherwise,
      a peak must exist on the RIGHT side.

    We don't compare TOP/BOTTOM because we already
    selected the maximum element in that column.
    */

    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = m - 1;

    while (low <= high)
    {
        int midCol = low + (high - low) / 2;

        // Find row index having maximum element
        // in the middle column
        int maxRow = 0;

        for (int i = 1; i < n; i++)
        {
            if (mat[i][midCol] > mat[maxRow][midCol])
                maxRow = i;
        }

        int left =
            (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;

        int right =
            (midCol + 1 < m) ? mat[maxRow][midCol + 1] : -1;

        // Peak found
        if (mat[maxRow][midCol] > left &&
            mat[maxRow][midCol] > right)
        {
            return {maxRow, midCol};
        }

        // Search left half
        else if (left > mat[maxRow][midCol])
        {
            high = midCol - 1;
        }

        // Search right half
        else
        {
            low = midCol + 1;
        }
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    pair<int, int> peak = findPeakGrid(mat);

    cout << "Peak found at Index: ("
         << peak.first << ", "
         << peak.second << ")" << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

10 20 15
21 30 14
 7 16 32

Choose middle column = 1

Column values:
20
30
16

Maximum = 30
(row = 1)

Compare:

Left  = 21
Right = 14

30 > 21
30 > 14

Peak found.

Answer = (1, 1)

--------------------------------------

Another Example:

1  4  3
6  7  8
5  2  9

Middle column:

4
7
2

Maximum = 7

Right neighbour = 8

Since right is larger,
search RIGHT half.

Eventually peak = 9.

--------------------------------------

Time Complexity:

O(n * log m)

where:
n = number of rows
m = number of columns

Space Complexity:

O(1)

Memory Trick:

1. Binary Search on COLUMNS.

2. In every middle column,
   find the MAXIMUM element.

3. Compare only LEFT and RIGHT.

4. If current > both:
      Peak found.

5. Else move towards the larger neighbour.

Why not TOP/BOTTOM?

Because we already picked the maximum
element in that column, so top and bottom
cannot be greater than it.
*/