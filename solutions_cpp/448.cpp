#include <cstdlib>
#include <vector>

using std::vector;

class Solution
{
  public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            const int val = std::abs(nums[i]);
            const int index = val - 1;

            if (nums[index] > 0)
            {
                nums[index] = -nums[index];
            }
        }

        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                res.push_back(i + 1);
        }
        return res;
    }
};