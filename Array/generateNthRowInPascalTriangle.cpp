#include <iostream>
#include <vector>
using namespace std;

// Function to generate the nth row (1-indexed)
vector<int> generateRow(int row)
{
    vector<int> ans;

    // First element is always 1
    int res = 1;
    ans.push_back(res);

    // Compute remaining elements using nCr formula
    for (int col = 1; col < row; col++)
    {
        res = res * (row - col);
        res = res / col;

        ans.push_back(res);
    }

    return ans;
}

int main()
{
    int row = 5;

    // Only function call
    vector<int> ans = generateRow(row);

    for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Nth row can be generated using:

nCr

Instead of calculating factorials,

Use:

res = res * (row - col)
res = res / col

Example:

5th row:

1

1 * 4 / 1 = 4

4 * 3 / 2 = 6

6 * 2 / 3 = 4

4 * 1 / 4 = 1

Answer:

1 4 6 4 1

Time Complexity : O(n)

Space Complexity : O(n)

Memory Trick:

Next Element =
Previous × (n - r) / r
*/