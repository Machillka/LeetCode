using System.Collections;

namespace Problem49;

class Solution
{
    public IList<IList<string>> GroupAnagrams(string[] strs)
    {
        Dictionary<string, IList<string>> dict = new Dictionary<string, IList<string>>();

        foreach (string data in strs)
        {
            char[] chars = data.ToCharArray();
            Array.Sort(chars);
            string sortedStr = new string(chars);
            // 不存在, 先插入一个新的空列表
            if (!dict.ContainsKey(sortedStr))
            {
                dict.Add(sortedStr, []);
            }
            // 再插入数据
            dict[sortedStr].Add(data);
        }

        return dict.Values.ToList();
    }
}