namespace Problem63
{
  	public class Solution
	{
		int [,] roadCounts = new int[105, 105];

		public void InitRoadCount(int m, int n)
		{
			for (int i = 0; i <= m + 1; i++)
			{
				for (int j = 0; j <= n + 1; j++)
				{
					roadCounts[i, j] = -1;
				}
			}
		}

		public int FindPathDFS(int x, int y, int endPosX, int endPosY, int[][] obstacleGrid)
		{
			if (x > endPosX || y > endPosY)
				return 0;

			if (obstacleGrid[x - 1][y - 1] == 1)
				return 0;

			if (roadCounts[x, y] != -1)
				return roadCounts[x, y];

			int currentCounts = FindPathDFS(x + 1, y, endPosX, endPosY, obstacleGrid) + FindPathDFS(x, y + 1, endPosX, endPosY, obstacleGrid);

			roadCounts[x, y] = currentCounts;

			return roadCounts[x, y];
		}

		public int UniquePathsWithObstacles(int[][] obstacleGrid)
		{
			int m = obstacleGrid.Length;
			int n = obstacleGrid[0].Length;
			InitRoadCount(m, n);

			// 终点标记
			if (obstacleGrid[m - 1][n - 1] == 1)
			{
				roadCounts[m, n] = 0;
			}
			else
			{
				roadCounts[m, n] = 1;
			}

			// 起点作为 1, 1 下标从 1 开始
			FindPathDFS(1, 1, m, n, obstacleGrid);

			if (roadCounts[1, 1] == -1)
				return 0;
			return roadCounts[1, 1];
		}
	}
}
