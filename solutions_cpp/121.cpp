#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
  public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        int ans = 0;
        int minBuyin = prices[0];
        for (int i = 0; i < n; i++)
        {
            ans = std::max(ans, prices[i] - minBuyin);
            minBuyin = std::min(minBuyin, prices[i]);
        }

        return ans;
    }
};