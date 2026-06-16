#include <iostream>
#include <vector>
using namespace std;

// Function to right rotate the array by one position
void rightRotateByOne(vector<int> &arr)
{
    if (arr.size() <= 1)
        return;

    // Save the last element.
    int lastElement = arr[arr.size() - 1];

    // Shift every element one position to the right.
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }

    // Put the saved last element at the beginning.
    arr[0] = lastElement;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    rightRotateByOne(arr);

    for (int num : arr)
        cout << num << " ";

    return 0;
}

/*
REVISION:

Before: [1 2 3 4 5]

Save 5
Shift right -> [_ 1 2 3 4]
Put saved element at front

After: [5 1 2 3 4]

Time: O(n)
Space: O(1)
*/