using Problem76;
using DataStructions;

public class Program
{
    public static void Main(string[] args)
    {
        var sol = new Solution();

        string s = "ADOBECODEBANC";
        string t = "ABC";

        var ans = sol.MinWindow(s, t);
        Console.WriteLine(ans);
        // ListNode.PrintList(ans);
    }
}