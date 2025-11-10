using DataStructions;

namespace Problem234
{
	public class Solution
	{
		public bool IsPalindrome(ListNode head)
		{
			if (head == null)
				return true;

			ListNode fastPoint = head;      // 快指针到达的时候, 慢指针指向中点
			ListNode lowPoint = head;

			while (fastPoint.next != null && fastPoint.next.next != null)
			{
				fastPoint = fastPoint.next.next;
				lowPoint = lowPoint.next;
			}

			ListNode curr = head;
			ListNode midPoint = ReverseList(lowPoint);
			ListNode.PrintList(midPoint);
			while (curr != null && midPoint != null)
			{
				if (curr.val != midPoint.val)
					return false;
				curr = curr.next;
				midPoint = midPoint.next;
			}

			return true;
		}

		public ListNode ReverseList(ListNode node)
		{
			if (node.next == null)
				return node;
			ListNode last = ReverseList(node.next);
			node.next.next = node;
			node.next = null;
			return last;
		}
	}
}
