#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count subarrays with sum equal to k
int countSubarraysWithSumK(vector<int> &arr, int k)
{
    // -------------------- INTUITION --------------------
    //
    // Use Prefix Sum + HashMap.
    //
    // Let:
    // prefixSum = sum of elements from index 0 to i.
    //
    // We need:
    // prefixSum - previousPrefixSum = k
    //
    // => previousPrefixSum = prefixSum - k
    //
    // If (prefixSum - k) has occurred before,
    // then every occurrence contributes one valid subarray.

    unordered_map<int, int> mp;

    // Important:
    // Prefix sum 0 has occurred once before starting.
    mp[0] = 1;

    int prefixSum = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // Update running prefix sum
        prefixSum += arr[i];

        // We need (prefixSum - k)
        int remove = prefixSum - k;

        // If found, add its frequency
        count += mp[remove];

        // Store current prefix sum
        mp[prefixSum]++;
    }

    return count;
}

int main()
{
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1};
    int k = 3;

    // Only function call
    cout << "Count of Subarrays: "
         << countSubarraysWithSumK(arr, k);

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Goal:
Count the number of subarrays
whose sum equals k.

--------------------------------------

Use Prefix Sum + HashMap.

Suppose:

Current Prefix Sum = sum

Need:
sum - previousSum = k

Therefore,

previousSum = sum - k

If (sum - k) already exists in the map,
then all of its occurrences form
valid subarrays ending at the current index.

--------------------------------------

Example:

arr = [1, 2, 3]
k = 3

Prefix Sums:

1
3
6

At sum = 3:
Need 0

Map contains:
0 -> once

Count = 1

At sum = 6:
Need 3

Map contains:
3 -> once

Count = 2

Subarrays:

[1,2]
[3]

--------------------------------------

Why initialize:

mp[0] = 1 ?

Because if prefixSum itself equals k,
then the subarray starts from index 0.

--------------------------------------

Time Complexity : O(n)

Space Complexity : O(n)

Memory Trick:

Need:
prefixSum - previousPrefix = k

So search for:
(prefixSum - k)

HashMap stores:
Prefix Sum -> Frequency

Don't forget:

mp[0] = 1
*/