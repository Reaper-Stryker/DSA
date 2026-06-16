#include <iostream>
#include <vector>
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

void findSecondSmallestAndLargest(vector<int> &arr)
{
    // Edge case: At least 2 elements are required
    if (arr.size() < 2)
    {
        cout << "Array should contain at least 2 elements." << endl;
        return;
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int num : arr)
    {
        // ---------------- FIND SECOND LARGEST ----------------

        // If current number is the new largest,
        // shift the old largest to secondLargest.
        if (num > largest)
        {
            secondLargest = largest;
            largest = num;
        }
        // Otherwise, check if it can become secondLargest.
        else if (num > secondLargest && num != largest)
        {
            secondLargest = num;
        }

        // ---------------- FIND SECOND SMALLEST ----------------

        // If current number is the new smallest,
        // shift the old smallest to secondSmallest.
        if (num < smallest)
        {
            secondSmallest = smallest;
            smallest = num;
        }
        // Otherwise, check if it can become secondSmallest.
        else if (num < secondSmallest && num != smallest)
        {
            secondSmallest = num;
        }
    }

    // Print results
    if (secondLargest == INT_MIN)
        cout << "Second Largest does not exist." << endl;
    else
        cout << "Second Largest: " << secondLargest << endl;

    if (secondSmallest == INT_MAX)
        cout << "Second Smallest does not exist." << endl;
    else
        cout << "Second Smallest: " << secondSmallest << endl;
}

int main()
{
    // Sample input
    vector<int> arr = {4, 2, 7, 1, 9, 5, 3};

    // Only function call in main
    findSecondSmallestAndLargest(arr);

    return 0;
}

/*
=========================
REVISION INTUITION
=========================

Maintain four variables:

largest
secondLargest

smallest
secondSmallest

For every element:

1. If it becomes the new largest:
      secondLargest = largest
      largest = current

2. Else if it lies between largest and secondLargest:
      secondLargest = current

Similarly,

1. If it becomes the new smallest:
      secondSmallest = smallest
      smallest = current

2. Else if it lies between smallest and secondSmallest:
      secondSmallest = current

Time Complexity  : O(n)
Space Complexity : O(1)

Key idea:
Whenever a new extreme (largest/smallest) is found,
push the previous extreme into the second position.
*/