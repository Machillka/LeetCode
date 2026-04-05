namespace Problem547
{
	public class Solution
	{
		// private int N;
		// private bool[] _visited;
		// private void _Dfs(int i, int j, int[][] graph)
		// {
		// 	graph[i][j] = graph[j][i] = 0;

		// 	for (int target = 0; target < N; target++)
		// 	{
		// 		if (graph[j][target] == 1)
		// 			_Dfs(j, target, graph);
		// 	}
		// }

		// public int FindCircleNum(int[][] isConnected)
		// {
		// 	if (isConnected == null)
		// 		return 0;

		// 	int ans = 0;

		// 	N = isConnected.Length;

		// 	for (int i = 0; i < N; i++)
		// 	{
		// 		for (int j = 0; j < N; j++)
		// 		{
		// 			if (isConnected[i][j] == 1)
		// 			{
		// 				_Dfs(i, j, isConnected);
		// 				ans += 1;
		// 			}

		// 		}
		// 	}

		// 	return ans;
		// }
		// private void _Dfs(int currentProvince, int[][] graph)
		// {
		// 	_visited[currentProvince] = true;
		// 	for (int i = 0; i < N; i++)
		// 	{
		// 		if ((!_visited[i]) && graph[currentProvince][i] == 1)
		// 		{
		// 			_Dfs(i, graph);
		// 		}
		// 	}
		// }

		// public int FindCircleNum(int[][] isConnected)
		// {
		// 	if (isConnected == null)
		// 		return 0;

		// 	int ans = 0;

		// 	N = isConnected.Length;
		// 	_visited = new bool[N];

		// 	for (int i = 0; i < N; i++)
		// 	{
		// 		if (!_visited[i])
		// 		{
		// 			ans += 1;
		// 			_Dfs(i, isConnected);
		// 		}
		// 	}

		// 	return ans;
		// }

		private int _n;

		public int FindCircleNum(int[][] isConnected)
		{
			if (isConnected == null)
				return 0;

			int ans = 0;

			_n = isConnected.Length;

			

			for (int i = 0; i < _n; i++)
			{
			}

			return ans;
		}
	}
}
