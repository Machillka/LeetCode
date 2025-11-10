namespace Problem13
{
	public class Solution
	{
		public string LongestCommonPrefix(string[] strs)
		{
			if (strs == null)
				return "";

			string ans = "";
			int minLength = strs[0].Length;

			for (int i = 0; i < strs.Length; i++)
			{
				minLength = Math.Min(minLength, strs[i].Length);
			}

			for (int idx = 0; idx < minLength; idx++)
			{
				char c = strs[0][idx];
				for (int i = 1; i < strs.Length; i++)
				{
					if (strs[i][idx] != c)
						return ans;
				}
				ans += c;
			}

			return ans;
		}
	}
}
