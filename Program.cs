using Problem63;

public class Program
{
    public static void Main(string[] args)
    {
        var sol = new Solution();

        int[][] test = [[0,1],[0,0]];

        var ans = sol.UniquePathsWithObstacles(test);
        Console.WriteLine(ans);
    }
}