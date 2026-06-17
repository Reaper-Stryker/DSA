#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the next lexicographically greater permutation
void nextPermutation(vector<int> &arr)
{
    int n = arr.size();

    // -------------------- INTUITION --------------------
    //
    // Step 1:
    // Traverse from the back and find the first index 'ind'
    // such that arr[ind] < arr[ind + 1].
    //
    // This is called the "break point".
    //
    // Example:
    // 2 1 5 4 3 0 0
    //       ^
    //       ind = 1 (1 < 5)
    //
    // If no such index exists,
    // the array is in descending order,
    // so simply reverse it to get the smallest permutation.

    int ind = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            ind = i;
            break;
        }
    }

    // Already the last permutation
    if (ind == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    // Step 2:
    // Find the first element from the end
    // which is greater than arr[ind]
    for (int i = n - 1; i > ind; i--)
    {
        if (arr[i] > arr[ind])
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }

    // Step 3:
    // Reverse everything after the break point
    // to get the smallest possible arrangement.
    reverse(arr.begin() + ind + 1, arr.end());
}

int main()
{
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};

    // Only function call
    nextPermutation(arr);

    // Print next permutation
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Goal:
Find the next lexicographically greater permutation.

Algorithm (3 Steps):

1. Find the BREAK POINT
   (first index from right where arr[i] < arr[i+1])

2. Find the first element from the END
   greater than arr[breakPoint]
   and swap them.

3. Reverse everything after the break point.

Example:

2 1 5 4 3 0 0

Step 1:
Break Point = 1

2 [1] 5 4 3 0 0

Step 2:
Just larger element = 3

2 3 5 4 1 0 0

Step 3:
Reverse suffix

2 3 0 0 1 4 5

Answer:
2 3 0 0 1 4 5

-------------------------
If no break point exists:

Example:
5 4 3 2 1

Reverse entire array:

1 2 3 4 5

-------------------------

Time Complexity : O(n)
Space Complexity: O(1)

Memory Trick:

1. Find Break Point
2. Find Just Greater Element
3. Swap
4. Reverse the Suffix

Remember:
"Break -> Swap -> Reverse"
*/
