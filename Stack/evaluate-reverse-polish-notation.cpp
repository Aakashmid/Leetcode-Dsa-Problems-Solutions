#include <iostream>
#include <vector>
#include <string>
using namespace std;


// function for checking that string is number or not 
bool isNumber(string s)
{
    if (s.length() > 1)
    { // for handling number having more than 1 digit or have -1 sign
        if (isdigit(s[1]))
        {
            return true;
        }
        return false;
    }
    else if (isdigit(s[0]))
    {
        return true;
    }
    return false;
}


/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.
*/ 



/*
approach - 
1 . when we encounter a number we push it into the stack
2. when we encounter an operator we pop the top 2 elements from the stack and perform the operation and push the result back into the stack
3. at the end we return the top element of the stack

*/
int evalRPN(vector<string> &tokens)
{
    vector<int> stack;
    int n = 0;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (isNumber(tokens[i]))
        {
            n = stoi(tokens[i]);
            stack.push_back(n);
        }

        // handling when the operator comes
        else
        {
            int firstTop = stack.back();
            stack.pop_back();
            int secondTop = stack.back();
            stack.pop_back();
            if (tokens[i] == "+")
            {
                stack.push_back(firstTop + secondTop);
            }
            else if (tokens[i] == "-")
            {
                stack.push_back(secondTop - firstTop);
            }
            else if (tokens[i] == "/")
            {
                stack.push_back(secondTop / firstTop);
            }
            else if (tokens[i] == "*")
            {
                stack.push_back(secondTop * firstTop);
            }
        }
    }
    return stack.back();
}

int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << evalRPN(tokens);
    return 0;
}