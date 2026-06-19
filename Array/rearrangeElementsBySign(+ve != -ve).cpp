#include <iostream>
#include <vector>
using namespace std;

// Function to rearrange elements by sign
vector<int> rearrangeArray(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // Step 1:
    // Store all positive numbers separately.
    //
    // Step 2:
    // Store all negative numbers separately.
    //
    // Step 3:
    // Alternate between positives and negatives
    // until one list is exhausted.
    //
    // Step 4:
    // Append the remaining elements.

    vector<int> positive;
    vector<int> negative;

    // Separate positives and negatives
    for (int num : arr)
    {
        if (num > 0)
            positive.push_back(num);
        else
            negative.push_back(num);
    }

    vector<int> ans;
    int i = 0, j = 0;

    // Alternate while both lists have elements
    while (i < positive.size() && j < negative.size())
    {
        ans.push_back(positive[i++]);
        ans.push_back(negative[j++]);
    }

    // Add remaining positives
    while (i < positive.size())
    {
        ans.push_back(positive[i++]);
    }

    // Add remaining negatives
    while (j < negative.size())
    {
        ans.push_back(negative[j++]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, -4, -1, 4};

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

Case:

Positive count != Negative count

Example:

[1, 2, 3, -4, -1, 4]

Positives:
[1, 2, 3, 4]

Negatives:
[-4, -1]

Alternate:

1 -4 2 -1

Negatives finished.

Append remaining positives:

3 4

Final:

[1, -4, 2, -1, 3, 4]

--------------------------------------

Similarly,

Input:

[-1, -2, -3, 4]

Positives:
[4]

Negatives:
[-1, -2, -3]

Result:

[4, -1, -2, -3]

--------------------------------------

Time Complexity : O(n)

Space Complexity : O(n)

Memory Trick:

1. Separate positives and negatives.
2. Alternate them.
3. Append leftovers.
*/