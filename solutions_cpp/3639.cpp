#include <iterator>
#include <set>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution
{
  public:
    int minTime(string s, vector<int>& order, int k)
    {
        const int n = s.size();

        long long total = 1LL * n * (n + 1) / 2;

        if (total < k)
            return -1;

        std::set<int> stars = { -1, n };
        long long valid = 0;
        for (int i = 0; i < n; i++)
        {
            int p = order[i];
            auto rightIt = stars.lower_bound(p);
            int R = *rightIt;
            int L = *std::prev(rightIt);
            valid += 1LL * (p - L) * (R - p);
            stars.insert(p);
            if (valid >= k)
                return i;
        }

        return -1;
    }
};