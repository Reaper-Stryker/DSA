#include <iostream>
#include <vector>
using namespace std;

// Function to search an element in a 2D sorted matrix
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    Given:
    - Each row is sorted.
    - First element of every row is greater than
      the last element of the previous row.

    Example:

    1   3   5   7
    10 11 16 20
    23 30 34 60

    If we flatten it:

    [1,3,5,7,10,11,16,20,23,30,34,60]

    It becomes a completely sorted 1D array.

    Instead of actually flattening it,
    map a 1D index to 2D coordinates:

        row = mid / numberOfColumns
        col = mid % numberOfColumns

    Then perform normal Binary Search.
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
            return true;

        else if (matrix[row][col] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int target = 16;

    if (searchMatrix(matrix, target))
        cout << "Element Found";
    else
        cout << "Element Not Found";

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

Target = 16

Imagine flattening:

Index:
0  1  2  3  4  5  6  7  8  9 10 11

Value:
1  3  5  7 10 11 16 20 23 30 34 60

Binary Search works directly.

--------------------------------------

Index Mapping:

Suppose:

mid = 6
m = 4

row = 6 / 4 = 1
col = 6 % 4 = 2

matrix[1][2] = 16

Found.

--------------------------------------

Time Complexity:
O(log(n * m))

Space Complexity:
O(1)

Memory Trick:

1. Treat the matrix as a sorted 1D array.

2. Convert index to coordinates:

      row = mid / m
      col = mid % m

3. Apply normal Binary Search.

No extra array is needed.
*/