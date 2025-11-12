namespace Problem221
{
	public class Solution
	{
		public int MaximalSquare(char[][] matrix)
		{
			if (matrix == null || matrix.Length == 0)
				return 0;

			int m = matrix.Length;
			int n = matrix[0].Length;

			// 存储 [i, j] 点为右下角的可以形成的最大正方形
			int[,] dp = new int[m, n];
			int maxSide = 0;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (matrix[i][j] == '1')
					{
						// 边角只能为 1
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
						maxSide = Math.Max(dp[i, j], maxSide);
					}
					else
					{
						dp[i, j] = 0;
					}
				}
			}

			return maxSide * maxSide;
		}
	}
}
