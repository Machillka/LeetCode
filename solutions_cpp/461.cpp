class Solution
{
  public:
    int hammingDistance(int x, int y)
    {
        int allBits = x ^ y;
        int ans = 0;

        while (allBits)
        {
            ans += allBits & 1;
            allBits >>= 1;
        }

        return ans;
    }
};