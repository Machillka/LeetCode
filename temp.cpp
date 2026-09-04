#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using std::vector;
int main()
{
    vector<int> nums = { 5, 0, 1, 4 };
    int k = 3;

    int n = nums.size();
    vector<int> max_nums(n, std::numeric_limits<int>::min());
    vector<int> min_nums(n, std::numeric_limits<int>::max());

    max_nums[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        max_nums[i] = std::max(nums[i], max_nums[i - 1]);
    }

    min_nums[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        min_nums[i] = std::min(nums[i], min_nums[i + 1]);
    }

    for (int i = 0; i < n; i++)
    {
        const int unstable = max_nums[i] - min_nums[i];
        std::cout << "max_nums[" << i << "]" << "=" << max_nums[i] << '\n';
        std::cout << "min_nums[" << i << "]" << "=" << min_nums[i] << '\n';

        if (unstable <= k)
            return i;
    }

    return -1;
}