#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the longest subarray with sum = k
int longestSubarrayWithSumK(vector<int> &arr, int k)
{
    unordered_map<long long, int> preSumMap;

    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // Calculate prefix sum
        sum += arr[i];

        // If prefix sum itself equals k
        if (sum == k)
        {
            maxLen = i + 1;
        }

        // Check if (sum - k) was seen before
        long long rem = sum - k;

        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // Store first occurrence only
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {2, -1, 3, 1, -2, 4};
    int k = 4;

    // Only function call
    cout << "Longest Length: "
         << longestSubarrayWithSumK(arr, k);

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Use Prefix Sum + HashMap.

At each index:
sum = prefix sum till current index.

Need:
sum - previousPrefix = k

So check if:
(previousPrefix == sum - k)

If found:
length = currentIndex - previousIndex

Store only the FIRST occurrence
of every prefix sum to maximize length.

Time Complexity : O(n)
Space Complexity: O(n)

Memory Trick:
Prefix Sum + HashMap
Need (sum - k) to exist.
*/