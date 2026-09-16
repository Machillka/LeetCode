#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using std::vector;

class Solution
{
  public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // val -> count
        std::unordered_map<int, int> count_map;
        for (auto val : nums)
        {
            ++count_map[val];
        }

        // count -> value, 由于可能存在重复 count 的 value, 所以使用嵌套说明
        // 保证 count > 0 所以下标属于 (0, nums.size()]
        std::vector<vector<int>> bucket(nums.size() + 1);

        for (auto [val, count] : count_map)
        {
            bucket[count].push_back(val);
        }

        std::vector<int> res;

        for (int freq = nums.size(); freq >= 0; freq--)
        {
            const auto current_bucket = bucket[freq];

            for (auto val : current_bucket)
            {
                res.push_back(val);
                --k;

                if (k == 0)
                    return res;
            }
        }

        return res;
    }
};