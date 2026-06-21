#include <iostream>
#include <vector>
using namespace std;

// Helper function to find the first occurrence of 1 in a sorted row
int lowerBound(vector<int> &row)
{
    int low = 0;
    int high = row.size() - 1;
    int ans = row.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (row[mid] == 1)
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

// Function to find the row with maximum number of 1s
int rowWithMax1s(vector<vector<int>> &matrix)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    Given:
    - Every row is sorted.
    - 0's appear before 1's.

    Observation:
    If we know the index of the FIRST 1 in a row,
    then

        Number of 1's = columns - firstOneIndex

    So for every row:
    1. Find the first occurrence of 1 using Binary Search.
    2. Compute count of 1's.
    3. Keep track of the row having maximum count.

    If a row has no 1's,
    lowerBound() returns m,
    giving count = 0.
    */

    int n = matrix.size();
    int m = matrix[0].size();

    int maxOnes = 0;
    int answerRow = -1;

    for (int i = 0; i < n; i++)
    {
        int firstOne = lowerBound(matrix[i]);

        int countOnes = m - firstOne;

        if (countOnes > maxOnes)
        {
            maxOnes = countOnes;
            answerRow = i;
        }
    }

    return answerRow;
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 1, 1}};

    cout << "Row with Maximum 1s = "
         << rowWithMax1s(matrix)
         << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

matrix =

0 0 1 1
0 1 1 1
0 0 0 1
1 1 1 1

Row 0:
First 1 at index 2
Count = 4 - 2 = 2

Row 1:
First 1 at index 1
Count = 4 - 1 = 3

Row 2:
First 1 at index 3
Count = 4 - 3 = 1

Row 3:
First 1 at index 0
Count = 4 - 0 = 4

Maximum = 4

Answer = Row 3

--------------------------------------

Time Complexity:
O(n * log m)

where
n = number of rows
m = number of columns

Space Complexity:
O(1)

Memory Trick:

1. Every row is sorted.

2. Find FIRST occurrence of 1
   using Binary Search.

3. Number of 1's =
      totalColumns - firstOneIndex

4. Keep the row with the maximum count.

Formula to remember:

    countOfOnes = m - lowerBound(row)
*/