#include<iostream>
using namespace std;


/*
Approach:
1. Find the common prefix of binary representation of left and right numbers
2. Keep right shifting both numbers until they become equal
3. Count the number of shifts needed
4. Left shift the final number by count to get the result
5. This works because all numbers in range will have same common prefix
   and rest bits will be different, so AND of all will have 0 in different bits

Time Complexity: O(log n) where n is the maximum number of bits
Space Complexity: O(1)
*/
int rangeBitwiseAnd(int left, int right) {
    int count =0;
    while(left!=right){
        left = left >>1;
        right = right >>1;
        count++;
    }
    return left<<count;
}

int main(){
    int left = 5, right = 7;
    cout << rangeBitwiseAnd(left,right) << endl;
    return 0;
}