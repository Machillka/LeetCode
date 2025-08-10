namespace Problem94
{

	//  Definition for a binary tree node.
	public class TreeNode
	{
		public int val;
		public TreeNode left;
		public TreeNode right;
		public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
		{
			this.val = val;
			this.left = left;
			this.right = right;
		}
	}

	public class Solution
	{
		IList<int> res = new List<int>();

		public void Dfs(TreeNode root)
		{
			if (root == null)
				return;

			Dfs(root.left);
			res.Add(root.val);
			Dfs(root.right);
		}

		public IList<int> InorderTraversal(TreeNode root)
		{
			Dfs(root);
			return res;
		}
	}
}