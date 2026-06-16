#include <iostream>
#include <vector>
#include <algorithm> // reverse()
using namespace std;

// Function to right rotate the array by k positions
void rightRotateByK(vector<int> &arr, int k)
{
    int n = arr.size();

    if (n == 0)
        return;

    // Handle cases where k > n
    k = k % n;

    // Reverse last k elements
    reverse(arr.end() - k, arr.end());

    // Reverse first n-k elements
    reverse(arr.begin(), arr.end() - k);

    // Reverse entire array
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    rightRotateByK(arr, 3);

    for (int num : arr)
        cout << num << " ";

    return 0;
}

/*
REVISION:

Right Rotate by k

Example:
[1 2 3 4 | 5 6 7]

Reverse last part:
[1 2 3 4 | 7 6 5]

Reverse first part:
[4 3 2 1 | 7 6 5]

Reverse whole:
[5 6 7 1 2 3 4]

Remember:
Reverse Right
Reverse Left
Reverse Whole

Time: O(n)
Space: O(1)
*/