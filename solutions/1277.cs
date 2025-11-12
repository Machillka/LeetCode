namespace Problem1277
{
	public class Solution
	{
		public int CountSquares(int[][] matrix)
		{
			if (matrix == null || matrix.Length == 0)
				return 0;
			int m = matrix.Length;
			int n = matrix[0].Length;
			int[,] dp = new int[m, n];

			int cnt = 0;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (matrix[i][j] == 1)
					{
						if (i == 0 || j == 0)
						{
							dp[i, j] = 1;
						}
						else
						{
							dp[i, j] = 1 + Math.Min(
								Math.Min(dp[i - 1, j], dp[i, j - 1]),
								dp[i - 1, j - 1]
							);
						}
						cnt += dp[i, j];
					}
					else
					{
						dp[i, j] = 0;
					}
				}
			}

			return cnt;
		}
	}
}
