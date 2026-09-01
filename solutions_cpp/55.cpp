#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
  public:
    /*!
     * @brief 从 index 开始, dfs 所有可以走的路径, 判断是否可以到达 end (index = n - 1)位置
     *
     * @param  index
     * @param  nums
     * @return true
     * @return false
     * @author Machillka (machillka2007@gmail.com)
     * @date 2026-09-01
     */
    bool dfs(int index, const vector<int>& nums)
    {
        if (_visited[index])
            return _canReachEnd[index];

        auto n = static_cast<int>(nums.size());

        if (index == n - 1)
        {
            _canReachEnd[index] = true;
            _visited[index] = true;
            return true;
        }
        int maxReachIndex = std::min(index + nums[index], n - 1);

        for (int i = index + 1; i <= maxReachIndex; i++)
        {
            if (dfs(i, nums))
            {
                _canReachEnd[index] = true;
                _visited[index] = true;
                return true;
            }
        }

        _canReachEnd[index] = false;
        _visited[index] = true;
        return false;
    }

    bool canJump(vector<int>& nums)
    {
        // _canReachEnd.assign(nums.size(), false);
        // _visited.assign(nums.size(), false);
        // return dfs(0, nums);
        return canJump_dp(nums);
    }

    bool canJump_dp(vector<int>& nums)
    {
        int n = nums.size();
        _dp.assign(n, false);

        _dp[n - 1] = true;

        for (int i = n - 2; i >= 0; i--)
        {
            int maxReachDistance = std::min(i + nums[i], n - 1);

            for (int j = i; j <= maxReachDistance; j++)
            {
                if (_dp[j])
                {
                    _dp[i] = true;
                    break;
                }
            }
        }

        return _dp[0];
    }

  private:
    std::vector<bool> _canReachEnd;
    std::vector<bool> _visited;
    std::vector<bool> _dp;
};