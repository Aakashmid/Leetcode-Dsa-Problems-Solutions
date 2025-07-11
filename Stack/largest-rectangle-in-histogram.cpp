// Approach: Using stack to maintain heights in ascending order
// For each bar, calculate area with current bar as smallest height
// by finding left and right boundaries where height becomes smaller
// Time: O(n), Space: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> stack;
        int maxArea = heights[0];
        for (int i = 0; i < heights.size(); i++) {
            int start = i;  // using start for left bounderies for current height
            while (stack.size() != 0 &&
                    stack.back().second > heights[i]) {
                start = stack.back().first; // start index of area with current bar
                                          // height
                int height = stack.back().second; // height of prev bar
                maxArea = max((i - start) * height, maxArea);
                stack.pop_back();
            }
            stack.push_back({start, heights[i]});
        }

        // for finding area of remaing stack elements
        int n = heights.size();
        for (int i = 0; i < stack.size(); i++) {
            maxArea = max((n - stack[i].first) * stack[i].second, maxArea);
        }

        return maxArea;
    }

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Maximum area of rectangle in histogram: " << largestRectangleArea(heights) << endl;
    return 0;
}