/*
Approach:
1. Use stack to handle parentheses
2. Keep track of current number, sign and running answer
3. For each character:
   - If digit: form complete number
   - If +/-: update sign
   - If '(': push current ans and sign to stack, reset ans
   - If ')': pop previous ans and sign, combine with current ans
*/

// time complexity : O(n)
// space complexity : O(n)
#include<iostream>
#include<vector>
using namespace std;


int calculate(string s) {
        int ans=0;
        int sign = 1;
        int currNo=0;

        vector<int> stack;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                currNo=s[i++]-'0';
                while(isdigit(s[i])){
                    currNo=(currNo*10)+(s[i]-'0');
                    i++;
                }
                ans+=currNo*sign;

            }
            if(s[i]=='+'){
                sign=1;
            }
            else if(s[i]=='-'){
                sign=-1;
            }
            else if(s[i]=='('){
                stack.push_back(ans);
                stack.push_back(sign);
                ans=0;
                sign=1;
            }
            else if(s[i]==')'){
                int prevSign = stack.back();
                stack.pop_back();
                int prevAns = stack.back();
                stack.pop_back();

                ans = (ans*prevSign) + prevAns;
                sign=1;
            }
            else{
                continue;
            }
        }
        return ans;
    }

int main(){
    string s = "1+1";
    cout<<calculate(s);
    return 0;
}