#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

class Solution
{
  public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<long long, int> prefixCount;

        prefixCount[0] = 1;

        long long sum = 0;
        int ans = 0;

        for (int n : nums)
        {
            sum += n;

            long long need = sum - k;

            ans += prefixCount[need];

            prefixCount[sum]++;
        }

        return ans;
    }
};