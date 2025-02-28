#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> myStack;
    unordered_map<char,char> pairs={{'}','{'},{')','('},{']','['}}; // 
    for(char ch :s ){
        if(pairs.count(ch) && myStack.empty()){  // if reverse bracket than it is invalid
            return false;
        }
        else{
            if(!pairs.count(ch)){
                myStack.push(ch);
            }
            else if( myStack.top()==pairs[ch]){  // only pop when its a part of pairs
                myStack.pop();
            }
            else{
                return false;
            }
        }
    }
    return myStack.size()==0;
}

int main(){
    string s = "()[]{}";
    cout<<isValid(s);
    return 0;
}