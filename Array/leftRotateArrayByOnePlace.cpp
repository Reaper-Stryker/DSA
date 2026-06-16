#include <iostream>
#include <vector>
using namespace std;

// Function to left rotate the array by one position
void leftRotateByOne(vector<int> &arr)
{
    // Edge case: Empty or single element array
    if (arr.size() <= 1)
        return;

    // Store the first element because it will be overwritten.
    int firstElement = arr[0];

    // Shift every element one position to the left.
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = arr[i];
    }

    // Put the original first element at the end.
    arr[arr.size() - 1] = firstElement;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    leftRotateByOne(arr);

    for (int num : arr)
        cout << num << " ";

    return 0;
}

/*
REVISION:

Before: [1 2 3 4 5]

Save 1
Shift left -> [2 3 4 5 _]
Put saved element at end

After: [2 3 4 5 1]

Time: O(n)
Space: O(1)
*/