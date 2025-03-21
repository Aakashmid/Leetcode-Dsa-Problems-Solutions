#include<iostream>
using namespace std;

class Solution  {
    public:
        int findComplement(int num) {
            int mask = 0;  //
            int n=num;

            if (n == 0) return 1; // Special case: complement of 0 is 1
            while(n!=0){
                mask = (mask << 1) | 1;
                n = n >> 1;
            }
            return ~num & mask;
        }
};

int main(){
    int num;
    cout<<"Enter number ";
    cin>>num;
    Solution s;
    cout<<s.findComplement(num);
    return 0;
}