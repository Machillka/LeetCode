#include <algorithm>
#include <numeric>
#include <vector>

using std::vector;

class Solution
{
  public:
    int lastStoneWeightII(vector<int>& stones)
    {
        int n = stones.size();

        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                // 不选取第 i 件物品 -> 继承上一次的结果
                // 第 i 件物品: 对应 v/w 数组下标 i - 1
                dp[i][j] = dp[i - 1][j];
                if (j >= stones[i - 1])
                {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                }
            }
        }

        auto best = dp[n][target];

        // (sum - best) - (best) = sum - 2 * best;
        return sum - best * 2;
    }
};