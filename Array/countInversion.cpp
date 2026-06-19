#include <iostream>
#include <vector>
using namespace std;

// Merge function that also counts inversions
int merge(vector<int> &arr, int low, int mid, int high)
{
    // -------------------- INTUITION --------------------
    //
    // Left part  = arr[low ... mid]
    // Right part = arr[mid+1 ... high]
    //
    // Both parts are already sorted.
    //
    // If arr[left] <= arr[right]:
    //      No inversion.
    //
    // Else:
    //      arr[left] > arr[right]
    //
    // Since left half is sorted,
    // ALL elements from left to mid
    // will also be greater than arr[right].
    //
    // Number of inversions:
    //
    // (mid - left + 1)

    vector<int> temp;

    int left = low;
    int right = mid + 1;

    int cnt = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);

            // Count inversions
            cnt += (mid - left + 1);

            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

// Merge Sort function
int mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;

    int cnt = 0;

    cnt += mergeSort(arr, low, mid);

    cnt += mergeSort(arr, mid + 1, high);

    cnt += merge(arr, low, mid, high);

    return cnt;
}

// Function to count inversions
int countInversions(vector<int> &arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};

    // Only function call
    cout << "Number of Inversions: "
         << countInversions(arr);

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Definition:

An inversion is:

i < j

and

arr[i] > arr[j]

--------------------------------------

Brute Force:

Check every pair.

Time:

O(n²)

--------------------------------------

Optimal:

Use Merge Sort.

During merge:

Left Half:
Sorted

Right Half:
Sorted

If

arr[left] <= arr[right]

No inversion.

Else

arr[left] > arr[right]

Then ALL remaining elements
from left to mid

also form inversions.

Count:

(mid - left + 1)

--------------------------------------

Example:

Left:

3 5

Right:

1 2

When comparing:

3 > 1

Inversions:

(3,1)
(5,1)

Count += 2

--------------------------------------

Time Complexity:

O(n log n)

Space Complexity:

O(n)

Memory Trick:

Merge Sort +
Count during Merge.

Whenever:

Left > Right

Add:

(mid - left + 1)
*/