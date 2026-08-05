#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
  public:
    static vector<int> buildPi(const string& p)
    {
        vector<int> pi(p.size(), 0);
        int j = 0;

        for (int i = 1; i < p.size(); ++i)
        {
            while (j > 0 && p[i] != p[j])
            {
                j = pi[j - 1];
            }

            if (p[i] == p[j])
            {
                ++j;
            }

            pi[i] = j;
        }

        return pi;
    }
    string longestPrefix(string s)
    {
        vector<int> pi = buildPi(s);
        return s.substr(0, pi.back());
    }
};