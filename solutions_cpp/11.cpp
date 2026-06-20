#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
  public:
    int maxArea(std::vector<int>& height)
    {
        int left = 0;
        int right = height.size() - 1;
        int ans = -1;

        while (left <= right)
        {
            ans = std::max(ans, (right - left) * std::min(height[left], height[right]));

            if (height[left] <= height[right])
                left++;
            else
                right--;
        }

        return ans;
    }
};

int main()
{
    Solution sol{};

    std::vector<int> height{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };

    std::cout << sol.maxArea(height);

    return 0;
}