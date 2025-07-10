#include<iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st; // stack for storing indices
                   //  stack<pair<int,int>> st;  // pair stack for both indices and value

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
    }

    return result;
}

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);
    for (int i = 0; i < result.size(); i++)
    {
        cout<< result[i] << " ";
    }
    return 0;
}