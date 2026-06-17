#include <iostream>
#include <vector>
using namespace std;

// Function to generate Pascal's Triangle
vector<vector<int>> generatePascalTriangle(int n)
{
    // -------------------- INTUITION --------------------
    //
    // Every row starts and ends with 1.
    //
    // Every middle element is:
    //
    // currentRow[j] =
    // previousRow[j - 1] + previousRow[j]
    //
    // Example:
    //
    //      1
    //     1 1
    //    1 2 1
    //   1 3 3 1
    //  1 4 6 4 1

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        vector<int> row(i + 1, 1);

        // Fill middle elements
        for (int j = 1; j < i; j++)
        {
            row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }

        ans.push_back(row);
    }

    return ans;
}

int main()
{
    int n = 5;

    // Only function call
    vector<vector<int>> triangle = generatePascalTriangle(n);

    // Print Pascal's Triangle
    for (auto &row : triangle)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Every row:

Starts with 1
Ends with 1

Middle element:

current[j] =
previous[j-1] + previous[j]

Example:

        1

      1   1

    1   2   1

  1   3   3   1

1   4   6   4   1

--------------------------------------

Time Complexity : O(n²)

Space Complexity : O(n²)

Memory Trick:

Boundary = 1

Middle =
Upper Left + Upper Right
*/