#include <iostream>
#include <vector>
using namespace std;

// Function to return the spiral traversal of the matrix
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    // -------------------- INTUITION --------------------
    //
    // Maintain four boundaries:
    //
    // top    -> first unvisited row
    // bottom -> last unvisited row
    // left   -> first unvisited column
    // right  -> last unvisited column
    //
    // Traverse in this order:
    // 1. Left  -> Right   (top row)
    // 2. Top   -> Bottom  (right column)
    // 3. Right -> Left    (bottom row)
    // 4. Bottom-> Top     (left column)
    //
    // After each traversal, shrink the corresponding boundary.

    vector<int> ans;

    int n = matrix.size();
    int m = matrix[0].size();

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;

    while (top <= bottom && left <= right)
    {
        // Traverse left -> right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // Traverse top -> bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // Traverse right -> left
        // Check needed to avoid duplicate traversal
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse bottom -> top
        // Check needed to avoid duplicate traversal
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Only function call
    vector<int> result = spiralOrder(matrix);

    // Print spiral order
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Maintain four boundaries:

top
bottom
left
right

Traverse in CLOCKWISE order:

1. top row      : left  -> right
2. right column : top   -> bottom
3. bottom row   : right -> left
4. left column  : bottom-> top

After every traversal,
shrink the corresponding boundary.

--------------------------------------

Example:

1   2   3   4
5   6   7   8
9  10  11  12
13 14  15  16

Spiral:

1 2 3 4
8 12 16
15 14 13
9 5
6 7
11
10

Answer:

1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

--------------------------------------

IMPORTANT:

Before traversing
bottom row:

if (top <= bottom)

Before traversing
left column:

if (left <= right)

Otherwise elements may be visited twice.

--------------------------------------

Time Complexity : O(n * m)

Space Complexity : O(n * m)
(for storing the answer)

Memory Trick:

Keep shrinking:

Top ↓
Right ←
Bottom ↑
Left →

Repeat until boundaries cross.

Order:
Right → Down ↓ Left ← Up ↑
*/