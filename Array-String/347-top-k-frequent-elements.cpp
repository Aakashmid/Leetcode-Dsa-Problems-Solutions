#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// bucket sort approach to find top k frequent elements

vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
          approach - 
          1. First count frequency of each element using hashmap
          2. Create a bucket array where index represents frequency count
            and value is array of elements having that frequency
          3. Each index i will contain list of numbers that appeared i times in array
          4. Traverse bucket array from end (highest frequency) to start
          5. Add elements to result until we get k elements
          6. This gives us k most frequent elements in O(n) time
        */
        unordered_map<int, int> count;
        vector<vector<int>> freqs(nums.size() + 1);
        for (int num : nums) {  // count frequency of each element 
            count[num]++;
        }

        for (const auto& pair : count) {  // create bucket
            freqs[pair.second].push_back(pair.first);
        }

        vector<int> res;
        for (int i = freqs.size() - 1; i > 0; i--) {
            for (int n : freqs[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    
    vector<int> result = topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements are: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}