#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find the length of the longest consecutive sequence
int longestConsecutive(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // Store all elements in a HashSet for O(1) lookup.
    //
    // Only start counting from an element if it is the
    // START of a sequence.
    //
    // An element is the start if (element - 1) is NOT present.
    //
    // Then keep checking element+1, element+2, ...
    // until the sequence breaks.

    unordered_set<int> st;

    // Insert all elements into the hash set
    for (int num : arr)
    {
        st.insert(num);
    }

    int longest = 0;

    // Traverse every unique element
    for (int num : st)
    {
        // Check if this is the start of a sequence
        if (st.find(num - 1) == st.end())
        {
            int currentNum = num;
            int count = 1;

            // Count consecutive numbers
            while (st.find(currentNum + 1) != st.end())
            {
                currentNum++;
                count++;
            }

            // Update maximum length
            longest = max(longest, count);
        }
    }

    return longest;
}

int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};

    // Only function call
    cout << "Longest Consecutive Sequence Length: "
         << longestConsecutive(arr);

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Goal:
Find the length of the longest sequence of
consecutive integers.

Example:

arr = [100, 4, 200, 1, 3, 2]

Sequence:
1 -> 2 -> 3 -> 4

Answer = 4

------------------------------------

Key Observation:

Don't start counting from every element.

Only start if:
(num - 1) does NOT exist.

Example:

For 2:
1 exists -> skip

For 3:
2 exists -> skip

For 1:
0 doesn't exist -> START counting

Count:
1 -> 2 -> 3 -> 4

Length = 4

------------------------------------

Time Complexity : O(n)
Space Complexity: O(n)

Memory Trick:

Use HashSet.

Start counting ONLY when
(previous element doesn't exist).

This avoids repeated work.
*/