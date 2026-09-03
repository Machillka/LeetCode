#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
  public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        // 假设有 1 最坏情况
        const int INF = amount + 1;
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];

                if (j >= coins[i - 1])
                {
                    dp[i][j] = std::min(dp[i][j], dp[i][j - coins[i]] + 1);
                }
            }
        }

        return dp[n][amount] == INF ? -1 : dp[n][amount];
    }
};