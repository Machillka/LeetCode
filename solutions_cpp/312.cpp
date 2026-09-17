#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
  public:
    int maxCoins(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> vals(n + 2);
        for (int i = 0; i < n; i++)
        {
            vals[i + 1] = nums[i];
        }

        vals[0] = vals[n + 1] = 1;

        const int m = n + 2;
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; len++)
        {
            for (int l = 0; l + len < m; l++)
            {
                const int r = l + len;
                for (int k = l + 1; k < r; k++)
                {
                    dp[l][r] = std::max(dp[l][r], dp[l][k] + dp[k][r] + vals[l] * vals[k] * vals[r]);
                }
            }
        }

        return dp[0][m - 1];
    }
};