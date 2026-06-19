#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count the number of subarrays with XOR = k
int subarraysWithXorK(vector<int> &arr, int k)
{
    // -------------------- INTUITION --------------------
    //
    // Similar to Prefix Sum problems, but using XOR.
    //
    // Let:
    // xr = XOR of elements from index 0 to i.
    //
    // Suppose:
    // previousXor ^ xr = k
    //
    // Then,
    // previousXor = xr ^ k
    //
    // So, if (xr ^ k) has appeared before,
    // every occurrence forms one valid subarray.

    unordered_map<int, int> mp;

    // XOR = 0 exists before starting
    mp[0] = 1;

    int xr = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // Update prefix XOR
        xr ^= arr[i];

        // Required previous XOR
        int x = xr ^ k;

        // Add all occurrences
        count += mp[x];

        // Store current XOR
        mp[xr]++;
    }

    return count;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    // Only function call
    cout << "Number of Subarrays: "
         << subarraysWithXorK(arr, k);

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Goal:
Count subarrays whose XOR = k.

--------------------------------------

Prefix XOR Idea:

Let:

xr = XOR till current index

Suppose a previous prefix XOR = p

Then,

p ^ xr = k

Using XOR property:

p = xr ^ k

So,

At every index:
Search for (xr ^ k)
in the HashMap.

--------------------------------------

Example:

arr = [4,2,2,6,4]

k = 6

Prefix XORs:

4
6
4
2
6

Whenever:

(previous XOR == xr ^ k)

we found a valid subarray.

Answer = 4

--------------------------------------

Why initialize?

mp[0] = 1

Because if prefix XOR itself equals k,
the subarray starts from index 0.

--------------------------------------

Time Complexity : O(n)

Space Complexity : O(n)

Memory Trick:

For Prefix SUM:
Need
prefixSum - k

For Prefix XOR:
Need
prefixXor ^ k

HashMap stores:
XOR -> Frequency

Don't forget:

mp[0] = 1
*/