namespace Problem3
{
  	public class Solution
	{
		public int LengthOfLongestSubstring(string s)
		{
			int left = 0, right = 0;
			int ans = 0;
			int length = s.Length;
			HashSet<char> letters = new HashSet<char>();

			for (; right < length;)
			{
				// 不包含在内
				if (!letters.Contains(s[right]))
				{
					// 加入当前字符
					letters.Add(s[right]);
					// 窗口右移动
					right++;
					ans = Math.Max(ans, right - left);
				}
				// 包含在内
				else
				{
					// 左侧指针右移动
					letters.Remove(s[left]);
					left++;
				}
			}
			return ans;
    	}
	}
}
