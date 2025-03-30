#include<iostream>
using namespace std;

int hammingWeight(int n) {
    // brute force approach
    // convert n into binary and during process count number of bit 1

    // int res=0;
    // while(n>0){
    //     res+=n%2;
    //     n=n/2;
    // }
    


    // approach 2 (only iterating as least as number of 1 bit)
    int res = 0;
    while(n>0){
        n=n&(n-1);
        res++;
    }
    return res;
}

int main(){
    int n = 11; // binary representation: 1011
    cout << hammingWeight(n) << endl; // Output: 3
    return 0;
}