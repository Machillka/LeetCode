#include <vector>
using std::vector;
class Solution
{
  public:
    int robRange(vector<int>& nums, int left, int right)
    {
        if (left == right)
            return nums[left];

        int prev2 = nums[left];
        int prev1 = std::max(nums[left], nums[left + 1]);

        for (int i = left + 2; i <= right; i++)
        {
            int current = std::max(prev1, prev2 + nums[i]);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    int rob(vector<int>& nums)
    {
        const int n = nums.size();

        if (n == 1)
            return nums[0];

        return std::max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};