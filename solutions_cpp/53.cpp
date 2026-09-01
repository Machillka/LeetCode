#include <algorithm>
#include <vector>
using std::vector;

class Solution
{
  public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.size() <= 0)
            return 0;

        int n = nums.size();

        vector<int> dp(n);
        dp[0] = nums[0];

        int res = nums[0];

        for (int i = 1; i < n; i++)
        {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
            res = std::max(dp[i], res);
        }

        return res;
    }
};