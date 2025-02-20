#include <iostream>
#include <vector>
using namespace std;

/*
give candy to children based on their rating , if rating is higher than left or right child then give more candy than their neighbour
*/
int candy(vector<int> &ratings)
{

    int num_candies = 0;
    int n = ratings.size();
    vector<int> candies(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1] && candies[i - 1] >= candies[i])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = ratings.size() - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
        {
            candies[i] = candies[i + 1] + 1;
        }
    }
    for (int n : candies)
    {
        num_candies += n;
    }

    return num_candies;



    // int n = ratings.size();
    // int candy = n, i=1;
    // while(i<n){
    //     if(ratings[i] == ratings[i-1]){
    //         i++;
    //         continue;
    //     }
        
    //     //For increasing slope
    //     int peak = 0;
    //     while(ratings[i] > ratings [i-1]){
    //         peak++;
    //         candy += peak;
    //         i++;
    //         if(i == n) return candy;
    //     }
        
    //     //For decreasing slope
    //     int valley = 0;
    //     while(i<n && ratings[i] < ratings[i-1]){
    //         valley++;
    //         candy += valley;
    //         i++;
    //     }
    //     candy -= min(peak, valley); //Keep only the higher peak
    // }
    // return candy;
}

int main()
{
    int n;
    cout << "Enter the number of children: ";
    cin >> n;
    vector<int> ratings(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ratings[i];
    }
    cout << candy(ratings); // get total number of candies
    return 0;
}