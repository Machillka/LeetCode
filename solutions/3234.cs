namespace Problem3234
{
	public class Solution
	{
		public int NumberOfSubstringsLow(string s)
		{
			if (s == null)
				return 0;

			int countNumbers = 0;
			for (int slideSize = 1; slideSize <= s.Length; slideSize++)
			{
				int[] cnt = new int[2];
				for (int i = 0; i < slideSize; i++)
				{
					cnt[s[i] - '0'] += 1;
				}
				if (cnt[1] >= (cnt[0] * cnt[0]))
					countNumbers += 1;
				for (int left = 1; left + slideSize <= s.Length; left++)
				{
					cnt[s[left - 1] - '0'] -= 1;
					cnt[s[left + slideSize - 1] - '0'] += 1;
					if (cnt[1] >= (cnt[0] * cnt[0]))
						countNumbers += 1;
				}
			}
			return countNumbers;
		}

		/// <summary>
		/// 枚举 0 的个数, 然后在确定 1 的个数 (通过计算)
		/// </summary>
		/// <param name="s"></param>
		/// <returns></returns>
		public int NumberOfSubstrings(string s)
		{
			if (string.IsNullOrEmpty(s))
				return 0;

			int n = s.Length;
			int countNumbers = 0;
			// 记录每个点位前一个0的位置
			// 对于[pre[j] .. i-1], 区间内 1 的数量就是 i - prev[j] - cnt0
			int[] prevIdx = new int[n + 1];
			prevIdx[0] = -1;
			for (int i = 1; i < n; i++)
				prevIdx[i + 1] = s[i - 1] == '0' ? i : prevIdx[i];

			// 枚举右端点
			for (int i = 1; i <= n; i++)
			{
				// 转化成枚举 0 的个数 => prev[i] - prev[j]
				int cnt0 = s[i - 1] == '0' ? 1 : 0;
				// 从右端点, 到距离右端点最近的 0 的这个区间
				int j = i;

				// 剪枝, 如果 cnt0 的数量大于 sqrt(n) 则一定不符合条件
				while (j > 0 && cnt0 * cnt0 <= n)
				{
					// 计算区间 [prev[j], i - 1] 这个区间内 1 的个数
					int cnt1 = i - prevIdx[j] - cnt0;
					if (cnt1 >= cnt0 * cnt0)
					{
						// 在满足区间可以的情况下
						// 左端可选取位置一共有 j - prevIdx[j] 个  (两个 0 位置之间都可以选取)
						// 但是也有一个约束条件是 不是两个 0 之间都可以选取, 对于可以选取的 1 的位置，有右端限制 (不能距离 右端点 太近否则可能会导致 1 的数量太少)
						// 是 cnt1 - cnt0^2 + 1
						countNumbers += Math.Min(j - prevIdx[j], cnt1 - cnt0 * cnt0 + 1);
					}
					// j 往前走到上一个 0 出现的位置
					j = prevIdx[j];
					// 所以 0 出现的次数 +1
					cnt0 += 1;
				}
			}

			for (int i = 0; i <= n; i++)
				Console.Write($" {prevIdx[i]}");
			Console.WriteLine();
			return countNumbers;
		}

	}
}
