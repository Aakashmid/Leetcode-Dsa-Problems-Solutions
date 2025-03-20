#include<iostream>
using namespace std;


// reverse the binary bits of a number
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++)
        result = (result << 1) + (n >> i & 1);  // used & 1 to get ith bit 
        // result = result  | ((n >> i & 1) << (31-i));

    return result;
}


int main(){
    uint32_t n = 43261596;
    cout << reverseBits(n) << endl;
    return 0;
}