#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to rotate the matrix by 90 degrees clockwise
void rotateImage(vector<vector<int>> &matrix)
{
    // -------------------- INTUITION --------------------
    //
    // Rotation by 90° clockwise can be done in TWO steps:
    //
    // Step 1: Transpose the matrix
    //         (Swap rows with columns)
    //
    // Step 2: Reverse every row
    //
    // This avoids using any extra matrix.

    int n = matrix.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse every row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Only function call
    rotateImage(matrix);

    // Print rotated matrix
    for (auto &row : matrix)
    {
        for (int val : row)
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
Rotate an n x n matrix by 90° clockwise.

--------------------------------------

Step 1: Transpose

Original:

1 2 3
4 5 6
7 8 9

Transpose:

1 4 7
2 5 8
3 6 9

--------------------------------------

Step 2: Reverse every row

1 4 7  ->  7 4 1
2 5 8  ->  8 5 2
3 6 9  ->  9 6 3

Final:

7 4 1
8 5 2
9 6 3

--------------------------------------

Why does this work?

Transpose:
Rows become columns.

Reverse rows:
Places elements in their correct
90° clockwise positions.

--------------------------------------

Time Complexity : O(n²)
Space Complexity: O(1)

Memory Trick:

90° Clockwise =
1. Transpose
2. Reverse each Row

Remember:
"TR" -> Transpose, Reverse Rows
*/