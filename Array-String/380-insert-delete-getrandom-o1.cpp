#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
using namespace std;

/************** Brute force approach *****************/
// class RandomizedSet {
// private:
//     set<int> my_set;

// public:
//     RandomizedSet() : my_set() {}

//     bool insert(int val) {
//         if (my_set.find(val) != my_set.end()) {
//             return false;
//         }
//         my_set.insert(val);
//         return true;
//     }

//     bool remove(int val) {
//         if (my_set.find(val) != my_set.end()) {
//             my_set.erase(val);
//             return true;
//         }
//         return false;
//     }

//     int getRandom() {

//         /*** Brute force approach for set ****/
//         random_device rd;
//         mt19937 gen(rd());
//         uniform_int_distribution<> dis(0, my_set.size() - 1);
//         auto it = next(my_set.begin(), dis(gen));
//         return *it;
//     }
// };

/*************** Optimal approach *****************/
class RandomizedSet
{
private:
    vector<int> arr;
    unordered_map<int, int> mp;

public:
    RandomizedSet() {}

    bool isPresent(int val)
    {
        if (mp.find(val) != mp.end())
            return true;
        return false;
    }
    bool insert(int val)
    {
        if (isPresent(val))
        {
            return false;
        }
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (isPresent(val))
        {
            auto it = mp.find(val);
            arr[it->second] = arr.back();
            arr.pop_back();
            mp[arr[it->second]] = it->second;
            mp.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() { return arr[rand() % arr.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    RandomizedSet *obj = new RandomizedSet();
    cout << obj->insert(1) << endl;
    cout << obj->remove(2) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->getRandom() << endl;
    cout << obj->remove(1) << endl;
    cout << obj->insert(2) << endl;
    return 0;
}