#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;
class Solution
{
  public:
    bool canPartition(vector<int>& nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;

        int totalWeight = sum >> 1;
        int n = nums.size();

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(totalWeight + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= totalWeight; j++)
            {
                if (j >= nums[i - 1])
                {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
                    if (dp[i][j] == totalWeight)
                        return true;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return false;
    }
};