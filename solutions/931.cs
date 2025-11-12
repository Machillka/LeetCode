namespace Problem931
{
	public class Solution
	{
		private int[][] sumTable = new int[105][];       // 从 (i, j) 到底部的最短路径
		private int m, n;
		private int[] pathY = { -1, 0, 1 };
		public int MinFallingPathSum(int[][] matrix)
		{
			m = matrix.Length;
			n = matrix[0].Length;

			for (int i = 0; i < m; i++)
			{
				sumTable[i] = new int[105];
				for (int j = 0; j < n; j++)
					sumTable[i][j] = int.MaxValue;
			}

			for (int j = 0; j < n; j++)
				sumTable[n - 1][j] = matrix[n - 1][j];

			int ans = int.MaxValue;
			for (int j = 0; j < n; j++)
			{
				ans = Math.Min(Dfs(0, j, matrix), ans);
			}

			return ans;
		}

		public int Dfs(int x, int y, int[][] matrix)
		{
			if (x > n - 1 || x < 0 || y > m - 1 || y < 0)
				return int.MaxValue;

			if (sumTable[x][y] != int.MaxValue)
			{
				return sumTable[x][y];
			}

			int temp = int.MaxValue;
			for (int i = 0; i < 3; i++)
			{
				temp = Math.Min(temp, Dfs(x + 1, y + pathY[i], matrix));
			}

			sumTable[x][y] = matrix[x][y] + temp;

			return sumTable[x][y];
		}
	}
}
