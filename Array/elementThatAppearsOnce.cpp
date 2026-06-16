#include <iostream>
#include <vector>
using namespace std;

// Function to find the element that appears only once
int singleNumber(vector<int> &arr)
{
    // -------------------- INTUITION --------------------
    //
    // XOR has two important properties:
    //
    // 1. a ^ a = 0
    // 2. a ^ 0 = a
    //
    // Since every element appears TWICE except one,
    // all duplicate elements cancel each other.
    //
    // The remaining value is the element that appears once.

    int xorr = 0;

    // XOR all elements of the array
    for (int i = 0; i < arr.size(); i++)
    {
        xorr = xorr ^ arr[i];
    }

    return xorr;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};

    // Only function call
    cout << "Element appearing once: " << singleNumber(arr) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

arr = [4, 1, 2, 1, 2]

XOR all elements:

4 ^ 1 ^ 2 ^ 1 ^ 2

Since:
1 ^ 1 = 0
2 ^ 2 = 0

We get:
4 ^ 0 ^ 0 = 4

Answer = 4

-------------------------
Properties of XOR:

a ^ a = 0
a ^ 0 = a

So duplicate elements cancel out,
leaving only the unique element.

Time Complexity : O(n)
Space Complexity: O(1)

Memory Trick:
"Same numbers vanish in XOR.
Only the lonely (single) number survives."
*/