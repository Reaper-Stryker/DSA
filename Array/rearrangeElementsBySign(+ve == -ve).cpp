#include <iostream>
#include <vector>
using namespace std;

// Function to rearrange elements by sign
vector<int> rearrangeArray(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // Since positives and negatives are equal,
    // place positives at even indices:
    // 0, 2, 4, ...
    //
    // Place negatives at odd indices:
    // 1, 3, 5, ...
    //
    // Maintain two pointers:
    //
    // posIndex = 0
    // negIndex = 1

    int n = arr.size();

    vector<int> ans(n);

    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
        else
        {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};

    // Only function call
    vector<int> ans = rearrangeArray(arr);

    // Print rearranged array
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

Given:

Equal number of
positive and negative elements.

Need:

Positive
Negative
Positive
Negative
...

--------------------------------------

Maintain:

posIndex = 0

negIndex = 1

Traverse the array:

If positive:
    place at posIndex
    posIndex += 2

If negative:
    place at negIndex
    negIndex += 2

--------------------------------------

Example:

Input:

[3,1,-2,-5,2,-4]

Output:

[3,-2,1,-5,2,-4]

--------------------------------------

Time Complexity : O(n)

Space Complexity : O(n)

Memory Trick:

Even indices  -> Positive

Odd indices   -> Negative

Keep jumping by 2.
*/