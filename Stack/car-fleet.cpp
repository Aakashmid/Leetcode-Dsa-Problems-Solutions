#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    // brute force approach  (iterative way )
    //  vector<pair<int,int>> pair;
    //  for(int i=0 ;i <position.size();i++){
    //     pair.push_back({position[i],speed[i]});
    //  }

    //  sort(pair.rbegin(), pair.rend());  // for sorting in descending order ]

    //  double t = (double)(target -  pair[0].first)/pair[0].second;  //

    //  int carFleets = 1;
    //  for(int i =1;i<pair.size();i++){
    //     double t_curr = (double)(target -  pair[i].first)/pair[i].second;
    //     if(t_curr > t){
    //         t=t_curr;
    //         carFleets++;
    //     }
    //  }

    //  return carFleets;

    // stack approach
    stack<double> stack;  // can also use vector
    vector<pair<int, int>> pair;
    for (int i = 0; i < position.size(); i++)
    {
        pair.push_back({position[i], speed[i]});
    }

    sort(pair.rbegin(), pair.rend());

    for (int i = 0; i < pair.size(); i++)
    {
        double t = (double)(target - pair[i].first) / pair[i].second;
        if (!stack.empty())
        {
            if (stack.top() < t)
            {
                stack.push(t);
            }
        }
        else
        {
            stack.push(t);
        }
    }

    return stack.size();
}

int main()
{
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    cout << carFleet(12, position, speed) << endl;
    return 0;
}