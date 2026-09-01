#include <deque>
#include <vector>
using std::vector;

class Solution
{
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n = nums.size();

        std::deque<int> q;
        std::vector<int> ans;
        ans.reserve(n - k + 1);
        for (int i = 0; i < n; i++)
        {
            while ((!q.empty()) && nums[q.back()] <= nums[i])
                q.pop_back();

            q.push_back(i);

            while ((!q.empty()) && q.front() < i - k + 1)
                q.pop_front();

            if (i + 1 >= k)
                ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};