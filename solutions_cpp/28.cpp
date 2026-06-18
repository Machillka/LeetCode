#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        // 使用 kmp
        vector<int> pi(needle.size(), 0);
        int n = haystack.size();
        int m = needle.size();

        int j = 0;
        for (int i = 1; i < m; i++)
        {
            while (j > 0 && needle[i] != needle[j])
            {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j])
                j++;
            pi[i] = j;
        }

        j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j > 0 && haystack[i] != needle[j])
                j = pi[j - 1];

            if (haystack[i] == needle[j])
                j++;

            // 匹配成功
            if (j == m)
                return i - m + 1;
        }

        return -1;
    }
};