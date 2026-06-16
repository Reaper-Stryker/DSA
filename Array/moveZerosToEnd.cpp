#include <iostream>
#include <vector>
using namespace std;

// Function to move all zeros to the end of the array
void moveZerosToEnd(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // We use the Two Pointer approach.
    //
    // j -> Points to the position where the next non-zero
    //      element should be placed.
    //
    // i -> Traverses the array.
    //
    // Whenever we find a non-zero element at i,
    // swap it with the element at j and increment j.
    //
    // This automatically pushes all zeros towards the end.
    //
    // Example:
    // [1, 0, 2, 0, 3, 4]
    //
    // j = 0
    //
    // i = 0 -> 1 (non-zero) -> swap(0,0)
    // [1,0,2,0,3,4], j = 1
    //
    // i = 1 -> 0 -> ignore
    //
    // i = 2 -> 2 -> swap(2,1)
    // [1,2,0,0,3,4], j = 2
    //
    // i = 4 -> 3 -> swap(4,2)
    // [1,2,3,0,0,4], j = 3
    //
    // i = 5 -> 4 -> swap(5,3)
    // [1,2,3,4,0,0]

    int j = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // Only process non-zero elements
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {1, 0, 2, 0, 3, 0, 4, 5, 0};

    // Only function call
    moveZerosToEnd(arr);

    // Print updated array
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}

/*
=========================
REVISION INTUITION
=========================

Goal:
Move all 0's to the END while keeping
the order of non-zero elements unchanged.

Use Two Pointers:

j -> Position where next non-zero should go.
i -> Traverses the array.

If arr[i] != 0:
    swap(arr[i], arr[j])
    j++

Think of j as:
"Next free slot for a non-zero element."

Example:

Before:
[1, 0, 2, 0, 3, 4]

After:
[1, 2, 3, 4, 0, 0]

Time Complexity  : O(n)
Space Complexity : O(1)

Interview Trick:
Ignore zeros.
Keep bringing non-zero elements to the front.
Zeros automatically accumulate at the back.
*/