using Problem931;
using DataStructions;

public class Program
{
    public static void Main(string[] args)
    {
        var sol = new Solution();

        int[][] m = [[0, 0, 0], [0, 0, 0], [0, 0, 0]];

        var ans = sol.MinFallingPathSum(m);
        Console.WriteLine(ans);
        // ListNode.PrintList(ans);
    }
}