#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to find maximum points that lie on the same straight line
    int maxPoints(vector<vector<int>> &points)
    {
        // Get the total number of points
        int n = points.size();

        // If points are less than or equal to 2, return the number of points
        if (n <= 2)
            return n;

        int maxPointsOnLine = 2; // Initialize with minimum 2 points

        // Iterate through each point as a reference point
        for (int i = 0; i < n - 1; i++)
        {
            // Hash map to store slope and count of points with that slope
            unordered_map<double, int> slopeCount;

            // Calculate slope with reference point and all other points
            for (int j = i + 1; j < n; j++)
            {
                double slope;
                // Handle vertical line case (infinite slope)
                if (points[j][0] == points[i][0])
                {
                    slope = numeric_limits<double>::infinity();
                }
                else
                {
                    // Calculate slope using the formula (y2-y1)/(x2-x1)
                    slope = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);
                }

                // Increment count for this slope
                if (slopeCount.count(slope))
                {
                    slopeCount[slope]++;
                }
                else
                {
                    slopeCount[slope] = 1;
                }

                // Find maximum points for current reference point
                int currentMax = 0;
                for (auto it : slopeCount)
                {
                    if (currentMax < it.second + 1)
                        currentMax = it.second + 1;
                }
                if (maxPointsOnLine < currentMax)
                    maxPointsOnLine = currentMax;
            }
        }
        return maxPointsOnLine;
    }
};

int main()
{
    Solution s;
    // Test case: Points forming a straight line
    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
    cout << s.maxPoints(points) << endl;
    return 0;
}