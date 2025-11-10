using DataStructions;

namespace Problem113
{
	public class Solution
	{
		public IList<IList<int>> PathSum(TreeNode root, int targetSum)
		{
			List<IList<int>> ansList = new();

			if (root == null)
				return ansList;

			var stack = new Stack<(TreeNode node, List<int> path, int sum)>();
			stack.Push((root, new List<int> { root.val }, root.val));

			while (stack.Count > 0)
			{
				var (node, path, sum) = stack.Pop();

				if (node.left == null && node.right == null && sum == targetSum)
				{
					ansList.Add([.. path]);
				}

				if (node.left != null)
				{
					var leftPath = new List<int>(path) { node.left.val };
					stack.Push((node.left, leftPath, sum + node.left.val));
				}

				if (node.right != null)
				{
					var rightPath = new List<int>(path) { node.right.val };
					stack.Push((node.right, rightPath, sum + node.right.val));
				}

			}

			return ansList;
		}
	}
}
