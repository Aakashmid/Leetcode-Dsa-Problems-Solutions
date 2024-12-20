#include<iostream>
using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        // work for small input (not efficient for large inputs)
        // if(n==0)
        //     return 1;
        // else if (n<0)
        //     return 1/myPow(x,-n);
        // else 
        //     return x*myPow(x,n-1);


        // double result = 1.0;
        // long long counter = n; // Use long long to handle INT_MIN case
        // if (n < 0) {
        //     x = 1 / x;
        //     counter = -counter;
        // }
        // while (counter > 0) {
        //     if (counter % 2 == 1) {
        //         result *= x;
        //     }
        //     x *= x;
        //     counter /= 2;
        // }        
        // return result;


        long long N = n;
        if(N==0){
            return 1;
        }
        else if(N<0){
            N= abs(N);
            x=1/x;
        } 
        
        if(N%2==0){
            return myPow(x*x,N/2);
        }
        else{
            return x*myPow(x,N-1);
        }

    }
};

int main(){
    Solution obj;
    // double x ;
    // int n ;
    // cin>> x;
    // cin>>n;
    // cout<<obj.myPow(x,n);
    cout<<obj.myPow(23,12300000);
    return 0;
}