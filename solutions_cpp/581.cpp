#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
  public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int n = nums.size();

        int right = -1;
        int maxVal = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < maxVal)
                right = i;

            maxVal = std::max(maxVal, nums[i]);
        }

        // 整个数组已经是递增序列
        if (right == -1)
            return 0;

        int left = n - 1;
        int minVal = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > minVal)
                left = i;

            minVal = std::min(minVal, nums[i]);
        }

        return right - left + 1;
    }
};