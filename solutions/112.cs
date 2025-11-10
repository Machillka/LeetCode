using DataStructions;

namespace Problem112
{
	public class Solution
	{
		// 不加入记忆化 直接裸的搜
		public bool HasPathSum(TreeNode root, int targetSum)
		{
			return SumPathValue(root, targetSum, 0);
		}

		public bool SumPathValue(TreeNode root, int targetSum, int sum)
		{
			if (root == null)
				return false;

			sum += root.val;

			// 保证是叶子节点才可以
			if (root.left == null && root.right == null)
				return sum == targetSum;

			return SumPathValue(root.left, targetSum, sum) || SumPathValue(root.right, targetSum, sum);
		}
	}
}
