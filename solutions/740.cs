namespace Problem740;

public class Solution
{
    const int MAXN = 10000;
    public int DeleteAndEarn(int[] nums)
    {
        int[] dp = new int[MAXN + 5];
        int[] counts = new int[MAXN + 5];
        int length = nums.Length;

        // 统计数量作为权重 idx * counts[idx]
        for (int i = 0; i < length; i++)
        {
            counts[nums[i]] += 1;
        }

        // 开始 dp
        dp[0] = 0;
        dp[1] = counts[1];
        int res = -1;

        for (int i = 2; i <= MAXN; i++)
        {
            dp[i] = Math.Max(dp[i - 1], dp[i - 2] + counts[i] * i);
            res = Math.Max(dp[i], res);
        }

        return res;
    }
}