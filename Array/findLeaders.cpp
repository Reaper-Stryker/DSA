#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find all leader elements
vector<int> findLeaders(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // Traverse the array from RIGHT to LEFT.
    //
    // Keep track of the maximum element seen so far.
    //
    // If the current element is greater than this maximum,
    // then it is a leader.
    //
    // Finally, reverse the answer because we traversed
    // from right to left.

    int n = arr.size();

    vector<int> ans;

    // Rightmost element is always a leader
    int maxi = arr[n - 1];
    ans.push_back(maxi);

    // Traverse from second last element towards left
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    // Reverse to maintain original left-to-right order
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};

    // Only function call
    vector<int> leaders = findLeaders(arr);

    // Print leaders
    cout << "Leader Elements: ";
    for (int num : leaders)
    {
        cout << num << " ";
    }

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Definition:
A leader is an element that is greater
than all elements to its right.

Observation:
The last element is always a leader.

Algorithm:

1. Start from the last element.
2. Keep track of the maximum element
   seen so far (maxi).
3. If current element > maxi:
      -> It is a leader.
      -> Update maxi.
4. Reverse the result at the end.

Example:

arr = [10, 22, 12, 3, 0, 6]

Traverse from right:

6  -> Leader
0  -> Not leader
3  -> Not leader
12 -> Leader
22 -> Leader
10 -> Not leader

Collected (right to left):
[6, 12, 22]

After reversing:
[22, 12, 6]

Time Complexity : O(n)
Space Complexity: O(n)   // For storing the answer

Memory Trick:

Go from RIGHT to LEFT.

Keep a variable:
maxi = largest seen so far

If current > maxi
    -> It's a leader.

Finally, reverse the answer.
*/