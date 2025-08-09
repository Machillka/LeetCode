using Problem64;

public class Program
{
    public static void Main(string[] args)
    {
        var sol = new Solution();

        int[][] test = [[1, 2, 3], [4, 5, 6]];

        var ans = sol.MinPathSum(test);
        Console.WriteLine(ans);
        sol.Log();
    }
}