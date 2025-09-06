using Problem5;
public class Program
{
    public static void Main(string[] args)
    {
        var sol = new Solution();

        // char[][] test = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']];

        // var ans = sol.Exist(test, "ABCB");
        // Console.WriteLine(ans);
        string s = "babad";
        var ans = sol.Temp(s);
        Console.WriteLine(ans);
        Console.WriteLine(sol.IsReversedString("aa", 0, 1));
    }
}