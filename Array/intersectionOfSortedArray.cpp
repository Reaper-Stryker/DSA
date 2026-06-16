#include <iostream>
#include <vector>
using namespace std;

// Function to find the intersection of two sorted arrays
vector<int> findIntersection(vector<int> &arr1, vector<int> &arr2)
{
    // -------------------- INTUITION --------------------
    //
    // Since both arrays are SORTED, use the Two Pointer approach.
    //
    // i -> traverses arr1
    // j -> traverses arr2
    //
    // Case 1: arr1[i] < arr2[j]
    //         -> arr1[i] cannot be in intersection
    //         -> move i
    //
    // Case 2: arr1[i] > arr2[j]
    //         -> arr2[j] cannot be in intersection
    //         -> move j
    //
    // Case 3: arr1[i] == arr2[j]
    //         -> common element found
    //         -> add it once and move both pointers

    vector<int> ans;

    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            // Add only if it is not already the last inserted element
            // This avoids duplicates in the answer.
            if (ans.empty() || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }

            i++;
            j++;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr1 = {1, 2, 2, 3, 4, 5};
    vector<int> arr2 = {2, 2, 3, 5, 6};

    // Only function call
    vector<int> result = findIntersection(arr1, arr2);

    // Print intersection
    cout << "Intersection: ";
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}

/*
=========================
REVISION INTUITION
=========================

Question:
Find INTERSECTION of two SORTED arrays.

Use Two Pointers:

i -> arr1
j -> arr2

Rules:

1. If arr1[i] < arr2[j]
      -> Move i

2. If arr1[i] > arr2[j]
      -> Move j

3. If arr1[i] == arr2[j]
      -> Common element found
      -> Add it once
      -> Move both pointers

Example:

arr1 = [1 2 2 3 4 5]
arr2 = [2 2 3 5 6]

Answer:
[2 3 5]

Time Complexity  : O(n + m)
Space Complexity : O(min(n, m)) for the output

Memory Trick:
"Smaller value can never match later,
so move its pointer.
Equal values? Add once and move both."

Note (Striver-style variant): 
If the problem expects duplicates in the intersection 
(e.g., [2,2] when both arrays contain two 2s), 
then remove the ans.back() duplicate check and 
simply push_back(arr1[i]) when the elements are equal.
*/