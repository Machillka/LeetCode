#include <algorithm>
#include <limits>
#include <vector>

using std::vector;

class Solution
{
  public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        vector<int> hold(n + 1);
        vector<int> sold(n + 1);
        vector<int> rest(n + 1);

        // 第 0 天
        hold[0] = -prices[0];
        sold[0] = std::numeric_limits<int>::min();
        rest[0] = 0;

        // 递推 1... n - 1 -> 最后一天
        for (int i = 1; i < n; i++)
        {
            hold[i] = std::max(hold[i - 1], rest[i - 1] - prices[i]);
            sold[i] = hold[i - 1] + prices[i];
            rest[i] = std::max(sold[i - 1], rest[i - 1]);
        }

        return std::max(rest[n - 1], sold[n - 1]);
    }
};