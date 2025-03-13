#include<iostream>
using namespace std;

// in this problem we have to find  a number which occure only once 
// size of array is n = 2m+1 means it is even , and m numbers are twice an 1 is unique

int main(){
    int arr[] = {4, 3, 2, 4, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans = ans^arr[i];   // same elements xor will cancel out , only unique will  remain 
    }
    cout<<ans<<endl;

    return 0;
}