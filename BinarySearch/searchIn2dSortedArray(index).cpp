#include <iostream>
#include <vector>
using namespace std;

// Function to return the index of the target in the matrix
pair<int, int> searchMatrix(vector<vector<int>> &matrix, int target)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    The matrix satisfies:
    - Every row is sorted.
    - First element of each row is greater than
      the last element of the previous row.

    Hence, the entire matrix can be viewed as
    one sorted 1D array.

    Binary Search on indices:
        row = mid / numberOfColumns
        col = mid % numberOfColumns

    If target is found, return {row, col}.
    Otherwise, return {-1, -1}.
    */

    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n * m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target)
            return {row, col};

        else if (matrix[row][col] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 16;

    pair<int, int> ans = searchMatrix(matrix, target);

    if (ans.first == -1)
        cout << "Element Not Found";
    else
        cout << "Found at Index: (" << ans.first
             << ", " << ans.second << ")";

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

matrix =

1   3   5   7
10 11 16 20
23 30 34 60

target = 16

Flattened view:

[1,3,5,7,10,11,16,20,23,30,34,60]

Suppose mid = 6

row = 6 / 4 = 1
col = 6 % 4 = 2

matrix[1][2] = 16

Return (1, 2).

--------------------------------------

Time Complexity : O(log(n * m))

Space Complexity : O(1)

Memory Trick:

1. Imagine the matrix as a sorted 1D array.
2. row = mid / m
3. col = mid % m
4. Perform normal Binary Search.
5. Return (row, col) if found, else (-1, -1).
*/