#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//Question Description
/*
You are given an unordered array consisting of consecutive integers  [1, 2, 3, ..., n] without any duplicates. You are allowed to swap any two elements. 
You need to find the minimum number of swaps required to sort the array in ascending order.

For example, given the array  we perform the following steps:

i   arr                     swap (indices)
0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
5   [1, 2, 3, 4, 5, 6, 7]
It took 5 swaps to sort the array.*/

//Problem Setter's Description
/*
1) The idea is that if a occupies b's position, b occupies c's position and so on, then there will be some integer x which will occupy  position. So, this forms a cycle.
2) So, if any element arr, is not at its correct position, we shift it to its correct position j, then shift arr[j] to its correct position k and so on.
So, if len is the length of the cycle (number of elements in the cycle), then it will require a minimum of len - 1 swaps to rearrange the elements of the cycle to their correct positions.
3)We find all such cycles and compute our answer. 
The correct positions of all the elements can be found by sorting the array by value and keeping track of the old and new positions.
*/

//Problem Setter's Solution
#if 0
#include<bits/stdc++.h>
using namespace std;

int a[100005];
bool visited[100005];

int solve(int n)
{
    pair<int, int> p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].first = a[i];

        // Storing the original position of a[i]
        p[i].second = i;
    }

    sort(p, p + n);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        //visited[i]=true indicates that index i belongs to a cycle that is already counted

        //p[i].second = i denotes that the ith element was at its correct position

        if (visited[i] || p[i].second == i)
            continue;

        int cycle_size = 0;
        int j = i;

        //Counting the size of the cycle
        while (!visited[j])
        {
            visited[j] = 1;
            j = p[j].second;
            cycle_size++;
        }

        ans += (cycle_size - 1);
    }

    return ans;

}
#endif
//Solution Explanation
/*
The question tells us that the array will always finish with the lowest value in the first element of the array. So the first loop keeps track of the exact
indices in the array we are on and the inner while loop states whilst we do not have the correct element in this array go through and find it once found
swap its position with the value in its correct place. 

The swapping works like so, if the value in the current element of the array is wrong, put that value in its correct element in the array, swapping with that 
value in its place. Check the value in the current element, if it is still wrong, repeat until the correct value is in that element. Once it is iterated and moved 
to the next element in the array. 

[3 2 4 1 5]

Element 0 in the array represents value 3, so put that in value in its correct element, which is element 2. The current value in element 2 is value 4 so they swap.

[4 2 3 1 5]

Checking again in element 0, the wrong element is in that place so put the current value in its correct element, which is element 3.

[1 2 3 4 5]

Checking again at element 0, however this time the value is correct so the loop moves onto index 1 and keeps cycling through to the end because the array is now in ascending order.
*/
#if 1
int minimumSwaps(std::vector<int> arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        while (arr[i] != i + 1) {
            int temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
            count++;
        }
    }
    return count;

}
#endif


int main()
{
    
    int n;
    std::cout << "Length of array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    for (int arr_i = 0; arr_i < n; arr_i++) {
        std::cout << "Value at " << arr_i << " element in the array is: ";
        std::cin >> arr[arr_i];
    }

    int res = minimumSwaps(arr);
    
    std::cout << "\nThe number of minimum swaps is: " << res << std::endl;
    
    return 0;
}

