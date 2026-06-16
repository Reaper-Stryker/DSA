#include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates from a sorted array
void removeDuplicates(vector<int> &arr)
{
    // Edge case: If the array is empty, nothing to do.
    if (arr.empty())
    {
        return;
    }

    // -------------------- INTUITION --------------------
    // Since the array is already SORTED,
    // all duplicate elements will be adjacent.
    //
    // We use two pointers:
    //
    // i -> Points to the position where the next unique element
    //      should be placed.
    //
    // j -> Traverses the array searching for new unique elements.
    //
    // Example:
    // arr = [1, 1, 2, 2, 3, 4, 4]
    //
    // Initially:
    // i = 0 (points to first unique element)
    //
    // j moves through the array:
    // If arr[j] != arr[i],
    // then we found a new unique element.
    // Increment i and copy arr[j] to arr[i].
    //
    // Final unique portion becomes:
    // [1, 2, 3, 4]
    //
    // Finally resize the vector to keep only unique elements.

    int i = 0;

    for (int j = 1; j < arr.size(); j++)
    {
        // Found a new unique element
        if (arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }

    // Keep only the unique elements
    arr.resize(i + 1);
}

int main()
{
    // Sorted input array
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5, 5, 5};

    // Only function call
    removeDuplicates(arr);

    // Print the updated array
    cout << "Array after removing duplicates:\n";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
=========================
REVISION INTUITION
=========================

Question: Remove duplicates from a SORTED array in-place.

Observation:
- Because the array is sorted,
  duplicates always appear next to each other.

Use Two Pointers:

i -> Last unique element's index.
j -> Scans the array.

Whenever arr[j] != arr[i]:
    i++;
    arr[i] = arr[j];

At the end:
    Number of unique elements = i + 1

Time Complexity  : O(n)
Space Complexity : O(1)

Memory Trick:
i = "unique section end"
j = "explorer"

Explorer finds a new unique value ->
expand the unique section by one.
*/