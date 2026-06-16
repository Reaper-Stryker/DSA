#include <iostream>
#include <vector>
using namespace std;

// Function to find the missing number using XOR
int missingNumber(vector<int> &arr)
{
    int n = arr.size();

    // xor1 -> XOR of numbers from 1 to n
    // xor2 -> XOR of elements present in the array
    int xor1 = 0;
    int xor2 = 0;

    // Traverse only once
    for (int i = 0; i < n; i++)
    {
        xor2 = xor2 ^ arr[i];   // XOR of array elements
        xor1 = xor1 ^ (i + 1);  // XOR of numbers 1 to n
    }

    // Missing number = XOR of above two values
    return xor1 ^ xor2;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5}; // Missing number is 3

    // Only function call
    cout << "Missing Number: " << missingNumber(arr) << endl;

    return 0;
}

/*
=========================
INTUITION
=========================

Array contains numbers from 1 to n,
with exactly one number missing.

Example:
arr = [1, 2, 4, 5]
n = 5

xor1 = 1 ^ 2 ^ 3 ^ 4 ^ 5
xor2 = 1 ^ 2 ^ 4 ^ 5

Answer = xor1 ^ xor2

Why?
Because:
a ^ a = 0
0 ^ b = b

So,
(1^2^3^4^5) ^ (1^2^4^5)
= 3

Time Complexity : O(n)
Space Complexity: O(1)

Memory Trick:
XOR all expected numbers.
XOR all given numbers.
Common numbers cancel out.
The remaining value is the missing number.
*/