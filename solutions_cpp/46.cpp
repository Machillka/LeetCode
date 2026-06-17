#include <utility>
#include <vector>
using std::vector;

class Solution
{
  public:
    void backtrack(vector<vector<int>>& result, vector<int>& current, int start)
    {
        if (start == current.size())
        {
            result.emplace_back(current);
            return;
        }

        /*
         * 思路不是从所有数字中挑一个没用过的
         * 而是依次填每一个位置
         * 这样在 Start 之前就是已经填写完的不可变元素
         * 所以只需要在 Start 之后的元素中进行迭代即可
         */
        for (int i = start; i < current.size(); i++)
        {
            std::swap(current[i], current[start]);
            backtrack(result, current, start + 1);
            std::swap(current[i], current[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }
};