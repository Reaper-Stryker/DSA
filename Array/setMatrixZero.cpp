#include <iostream>
#include <vector>
using namespace std;

// Function to set matrix zeroes
void setZeroes(vector<vector<int>> &matrix)
{
    // -------------------- INTUITION --------------------
    //
    // Instead of using extra row[] and col[] arrays,
    // use the FIRST ROW and FIRST COLUMN as markers.
    //
    // If matrix[i][j] == 0:
    //      mark matrix[i][0] = 0
    //      mark matrix[0][j] = 0
    //
    // Special Case:
    // We cannot use matrix[0][0] for both first row
    // and first column.
    //
    // Therefore, maintain an extra variable:
    // col0 -> tells whether the first column
    // should become zero.

    int n = matrix.size();
    int m = matrix[0].size();

    int col0 = 1;

    // Step 1: Mark rows and columns
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            col0 = 0;
        }

        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Step 2: Traverse from bottom-right
    // and update cells based on markers
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }

        // Handle first column separately
        if (col0 == 0)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    // Only function call
    setZeroes(matrix);

    // Print updated matrix
    for (auto &row : matrix)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Goal:
If any cell is 0,
make its ENTIRE ROW and COLUMN zero.

--------------------------------------

Naive:
Store rows and columns separately.

Space = O(n + m)

--------------------------------------

Optimal Idea:

Use:
First Row -> Column markers

First Column -> Row markers

Need one extra variable:

col0

because matrix[0][0] cannot represent
both first row and first column.

--------------------------------------

Example:

1 1 1
1 0 1
1 1 1

Mark:

1 0 1
0 0 1
1 1 1

Then update:

1 0 1
0 0 0
1 0 1

--------------------------------------

Algorithm:

1. Traverse matrix.
   Whenever matrix[i][j] == 0:
       matrix[i][0] = 0
       matrix[0][j] = 0

2. Traverse from bottom-right.
   If row marker or column marker is 0:
       make current cell 0.

3. Handle first column separately using col0.

Time Complexity : O(n * m)
Space Complexity: O(1)

Memory Trick:

Use first ROW as column markers.
Use first COLUMN as row markers.
Use one extra variable: col0.

Think:
"Mark first, then zero later."
*/