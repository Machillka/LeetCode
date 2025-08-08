using Problem62;

public class Program
{
    public static void Main(string[] args)
    {
        var sol = new Solution();

        int ans = sol.UniquePaths(3, 2);

        Console.WriteLine(ans);
    }
}