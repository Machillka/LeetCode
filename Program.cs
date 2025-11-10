using Problem113;
using DataStructions;

public class Program
{
    public static void Main(string[] args)
    {
        var sol = new Solution();

        // // char[][] test = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']];

        // // var ans = sol.Exist(test, "ABCB");
        // // Console.WriteLine(ans);

        TreeNode t = new(5)
        {
            left = new TreeNode(4),
            right = new TreeNode(8)
        };

        t.left.left = new TreeNode(11)
        {
            left = new TreeNode(7),
            right = new TreeNode(2)
        };

        t.right.left = new TreeNode(13);
        t.right.right = new TreeNode(4)
        {
            left = new TreeNode(5),
            right = new TreeNode(1)
        };

        var ans = sol.PathSum(t, 22);
        Console.WriteLine(ans);
        // ListNode.PrintList(ans);
    }
}