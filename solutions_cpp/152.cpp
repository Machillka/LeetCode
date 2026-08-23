#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
  public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        int res = nums[0];

        vector<int> dp_min(n);
        vector<int> dp_max(n);

        dp_min[0] = nums[0];
        dp_max[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            const int x = nums[i];
            const int min_candicate = dp_min[i - 1] * x;
            const int max_candicate = dp_max[i - 1] * x;

            dp_min[i] = std::min({ x, min_candicate, max_candicate });
            dp_max[i] = std::max({ x, min_candicate, max_candicate });

            res = std::max(res, dp_max[i]);
        }

        return res;
    }
};