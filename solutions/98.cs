namespace Problem98
{
	public class TreeNode
	{
		public int val;
		public TreeNode left;
		public TreeNode right;
		public TreeNode(int val=0, TreeNode left = null, TreeNode right = null)
		{
			this.val = val;
			this.left = left;
			this.right = right;
		}
	}

	public class Solution
	{
		public bool IsValidBST(TreeNode root) => InOrder(root);

		public bool Search(TreeNode node, long minVal = long.MinValue, long maxVal = long.MaxValue)
		{
			if (node == null)
				return true;
			// 不在区间内
			if (node.val <= minVal || node.val >= maxVal)
				return false;

			return Search(node.left, minVal, node.val) && Search(node.right, node.val, maxVal);
		}

		public bool InOrder(TreeNode root)
		{
			if (root == null)
				return true;

			Stack<TreeNode> stack = new Stack<TreeNode>();
			long lastVal = long.MinValue;

			while (stack.Count > 0 || root != null)
			{
				while (root != null)
				{
					stack.Push(root);
					root = root.left;
				}

				root = stack.Pop();

				if (root.val <= lastVal)
					return false;

				lastVal = root.val;
				root = root.right;
			}

			return true;
		}
	}
}
