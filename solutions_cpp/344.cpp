#include <utility>
#include <vector>
using std::vector;

class Solution
{
  public:
    void reverseString(vector<char>& s)
    {
        int n = s.size();
        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            std::swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};