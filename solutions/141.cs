using DataStructions;

namespace Problem141
{
	public class Solution
	{
		public bool HasCycle(ListNode head)
		{
			if (head == null)
				return false;

			ListNode low = head;
			ListNode fast = head;

			while (low != null && fast != null && fast.next != null)
			{
				low = low.next;
				fast = fast.next.next;

				if (low == fast)
					return true;
			}

			return false;
		}
	}
}
