#include <iostream>
#include <vector>
using namespace std;

int largestAltitude(vector<int> &gain)
{
    int max = 0;
    int sum = 0;
    for (int num : gain)
    {
        sum += num;
        if (sum > max)
        {
            max = sum;
        }
    }
    return max;
}

int main(){
    vector<int> gain = {-4,-3,-2,-1,4,3,2,1};
    cout << largestAltitude(gain);
}