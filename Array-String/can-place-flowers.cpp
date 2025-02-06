#include<iostream>
#include<vector>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    if (n == 0)
    {
        return true;
    }
    if (flowerbed.size() == 1)
    {
        if (flowerbed[0] == 0 && n == 1)
        {
            return true;
        }

        return false;
    }

    for (int i = 0; i + 1 < flowerbed.size(); i++)
    {
        if (i > 0 && flowerbed[i - 1] == flowerbed[i] &&
            flowerbed[i] == flowerbed[i + 1])
        {
            flowerbed[i] = !flowerbed[i];
            if (flowerbed[i] == 1)
            {
                n--;
            }
        }
        else if (flowerbed[i] == flowerbed[i + 1] && flowerbed[i] == 0)
        {
            if (i == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
            else if (i == flowerbed.size() - 2)
            {
                flowerbed[i + 1] = 1;
                n--;
            }
        }
    }

    return n <= 0 ? true : false;
}



int main(){
    int n;
    cout<<"Enter the number of flowers: ";
    cin>>n;
    vector<int> flowerbed(n);
    for(int i=0;i<n;i++){
        cin>>flowerbed[i];
    }
    int k;
    cout<<"Enter the number of flowers to be planted: ";
    cin>>k;
    cout<<"Result: ";
    bool result = canPlaceFlowers(flowerbed, k);
    if(result){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}