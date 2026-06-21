#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to check if allocation is possible
bool canAllocateBooks(vector<int> &books, int students, int maxPages)
{
    /*
    Greedily assign books to the current student.

    If adding the next book exceeds maxPages,
    allocate it to a new student.

    If the number of students required is
    <= given students, then allocation is possible.
    */

    int studentCount = 1;
    int pagesAllocated = 0;

    for (int pages : books)
    {
        if (pagesAllocated + pages <= maxPages)
        {
            pagesAllocated += pages;
        }
        else
        {
            studentCount++;
            pagesAllocated = pages;

            if (studentCount > students)
                return false;
        }
    }

    return true;
}

// Function to find the minimum possible maximum pages
int allocateBooks(vector<int> &books, int students)
{
    /*
    =========================
    STRIVER'S INTUITION
    =========================

    We have to allocate books such that:
    1. Every student gets at least one book.
    2. Books are allocated contiguously.
    3. Minimize the maximum pages assigned
       to any student.

    Observation:
    - If a maximum limit X works,
      then any value > X will also work.
    - If X doesn't work,
      then any value < X also won't work.

    This is a monotonic property,
    so we Binary Search on the answer.

    Search Space:
    - Minimum possible answer =
          maximum pages in a single book.
    - Maximum possible answer =
          sum of all pages
          (one student gets all books).

    Binary Search:
    - If allocation is possible with mid pages,
      store answer and search LEFT.
    - Otherwise,
      search RIGHT.
    */

    int n = books.size();

    // Impossible case
    if (students > n)
        return -1;

    int low = *max_element(books.begin(), books.end());

    int high = 0;
    for (int pages : books)
        high += pages;

    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canAllocateBooks(books, students, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> books = {25, 46, 28, 49, 24};
    int students = 4;

    cout << "Minimum Possible Maximum Pages = "
         << allocateBooks(books, students) << endl;

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Example:

books = [25, 46, 28, 49, 24]
students = 4

Try maxPages = 60

Student 1 -> 25
Student 2 -> 46
Student 3 -> 28
Student 4 -> 49
24 cannot be added to Student 4,
so need Student 5.

Not possible.

Increase maxPages.

--------------------------------------

Try maxPages = 71

Student 1 -> 25 + 46 = 71
Student 2 -> 28
Student 3 -> 49
Student 4 -> 24

Possible.

Try a smaller answer.

--------------------------------------

Eventually,
Minimum Possible Maximum Pages = 71.

--------------------------------------

Edge Case:

books = [10, 20]
students = 3

More students than books.

Impossible.

Return -1.

--------------------------------------

Time Complexity:
O(n * log(sum(books)))

where:
n = number of books

Space Complexity:
O(1)

Memory Trick:

1. Binary Search on the ANSWER
   (maximum pages assigned).

2. low = maximum book pages.

3. high = sum of all book pages.

4. Greedily allocate books.

5. If allocation is possible:
      save answer and move LEFT.
   Else:
      move RIGHT.

6. Always check:
      if (students > books.size())
          return -1;
*/