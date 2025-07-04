// Generate Parentheses using Backtracking
// Time: O(4^n/sqrt(n)), Space: O(n)
// Approach: For each position, we can either place '(' if we haven't used all n
// or place ')' if we have more open than closed parentheses

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(int openN, int closedN, int n, vector<string>& res, string& stack) {
        if (openN == closedN && openN == n) {
            res.push_back(stack);
            return;
        }

        if (openN < n) {
            stack += '(';
            backtrack(openN + 1, closedN, n, res, stack);
            stack.pop_back();
        }
        if (closedN < openN) {
            stack += ')';
            backtrack(openN, closedN + 1, n, res, stack);
            stack.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(0, 0, n, res, stack);
        return res;
    }

int main() {
    int n = 3;
    vector<string> result = generateParenthesis(n);
    
    cout << "All valid parentheses combinations for n = " << n << " are:" << endl;
    for(const string& s : result) {
        cout << s << endl;
    }
    
    return 0;
}