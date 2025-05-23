#include<iostream>
#include<unordered_set>
using namespace std;

/*
Happy Number
Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy. Otherwise, it is not a happy number.
*/
bool isHappy(int n) {
    int num = n;
    unordered_set<int,bool> num_set ; // for collection of numbers or sum come during find that number is happy or not 
    if(num==1){
        return true;
    }
   
    do {
        int sum = 0;
        int d = 0;
        while (num > 0) {
            d = num % 10;
            num /= 10;
            sum += d * d;
        }
        if (sum == 1) {
            return true;
        } else if(num_set.count(sum)) {   // if cycle is formed then break (same number start repeating)
            break;
        }
        else{
            num_set.insert(sum);
            num=sum;
        }
    } while (num != n);
    return false;
}


// // another approach( two pointer approach , used flyod cycle detection algorithm)
// int digitSquareSum(int n) {
//     int sum = 0, tmp;
//     while (n) {
//         tmp = n % 10;
//         sum += tmp * tmp;
//         n /= 10;
//     }
//     return sum;
// }

// bool isHappy(int n) {
//     int slow, fast;
//     slow = fast = n;
//     do {
//         slow = digitSquareSum(slow);
//         fast = digitSquareSum(fast);
//         fast = digitSquareSum(fast);
//     } while (slow != fast);
//     if (slow == 1)
//         return 1;
//     else
//         return 0;
// }

int main(){
    cout<<isHappy(19);
    return 0;
}