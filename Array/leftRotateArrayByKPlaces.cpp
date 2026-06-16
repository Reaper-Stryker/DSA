#include <iostream>
#include <vector>
#include <algorithm> // reverse()
using namespace std;

// Function to left rotate the array by k positions
void leftRotateByK(vector<int> &arr, int k)
{
    int n = arr.size();

    if (n == 0)
        return;

    // Handle cases where k > n
    k = k % n;

    // Reverse first k elements
    reverse(arr.begin(), arr.begin() + k);

    // Reverse remaining elements
    reverse(arr.begin() + k, arr.end());

    // Reverse entire array
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    leftRotateByK(arr, 3);

    for (int num : arr)
        cout << num << " ";

    return 0;
}

/*
REVISION:

Left Rotate by k

Example:
[1 2 3 | 4 5 6 7]

Reverse first part:
[3 2 1 | 4 5 6 7]

Reverse second part:
[3 2 1 | 7 6 5 4]

Reverse whole:
[4 5 6 7 1 2 3]

Remember:
Reverse Left
Reverse Right
Reverse Whole

Time: O(n)
Space: O(1)
*/