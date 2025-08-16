namespace Problem79
{
  	public class Solution
	{
		int m, n;
		int[,] dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		/// <summary>
		/// 深搜查找单词是否存在
		/// </summary>
		/// <param name="board"></param>
		/// <param name="word">目标单词</param>
		/// <param name="currentWord">目前拼接的单词</param>
		/// <param name="x">目前坐标, 行</param>
		/// <param name="y">目前坐标, 列</param>
		/// <returns></returns>
		public bool IsWordExist(char[][] board, string word, string currentWord, int x, int y, bool[,] calledCell)
		{
			currentWord += board[x][y];
			if (currentWord.Length > word.Length)
				return false;

			if (currentWord == word)
				return true;

			// 遍历四个方向
			for (int i = 0; i < 4; i++)
			{
				int objX = x + dir[i, 0];
				int objY = y + dir[i, 1];
				// 数组越界
				if (objX >= m || objY >= n || objX < 0 || objY < 0)
					continue;
				// 目标单位的字符不对应
				if (board[objX][objY] != word[currentWord.Length])
					continue;
				// 已访问过的无法重新访问
				if (calledCell[objX, objY])
					continue;

				calledCell[objX, objY] = true;
				bool resExist = IsWordExist(board, word, currentWord, objX, objY, calledCell);
				calledCell[objX, objY] = false;
				if (resExist)
					return true;
			}

			return false;
		}

		public bool Exist(char[][] board, string word)
		{
			m = board.Length;
			n = board[0].Length;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (board[i][j] == word[0])
					{
						// 重新声明 -> 少一步初始化 = false
						bool[,] calledCell = new bool[m, n];
						calledCell[i, j] = true;
						if (IsWordExist(board, word, "", i, j, calledCell))
							return true;
					}
				}
			}

			return false;
		}
	}
}
