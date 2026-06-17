#include <iostream>
#include <vector>
using namespace std;

// Function to find all elements appearing more than n/3 times
vector<int> majorityElement(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // For n/3 majority, there can be AT MOST 2 candidates.
    //
    // So maintain:
    // candidate1, count1
    // candidate2, count2
    //
    // Phase 1:
    // Find the two potential candidates.
    //
    // Phase 2:
    // Verify their frequencies.

    int count1 = 0, count2 = 0;
    int candidate1 = -1, candidate2 = -1;

    // ---------------- Phase 1 ----------------
    for (int num : arr)
    {
        if (num == candidate1)
        {
            count1++;
        }
        else if (num == candidate2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            candidate1 = num;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = num;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // ---------------- Phase 2 ----------------
    count1 = 0;
    count2 = 0;

    for (int num : arr)
    {
        if (num == candidate1)
            count1++;
        else if (num == candidate2)
            count2++;
    }

    vector<int> ans;
    int mini = arr.size() / 3 + 1;

    if (count1 >= mini)
        ans.push_back(candidate1);

    if (count2 >= mini)
        ans.push_back(candidate2);

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 1, 2, 2};

    // Only function call
    vector<int> ans = majorityElement(arr);

    cout << "Majority Elements: ";
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

For majority > n/3:

Maximum possible majority elements = 2

Why?

Suppose there are 3 elements each occurring
more than n/3 times.

Total count would exceed n,
which is impossible.

--------------------------------------

Maintain:

candidate1, count1
candidate2, count2

Rules:

1. Same as candidate1
      -> count1++

2. Same as candidate2
      -> count2++

3. count1 == 0
      -> candidate1 = current

4. count2 == 0
      -> candidate2 = current

5. Otherwise
      -> count1--
      -> count2--

After first pass,
VERIFY both candidates.

--------------------------------------

Example:

arr = [1,2,1,3,1,2,2]

Candidate1 = 1
Candidate2 = 2

Counts:

1 -> 3
2 -> 3

n = 7

Need > 7/3 = 2

Answer:
[1, 2]

--------------------------------------

Time Complexity : O(n)

Space Complexity : O(1)

Memory Trick:

For > n/2
    -> Keep ONE candidate

For > n/3
    -> Keep TWO candidates

Always VERIFY in the second pass.
*/