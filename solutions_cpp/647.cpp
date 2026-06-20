#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
  public:
    int countSubstrings(string s)
    {
        string t = "^";

        for (char c : s)
        {
            t += "#";
            t += c;
        }

        t += "#$";

        int n = t.size();
        vector<int> p(n, 0);

        int center = 0;
        int right = 0;
        int ans = 0;

        for (int i = 1; i < n - 1; i++)
        {
            int mirror = center * 2 - i;

            // 在边界内, 可以复用旧的信息
            if (i < right)
            {
                p[i] = std::min(p[mirror], right - i);
            }

            // 左 = 右
            while (t[i - p[i] - 1] == t[i + p[i] + 1])
            {
                p[i]++;
            }

            if (i + p[i] > right)
            {
                right = i + p[i];
                center = i;
            }

            ans += (p[i] + 1) / 2;
        }

        return ans;
    }
};