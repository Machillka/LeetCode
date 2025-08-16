namespace Problem120
{
  	public class Solution
	{
		public int MinimumTotal(IList<IList<int>> triangle)
		{
			int[,] dp = new int[triangle.Count + 1, triangle.Count + 1];
			dp[0, 0] = triangle[0][0];

			int res = triangle[0][0];

			for (int i = 1; i < triangle.Count; i++)
			{
				int currentLength = triangle[i].Count;
				// 第一列
				dp[i, 0] = dp[i - 1, 0] + triangle[i][0];
				res = dp[i, 0];
				for (int j = 1; j < currentLength - 1; j++)
				{
					dp[i, j] = Math.Min(dp[i - 1, j], dp[i - 1, j - 1]) + triangle[i][j];

					res = Math.Min(res, dp[i, j]);
				}
				// 最后一列
				dp[i, currentLength - 1] = dp[i - 1, currentLength - 2] + triangle[i][currentLength - 1];
				res = Math.Min(res, dp[i, currentLength - 1]);
			}

			return res;
		}
	}
}
