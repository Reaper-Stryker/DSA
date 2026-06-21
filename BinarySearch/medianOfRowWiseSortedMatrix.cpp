#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to count elements <= x in a sorted row
int upperBound(vector<int> &row, int x)
{
    int low = 0;
    int high = row.size() - 1;
    int ans = row.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (row[mid] > x)
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

// Function to find the median of a row-wise sorted matrix
int matrixMedian(vector<vector<int>> &matrix)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We CANNOT flatten and sort because that takes
    O(n * m * log(n*m)).

    Instead, Binary Search on the ANSWER.

    Observation:
    If we guess a value 'mid',
    we can count how many elements in the matrix
    are <= mid.

    Since every row is sorted,
    this count can be found using Upper Bound.

    If count <= required,
        median is larger.

    Otherwise,
        median is smaller or equal.

    Search Space:
    low  = minimum element in matrix
    high = maximum element in matrix

    Median position:
        (n * m) / 2
    (0-based indexing)
    */

    int n = matrix.size();
    int m = matrix[0].size();

    int low = matrix[0][0];
    int high = matrix[0][m - 1];

    // Find global minimum and maximum
    for (int i = 0; i < n; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    int required = (n * m) / 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            count += upperBound(matrix[i], mid);
        }

        if (count <= required)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 5, 7},
        {2, 3, 8},
        {4, 6, 9}
    };

    cout << "Median = "
         << matrixMedian(matrix) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

Matrix:

1 5 7
2 3 8
4 6 9

Flattened:

1 2 3 4 5 6 7 8 9

Median = 5

--------------------------------------

Binary Search on VALUE:

Suppose mid = 4

Count elements <= 4

Row 1:
1 -> count = 1

Row 2:
2 3 -> count = 2

Row 3:
4 -> count = 1

Total = 4

Need median position = 4

Count <= required

Search RIGHT.

--------------------------------------

Suppose mid = 5

Count <= 5

Total = 5

Now count > required

Search LEFT.

Eventually answer = 5.

--------------------------------------

Time Complexity:

O(log(MaxValue - MinValue) * n * log(m))

where:
n = number of rows
m = number of columns

Space Complexity:

O(1)

Memory Trick:

1. Binary Search on the VALUE,
   not on indices.

2. For every guessed value mid,
   count elements <= mid.

3. Use Upper Bound in every row.

4. If count <= required:
      move RIGHT.

5. Else:
      move LEFT.

Key Formula:

required = (n * m) / 2

Median is the first value whose
count of elements <= value exceeds
the required position.
*/