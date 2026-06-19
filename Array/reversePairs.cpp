#include <iostream>
#include <vector>
using namespace std;

// Function to count reverse pairs across two sorted halves
int countPairs(vector<int> &arr, int low, int mid, int high)
{
    // -------------------- INTUITION --------------------
    //
    // Left half  : arr[low ... mid]
    // Right half : arr[mid+1 ... high]
    //
    // Both halves are already sorted.
    //
    // For each element in the left half,
    // find how many elements in the right half satisfy:
    //
    // arr[left] > 2 * arr[right]
    //
    // Since both halves are sorted,
    // the right pointer only moves forward.

    int right = mid + 1;
    int cnt = 0;

    for (int left = low; left <= mid; left++)
    {
        while (right <= high &&
               (long long)arr[left] > 2LL * arr[right])
        {
            right++;
        }

        cnt += (right - (mid + 1));
    }

    return cnt;
}

// Standard merge function
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;

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

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
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

    // Count reverse pairs before merging
    cnt += countPairs(arr, low, mid, high);

    // Merge the two sorted halves
    merge(arr, low, mid, high);

    return cnt;
}

// Function to count reverse pairs
int reversePairs(vector<int> &arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {1, 3, 2, 3, 1};

    // Only function call
    cout << "Reverse Pairs: "
         << reversePairs(arr);

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Reverse Pair:

i < j

AND

arr[i] > 2 * arr[j]

--------------------------------------

Brute Force:

Check every pair.

Time = O(n²)

--------------------------------------

Optimal:

Use Merge Sort.

Left Half:
Sorted

Right Half:
Sorted

For every left element:

Move right pointer until:

arr[left] <= 2 * arr[right]

Then,

count += right - (mid + 1)

--------------------------------------

Example:

Left:

[4, 5]

Right:

[1, 2]

For 4:

4 > 2*1

4 > 2*2 ? No

Count = 1

For 5:

Continue from same right pointer.

Total count computed efficiently.

--------------------------------------

IMPORTANT:

Use long long:

(long long)arr[left] > 2LL * arr[right]

Otherwise integer overflow
may occur.

--------------------------------------

Time Complexity :

O(n log n)

Space Complexity :

O(n)

Memory Trick:

Exactly like Count Inversions,

but condition changes to:

arr[left] > 2 * arr[right]

Count BEFORE merging.
*/