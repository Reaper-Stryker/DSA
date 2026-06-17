#include <iostream>
#include <vector>
using namespace std;

// Function to find the majority element
int majorityElement(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // Majority Element:
    // An element that appears MORE THAN n/2 times.
    //
    // Moore's Voting Algorithm works in two phases:
    //
    // Phase 1: Find a potential candidate.
    // Phase 2: Verify that the candidate is actually
    //          the majority element.
    //
    // The idea is that every occurrence of a different
    // element cancels out one occurrence of the majority element.
    // Since the majority element appears more than n/2 times,
    // it will always survive in the end.

    int candidate = -1;
    int count = 0;

    // ---------------- Phase 1 ----------------
    // Find the potential majority candidate
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            candidate = arr[i];
            count = 1;
        }
        else if (arr[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    // ---------------- Phase 2 ----------------
    // Verify the candidate
    count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }

    if (count > arr.size() / 2)
    {
        return candidate;
    }

    // No majority element exists
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 2, 2, 2};

    // Only function call
    cout << "Majority Element: " << majorityElement(arr);

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Majority Element:
Frequency > n/2

Idea:
Every different element cancels one occurrence
of the majority element.

Example:

[2, 2, 1, 1, 2, 2, 2]

count = 0

2 -> candidate = 2, count = 1
2 -> count = 2
1 -> count = 1
1 -> count = 0
2 -> candidate = 2, count = 1
2 -> count = 2
2 -> count = 3

Candidate = 2

Verify:
Frequency of 2 = 5
5 > 7/2 => true

Answer = 2

-------------------------
Time Complexity : O(n)
Space Complexity: O(1)

Memory Trick:

count == 0
    -> Choose new candidate

same element
    -> count++

different element
    -> count--

Finally, VERIFY the candidate by counting
its occurrences.
*/