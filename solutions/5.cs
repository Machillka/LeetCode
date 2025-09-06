namespace Problem5
{
	public class Solution
	{
		public bool IsReversedString(string s, int left, int right)
		{
			while (left < right)
			{
				if (s[left] != s[right])
					return false;
				left++;
				right--;
			}

			return true;
		}

		// N^2 枚举
		public string LongestPalindrome(string s)
		{
			// 枚举左边，判断右侧是否可以成为回文子串
			int len = s.Length;
			int resLength = 0;
			string res = "";
			for (int left = 0; left < len; left++)
			{
				int right = left;
				while (right < len)
				{
					if (IsReversedString(s, left, right))
					{
						if (resLength < (right - left + 1))
						{
							res = s.Substring(left, right - left + 1);
							resLength = right - left + 1;
						}
					}
					right++;
				}
			}
			return res;
		}
	}
}
