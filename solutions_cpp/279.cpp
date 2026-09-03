#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
  public:
    int numSquares(int n)
    {
        // 构造完全平方表
        vector<int> nums;
        for (int i = 1; i * i <= n; i++)
        {
            nums.push_back(i * i);
        }

        const int INF = n + 1;
        int size = nums.size();
        // [i][j]: 使用前 i 个 完全平方数, 组成 j 所需要的最少数组
        vector<vector<int>> dp(size + 1, vector<int>(n + 1, INF));

        // 组成 0 不需要数字
        for (int i = 0; i <= size; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= size; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1])
                {
                    dp[i][j] = std::min(dp[i][j], dp[i][j - nums[i - 1]] + 1);
                }
            }
        }

        return dp[size][n];
    }
};