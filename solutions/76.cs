namespace Problem76
{
	public class Solution
	{
		// public string MinWindow(string s, string t)
		// {
		// 	// 尝试使用 HashSet 优化
		// 	var needsChar = new Dictionary<char, int>();

		// 	int m = t.Length;
		// 	for (int i = 0; i < m; i++)
		// 	{
		// 		needsChar.TryAdd(t[i], 0);
		// 		// 对应下标 +1 -> 说明需要的多了
		// 		needsChar[t[i]] += 1;
		// 	}

		// 	int n = s.Length;
		// 	int left = 0;
		// 	int right = 0;
		// 	// 记录答案下标，最后生成字符串
		// 	int ansLeft = -1;
		// 	int ansRight = n;

		// 	while (right < n)
		// 	{
		// 		// 往窗口中添加元素
		// 		if (needsChar.ContainsKey(s[right]))
		// 			needsChar[s[right]] -= 1;

		// 		// 收缩窗口
		// 		while (IsContainSubString(needsChar) && left <= right)
		// 		{
		// 			// 说明找到更小的窗口
		// 			if (ansRight - ansLeft > right - left)
		// 			{
		// 				ansRight = right;
		// 				ansLeft = left;
		// 			}
		// 			if (needsChar.ContainsKey(s[left]))
		// 				needsChar[s[left]] += 1;
		// 			left++;
		// 		}
		// 		right++;
		// 	}

		// 	return ansLeft == -1 ? "" : s.Substring(ansLeft, ansRight - ansLeft + 1);
		// }

		// private bool IsContainSubString(Dictionary<char, int> contain)
		// {
		// 	foreach (var key in contain.Keys)
		// 	{
		// 		if (contain[key] > 0)
		// 			return false;
		// 	}
		// 	return true;
		// }
		public string MinWindow(string s, string t)
		{
			int[] hashTable = new int[128];

			int m = t.Length;
			for (int i = 0; i < m; i++)
				hashTable[t[i]] += 1;

			int n = s.Length;
			int left = 0, right = 0;
			// 记录答案下标，最后生成字符串
			int ansLeft = -1, ansRight = n;

			while (right < n)
			{
				// 往窗口中添加元素
				hashTable[s[right]] -= 1;

				// 收缩窗口
				while (IsContainSubString(hashTable) && left <= right)
				{
					// 说明找到更小的窗口
					if (ansRight - ansLeft > right - left)
					{
						ansRight = right;
						ansLeft = left;
					}

					hashTable[s[left]] += 1;
					left++;
				}
				right++;
			}

			return ansLeft == -1 ? "" : s.Substring(ansLeft, ansRight - ansLeft + 1);
		}

		private bool IsContainSubString(int[] hashTable)
		{
			for (int i = 0; i < hashTable.Length; i++)
			{
				if (hashTable[i] > 0)
					return false;
			}
			return true;
		}
	}
}
