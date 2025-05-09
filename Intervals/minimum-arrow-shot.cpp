// Problem: Find minimum number of arrows to burst all balloons
// Approach: Sort by end points and check overlapping intervals
#include <vector>
#include <algorithm>
using namespace std;


int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });
        int count = 1;
        int x = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (x >= points[i][0]) {
                continue;
            }
            x = points[i][1];
            count++;
        }
        return count;
}

int main() {
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    int result = findMinArrowShots(points);
    return 0;
}