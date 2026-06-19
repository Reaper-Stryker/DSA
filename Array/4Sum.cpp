#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find all unique quadruplets with sum = target
vector<vector<int>> fourSum(vector<int> &arr, int target)
{
    // -------------------- INTUITION --------------------
    //
    // Similar to 3 Sum.
    //
    // Step 1: Sort the array.
    //
    // Step 2: Fix the first element (i).
    //
    // Step 3: Fix the second element (j).
    //
    // Step 4: Use two pointers:
    //         left = j + 1
    //         right = n - 1
    //
    // Compare:
    // arr[i] + arr[j] + arr[left] + arr[right]
    //
    // Skip duplicates at every level.

    vector<vector<int>> ans;

    int n = arr.size();

    // Sort the array
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        // Skip duplicate first elements
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            // Skip duplicate second elements
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                // Use long long to avoid integer overflow
                long long sum = (long long)arr[i] +
                                arr[j] +
                                arr[left] +
                                arr[right];

                if (sum < target)
                {
                    left++;
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    ans.push_back({arr[i], arr[j], arr[left], arr[right]});

                    left++;
                    right--;

                    // Skip duplicate third elements
                    while (left < right && arr[left] == arr[left - 1])
                        left++;

                    // Skip duplicate fourth elements
                    while (left < right && arr[right] == arr[right + 1])
                        right--;
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    // Only function call
    vector<vector<int>> ans = fourSum(arr, target);

    // Print quadruplets
    for (auto &quad : ans)
    {
        for (int num : quad)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Goal:
Find all UNIQUE quadruplets
whose sum equals target.

--------------------------------------

Step 1:
Sort the array.

Example:

[1,0,-1,0,-2,2]

↓

[-2,-1,0,0,1,2]

--------------------------------------

Fix first element (i).

Fix second element (j).

Now solve:

2-Sum on the remaining array
using Two Pointers.

--------------------------------------

Use:

left = j + 1
right = n - 1

sum = arr[i] + arr[j]
    + arr[left] + arr[right]

If sum < target
    -> left++

If sum > target
    -> right--

If sum == target
    -> Store answer
    -> Move both pointers
    -> Skip duplicates

--------------------------------------

IMPORTANT:

Use long long while computing sum
to avoid integer overflow.

--------------------------------------

Time Complexity:

Sorting      -> O(n log n)

Outer loops  -> O(n²)

Two pointers -> O(n)

Overall:

O(n³)

Space Complexity:

O(1)
(excluding output)

Memory Trick:

4 Sum =

Fix first element
+
Fix second element
+
Solve 2-Sum

Remember:

Sort
→ Fix i
→ Fix j
→ Left & Right
→ Skip duplicates
*/