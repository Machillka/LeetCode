#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        ans.push_back(intervals[0]);
        const int n = intervals.size();
        for (int i = 1; i < n; i++)
        {
            int left = intervals[i][0];
            int right = intervals[i][1];

            int currentRangeLeft = ans.back()[1];

            // 说明在区间内
            if (left <= currentRangeLeft)
            {
                ans.back()[1] = std::max(right, ans.back()[1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};