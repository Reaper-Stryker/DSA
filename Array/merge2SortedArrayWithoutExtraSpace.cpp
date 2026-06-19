#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge two sorted arrays without using extra space
void mergeSortedArrays(vector<int> &arr1, vector<int> &arr2)
{
    // -------------------- INTUITION --------------------
    //
    // Use the "Gap Method" (Shell Sort idea).
    //
    // Consider both arrays as one virtual array.
    //
    // Start with:
    // gap = ceil((n + m) / 2)
    //
    // Compare elements gap distance apart.
    // If out of order, swap them.
    //
    // Keep reducing:
    // gap = ceil(gap / 2)
    //
    // Continue until gap becomes 1.

    int n = arr1.size();
    int m = arr2.size();

    // Initial gap
    int gap = (n + m) / 2 + (n + m) % 2;

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while (right < n + m)
        {
            // Case 1:
            // Both pointers in arr1
            if (left < n && right < n)
            {
                if (arr1[left] > arr1[right])
                    swap(arr1[left], arr1[right]);
            }

            // Case 2:
            // left in arr1, right in arr2
            else if (left < n && right >= n)
            {
                if (arr1[left] > arr2[right - n])
                    swap(arr1[left], arr2[right - n]);
            }

            // Case 3:
            // Both pointers in arr2
            else
            {
                if (arr2[left - n] > arr2[right - n])
                    swap(arr2[left - n], arr2[right - n]);
            }

            left++;
            right++;
        }

        // Stop after processing gap = 1
        if (gap == 1)
            break;

        // Compute next gap = ceil(gap / 2)
        gap = gap / 2 + gap % 2;
    }
}

int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};

    // Only function call
    mergeSortedArrays(arr1, arr2);

    cout << "Array 1: ";
    for (int num : arr1)
        cout << num << " ";

    cout << endl;

    cout << "Array 2: ";
    for (int num : arr2)
        cout << num << " ";

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Goal:
Merge two sorted arrays
WITHOUT using extra space.

--------------------------------------

Treat both arrays as one
combined array.

Example:

arr1 = [1 4 8 10]

arr2 = [2 3 9]

Virtual array:

[1 4 8 10 | 2 3 9]

--------------------------------------

Gap Method:

Initial gap:

ceil((n+m)/2)

Compare elements gap apart.

Swap if needed.

Then reduce gap:

7 -> 4 -> 2 -> 1

When gap becomes 1,
after processing, stop.

--------------------------------------

Three cases while comparing:

1. Both indices in arr1

2. One index in arr1,
   one in arr2

3. Both indices in arr2

--------------------------------------

Time Complexity :

O((n + m) log(n + m))

Space Complexity :

O(1)

Memory Trick:

Think of BOTH arrays
as ONE big array.

Use Shell Sort idea:

Gap ↓
Compare
Swap
Repeat.
*/