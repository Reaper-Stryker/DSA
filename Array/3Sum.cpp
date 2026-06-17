#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find all unique triplets with sum = 0
vector<vector<int>> threeSum(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // Step 1: Sort the array.
    //
    // Step 2: Fix one element (arr[i]).
    //
    // Step 3: Use two pointers:
    //         left  = i + 1
    //         right = n - 1
    //
    // If sum < 0:
    //      Move left++
    //
    // If sum > 0:
    //      Move right--
    //
    // If sum == 0:
    //      Store the triplet.
    //      Skip duplicates.
    //      Move both pointers.

    vector<vector<int>> ans;

    int n = arr.size();

    // Sort the array
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        // Skip duplicate first elements
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum < 0)
            {
                left++;
            }
            else if (sum > 0)
            {
                right--;
            }
            else
            {
                ans.push_back({arr[i], arr[left], arr[right]});

                left++;
                right--;

                // Skip duplicate second elements
                while (left < right && arr[left] == arr[left - 1])
                    left++;

                // Skip duplicate third elements
                while (left < right && arr[right] == arr[right + 1])
                    right--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};

    // Only function call
    vector<vector<int>> ans = threeSum(arr);

    // Print triplets
    for (auto &triplet : ans)
    {
        for (int num : triplet)
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
Find all UNIQUE triplets
whose sum is 0.

--------------------------------------

Step 1:
Sort the array.

Example:

[-1, 0, 1, 2, -1, -4]

↓

[-4, -1, -1, 0, 1, 2]

--------------------------------------

Fix one element.

Suppose i = -1

Now search for:

left + right = +1

using Two Pointers.

--------------------------------------

Rules:

sum < 0
    -> left++

sum > 0
    -> right--

sum == 0
    -> Store answer
    -> left++
    -> right--
    -> Skip duplicates

--------------------------------------

Why skip duplicates?

Input:

[-1, -1, 0, 1]

Without skipping,
same triplet gets added twice.

--------------------------------------

Time Complexity :

Sorting = O(n log n)

Loop + Two Pointers = O(n²)

Overall = O(n²)

Space Complexity :

O(1)
(excluding output array)

Memory Trick:

Sort first.

Fix one number.

Then solve 2-Sum
using Two Pointers.

Remember:

Fix → Left → Right
Skip duplicates.
*/