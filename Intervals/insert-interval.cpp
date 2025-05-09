#include<iostream>
#include<vector>
using namespace std;

/*
Problem Statement : You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by start. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by start and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
*/


// time complexity - O(n) , memory complexity - O(n)

// helper function to merge overlapping when inserting new element in result
    void mergeInterval(vector<vector<int>>& result, vector<int> newInterval) {
        if (!result.empty()  && result.back()[1] >= newInterval[0]) {
            result.back()[1] = max(newInterval[1], result.back()[1]);
        } else {
            result.push_back(newInterval);
        }
    }


    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        int j = -1; // flag for checking that newinterval is inserted or not
        int size = intervals.size();

    if(size==0){
        return {newInterval};
    }

        vector<vector<int>> result;
        for (int i = 0; i < size; i++) {
            if (intervals[i][0] > newInterval[0]) {
                mergeInterval(result,newInterval);

                j = i; // point from where now add or merge elements from
                       // inteervals
                break;
            } else {
                result.push_back(intervals[i]);
            }
        }

        if (j != -1) {
            // merge overlapping intervals
            for (int i = j; i < size; i++) {
                mergeInterval(result,intervals[i]);
            }
        } else {
            mergeInterval(result,newInterval);
            
        }

        return result;
    }