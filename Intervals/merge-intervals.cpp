#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Sort intervals by start time
// If current interval overlaps with previous merged interval, update end time
// Otherwise add current interval to result
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());

    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        if (result.back()[1] >= intervals[i][0]) {
            result.back()[1] = max(intervals[i][1], result.back()[1]);
        } else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}
int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> merged = merge(intervals);
    for (auto interval : merged) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}