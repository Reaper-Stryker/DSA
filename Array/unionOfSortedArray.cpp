#include <iostream>
#include <vector>
using namespace std;

// Function to find the union of two sorted arrays
vector<int> findUnion(vector<int> &arr1, vector<int> &arr2)
{
    // -------------------- INTUITION --------------------
    //
    // Since BOTH arrays are sorted, we can use the
    // Two Pointer technique.
    //
    // i -> traverses arr1
    // j -> traverses arr2
    //
    // Compare arr1[i] and arr2[j]:
    //
    // 1. Smaller element definitely belongs to the union.
    // 2. If both are equal, add only ONE copy and move both pointers.
    // 3. Before inserting into the answer, make sure it is
    //    not the same as the last inserted element.
    //
    // This avoids duplicates automatically.

    vector<int> ans;

    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            // Add only if different from last inserted element
            if (ans.empty() || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            if (ans.empty() || ans.back() != arr2[j])
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }
        else
        {
            // Same element in both arrays -> add only once
            if (ans.empty() || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    // Add remaining elements from arr1
    while (i < arr1.size())
    {
        if (ans.empty() || ans.back() != arr1[i])
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    // Add remaining elements from arr2
    while (j < arr2.size())
    {
        if (ans.empty() || ans.back() != arr2[j])
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }

    return ans;
}

int main()
{
    vector<int> arr1 = {1, 2, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5, 6};

    // Only function call
    vector<int> result = findUnion(arr1, arr2);

    // Print union
    cout << "Union: ";
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
Find UNION of two SORTED arrays.

Use Two Pointers:

i -> arr1
j -> arr2

Case 1:
arr1[i] < arr2[j]
=> Take arr1[i]
=> i++

Case 2:
arr2[j] < arr1[i]
=> Take arr2[j]
=> j++

Case 3:
arr1[i] == arr2[j]
=> Take only ONE copy
=> i++, j++

IMPORTANT:
Before pushing into answer:
    if (answer is empty OR answer.back() != current)
        push it

This prevents duplicates.

Example:

arr1 = [1 2 2 3 5]
arr2 = [2 3 4 5]

Answer:
[1 2 3 4 5]

Time Complexity  : O(n + m)
Space Complexity : O(n + m)   // For storing the union

Memory Trick:
"Two sorted arrays → Two pointers.
Always take the smaller element.
If equal → take once and move both."
*/