#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
  public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        std::vector<vector<int>> dp(2, std::vector<int>(n + 1, 0));

        dp[0][0] = 0;
        dp[1][0] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            dp[0][i] = std::max(dp[1][i - 1] + prices[i], dp[0][i - 1]);
            dp[1][i] = std::max(dp[0][i - 1] - prices[i], dp[1][i - 1]);
        }

        return std::max(dp[0][n - 1], dp[1][n - 1]);
    }
};