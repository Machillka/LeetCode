using Problem3234;
using DataStructions;

public class Program
{
    public static void Main(string[] args)
    {
        var sol = new Solution();

        string s = "101101";

        var ans = sol.NumberOfSubstrings(s);
        Console.WriteLine(ans);
        // ListNode.PrintList(ans);
    }
}