#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;

        int n = nums.size();

        // dp[i]: 表示 以 nums[i] 为结尾的 LIS
        vector<int> dp(n);
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;

            for (int j = 0; j < i; j++)
            {
                // 取, 则接到后面
                if (nums[i] > nums[j])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                    ans = std::max(ans, dp[i]);
                }
            }
        }

        return ans;
    }
};