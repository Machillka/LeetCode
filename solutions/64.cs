using System.Runtime.CompilerServices;

namespace Problem64
{
	public class Solution
	{
		// [i, j] 表示从起点开始到 [i, j] 的最小开销
		int[,] minCosts = new int[205, 205];

		/// <summary>
		/// 使用记忆化搜索的方式
		/// </summary>
		/// <param name="costs"></param>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <param name="endPosX"></param>
		/// <param name="endPosY"></param>
		/// <returns></returns>
		public int SearchMinPathSum(int[][] costs, int x, int y, int endPosX, int endPosY)
		{
			if (minCosts[x, y] != -1)
			{
				return minCosts[x, y];
			}

			if (x >= endPosX || y >= endPosY)
			{
				return int.MaxValue;
			}

			minCosts[x, y] = Math.Min(
				SearchMinPathSum(costs, x + 1, y, endPosX, endPosY),
				SearchMinPathSum(costs, x, y + 1, endPosX, endPosY)
			) + costs[x][y];

			return minCosts[x, y];
		}

		public void InitializeMinCosts(int width, int height)
		{
			for (int i = 0; i <= height; i++)
			{
				for (int j = 0; j <= width; j++)
				{
					minCosts[i, j] = -1;
				}
			}
		}

		public int MinPathSum(int[][] grid)
		{
			int width = grid[0].Length;
			int height = grid.Length;

			InitializeMinCosts(width, height);
			minCosts[height - 1, width - 1] = grid[height - 1][width - 1];

			return SearchMinPathSum(grid, 0, 0, height, width);
		}

		public void Log()
		{
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Console.Write(minCosts[i, j]);
					Console.Write(" ");
				}
				Console.WriteLine();
			}
		}

		// [i, j] 表示从起点开始到 [i, j] 的最小开销
		// public int[,] minCosts = new int[205, 205];
		// /// <summary>
		// /// 使用 dp 递推的方式
		// /// </summary>
		// /// <param name="grid"></param>
		// /// <returns></returns>
		// public int MinPathSum(int[][] grid)
		// {
		// 	minCosts[0, 0] = grid[0][0];
		// 	int width = grid[0].Length;
		// 	int height = grid.Length;
		// 	// 第一行只能累加
		// 	for (int j = 1; j < width; j++)
		// 	{
		// 		minCosts[0, j] = grid[0][j] + minCosts[0, j - 1];
		// 	}
		// 	// 第一列只能累加
		// 	for (int i = 1; i < height; i++)
		// 	{
		// 		minCosts[i, 0] = grid[i][0] + minCosts[i - 1, 0];
		// 	}

		// 	for (int i = 1; i < height; i++)
		// 	{
		// 		for (int j = 1; j < width; j++)
		// 		{
		// 			minCosts[i, j] = Math.Min(minCosts[i - 1, j], minCosts[i, j - 1]) + grid[i][j];
		// 		}
		// 	}

		// 	return minCosts[height - 1, width - 1];
		// }
	}
}
