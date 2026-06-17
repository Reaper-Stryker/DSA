#include <iostream>
#include <vector>
using namespace std;

// Function to sort an array containing only 0s, 1s and 2s
void sortColors(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // We divide the array into four regions:
    //
    // 0 to low-1        -> All 0s
    // low to mid-1      -> All 1s
    // mid to high       -> Unsorted elements
    // high+1 to n-1     -> All 2s
    //
    // We process the element at 'mid':
    //
    // If arr[mid] == 0:
    //      Swap with arr[low]
    //      Increment both low and mid
    //
    // If arr[mid] == 1:
    //      It is already in the correct region
    //      Increment mid
    //
    // If arr[mid] == 2:
    //      Swap with arr[high]
    //      Decrement high
    //      Do NOT increment mid because the swapped
    //      element needs to be checked.

    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    // Only function call
    sortColors(arr);

    // Print sorted array
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

Maintain three pointers:

low  -> Next position for 0
mid  -> Current element being processed
high -> Next position for 2

Invariant:

[0 ... low-1]     -> 0s
[low ... mid-1]   -> 1s
[mid ... high]    -> Unsorted
[high+1 ... n-1]  -> 2s

Rules:

1. arr[mid] == 0
      swap(low, mid)
      low++, mid++

2. arr[mid] == 1
      mid++

3. arr[mid] == 2
      swap(mid, high)
      high--
      (Don't move mid)

Example:

Initial:
[2, 0, 2, 1, 1, 0]

Final:
[0, 0, 1, 1, 2, 2]

Time Complexity : O(n)
Space Complexity: O(1)

Memory Trick:

0 -> Send LEFT  (low++, mid++)
1 -> STAY       (mid++)
2 -> Send RIGHT (high-- only)

Remember:
After swapping with high,
don't increment mid because
the incoming element is still unchecked.
*/