// using Problem76;
using DataStructions;
using Problem547;

public class Program
{
    public static void Main(string[] args)
    {
        var sol = new Solution();

        int[][] isConnected = [[1, 1, 0], [1, 1, 0], [0, 0, 1]];

        int ans = sol.FindCircleNum(isConnected);

        // string s = "ADOBECODEBANC";
        // string t = "ABC";

        // var ans = sol.MinWindow(s, t);
        Console.WriteLine(ans);
        // ListNode.PrintList(ans);
    }
}