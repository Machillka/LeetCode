namespace Problem128
{
	public class Solution
	{
		public int LongestConsecutive(int[] nums)
		{
			if (nums == null || nums.Length == 0)
				return 0;

			HashSet<int> deduplications = new();
			int ans = 1;

			for (int i = 0; i < nums.Length; i++)
				deduplications.Add(nums[i]);

			foreach (var num in deduplications)
			{
				// 不存在前驱 ( 说明是序列开始 ), 才进入长度判断
				if (!deduplications.Contains(num - 1))
				{
					int currentNum = num;
					int currentLength = 0;
					while (deduplications.Contains(currentNum))
					{
						currentLength += 1;
						currentNum += 1;
					}

					ans = Math.Max(currentLength, ans);
				}
			}

			return ans;
		}
	}
}
