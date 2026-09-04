#include <vector>

using std::vector;

class Solution
{
  public:
    int ans = 0;
    void dfs(vector<int>& nums, int i, int target, int sum)
    {
        const int n = nums.size();
        if (i > n)
            return;
        if (i == n)
        {
            if (sum == target)
                ++ans;
            return;
        }

        dfs(nums, i + 1, target, sum + nums[i]);
        dfs(nums, i + 1, target, sum - nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target)
    {
        dfs(nums, 0, target, 0);
        return ans;
    }
};