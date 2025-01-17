#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int> &citations)
{
    /********* Brute force approach **************/
    // sort(citations.begin(), citations.end());
    // int h = 0;
    // int n= citations.size();
    // for (int i = 0; i < n; i++) {
    //     for (int j = 1; j <= citations[i]; j++) {
    //         if (j > h && j + i-1 <= n-1) {
    //             h = j;
    //         }
    //     }
    // }
    // return h;

    /********* Optimized  approach **************/
    /*
    here we first create a count array of size n+1, where n is the size of the citations array.
    Then we iterate through the citations array and for each element, we increment the count array at the index corresponding to the element.
    Then we iterate through the count array in reverse order and for each element, we add it to the sum.
    If the sum is greater than or equal to the index, we return the index.
    If no such index is found, we return 0.
    Time complexity: O(n) where n is the size of the citations array
    */

    vector<int> count_arr(citations.size() + 1);
    for (int el : citations) // el - element
    {
        if (el >= count_arr.size())
        {
            count_arr[count_arr.size() - 1]++;
        }
        else
        {
            count_arr[el]++;
        }
    }
    int sum = 0;
    for (int i = count_arr.size() - 1; i >= 0; i--)
    {
        sum += count_arr[i];
        if (sum >= i)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << hIndex(citations);
    return 0;
}