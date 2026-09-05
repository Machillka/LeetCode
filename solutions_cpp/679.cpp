#include <cstdlib>
#include <vector>

using std::vector;

class Solution
{
  public:
    static constexpr double EPS = 1e-6;
    bool dfs(const vector<double> remain_nums)
    {
        const int n = remain_nums.size();

        if (n == 1)
            return std::abs(remain_nums[0] - 24.0) < EPS;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                double a = remain_nums[i];
                double b = remain_nums[j];

                vector<double> next_nums;

                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                        continue;
                    next_nums.push_back(remain_nums[k]);
                }

                vector<double> current_res;

                current_res.push_back(a + b);
                current_res.push_back(a - b);
                current_res.push_back(b - a);
                current_res.push_back(a * b);

                // 不能 /0
                if (std::abs(b) > EPS)
                    current_res.push_back(a / b);
                if (std::abs(a) > EPS)
                    current_res.push_back(b / a);

                for (auto x : current_res)
                {
                    next_nums.push_back(x);
                    if (dfs(next_nums))
                        return true;
                    next_nums.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards)
    {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
};