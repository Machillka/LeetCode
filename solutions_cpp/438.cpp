#include <array>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
  public:
    vector<int> findAnagrams(string s, string p)
    {
        const int n = static_cast<int>(s.size());
        const int m = static_cast<int>(p.size());

        if (n < m)
            return {};

        vector<int> ans;

        std::array<int, 26> window_count{};
        std::array<int, 26> p_count{};

        for (int i = 0; i < m; i++)
        {
            ++window_count[s[i] - 'a'];
            ++p_count[p[i] - 'a'];
        }

        if (window_count == p_count)
            ans.push_back(0);

        for (int i = m; i < n; i++)
        {
            --window_count[s[i - m] - 'a'];
            ++window_count[s[i] - 'a'];

            if (window_count == p_count)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};