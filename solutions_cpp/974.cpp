#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

class Solution
{
  public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        unordered_map<int, int> prefixModCount;

        prefixModCount[0] = 1;

        int ans = 0;
        int sum = 0;

        for (int n : nums)
        {
            sum = (sum + n) % k;

            if (sum < 0)
            {
                sum += k;
            }

            ans += prefixModCount[sum];

            prefixModCount[sum]++;
        }

        return ans;
    }
};