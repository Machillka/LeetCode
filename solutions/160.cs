namespace Problem160
{
	public class ListNode
	{
		public int val;
		public ListNode next;
		public ListNode(int x) { val = x; }
	}
	public class Solution
	{
		public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
		{
			// 一定不存在
			if (headA == null || headB == null)
				return null;

			HashSet<ListNode> set = new();
			ListNode currA = headA;

			while (currA != null)
			{
				set.Add(currA);
				currA = currA.next;
			}

			ListNode currB = headB;
			while (currB != null)
			{
				if (set.Contains(currB))
					return currB;
				currB = currB.next;
			}

			return null;
		}
	}
}
