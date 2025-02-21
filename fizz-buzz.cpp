#include<iostream>
#include<vector>
#include<string>
using namespace std;

/* 
Write a function to print the numbers from 1 to n,
replacing multiples of 3 with "Fizz", 
multiples of 5 with "Buzz", 
and multiples of both 3 and 5 with "FizzBuzz". 
*/
vector<string> fizzBuzz(int n) {
    vector<string> result;
    for (int i = 1; i < n + 1; i++) {
        if (i % 15 == 0) {
            result.push_back("FizzBuzz");
        } else if (i % 3 == 0) {
            result.push_back("Fizz");
        } else if (i % 5 == 0) {
            result.push_back("Buzz");
        } else {
            result.push_back(to_string(i));
        }
    }
    return result;
}


int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<string> result = fizzBuzz(n);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i]<<endl;
        
    }
       
}