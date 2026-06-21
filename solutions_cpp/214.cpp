#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
  public:
    vector<int> buildPi(string s)
    {
        vector<int> pi(s.size(), 0);

        int j = 0;
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j])
            {
                j = pi[j - 1];
            }

            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }

        return pi;
    }
    string shortestPalindrome(string s)
    {
        string rev = s;

        std::reverse(rev.begin(), rev.end());

        // 倒着加上去 跑一边 kmp 从相同的前后缀 -> 回文串
        string t = s + "$" + rev;

        vector<int> pi = buildPi(t);

        int longestPrefixLen = pi.back();

        string rest = s.substr(longestPrefixLen);
        std::reverse(rest.begin(), rest.end());

        return rest + s;
    }
};  