namespace Problem1513
{
	public class Solution
	{
		const int MOD = 1000000007;
		public static int NumSub(string s)
		{
			long ans = 0;
			int n = s.Length;

			for (int i = 0; i < n; i++)
			{
				long cnt = 0;
				while (i < n && s[i] == '1')
				{
					cnt += 1;
					i++;
				}
				ans += (cnt + 1) * cnt / 2;
				ans %= MOD;
			}

			return (int)ans;
		}
	}
}
