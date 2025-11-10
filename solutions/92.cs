using DataStructions;
namespace Problem92
{
	public class Solution
	{
		public ListNode ReverseBetween(ListNode head, int left, int right)
		{
			if (head == null)
				return null;

			ListNode temp = new ListNode(0, head);
			ListNode prev = temp;

			for (int i = 1; i < left; i++)
				prev = prev.next;

			// 找到左端点
			ListNode leftNode = prev.next;
			ListNode rightNode = leftNode;

			for (int i = left; i < right; i++)
				rightNode = rightNode.next;

			ListNode rightNodeNext = rightNode.next;

			// 切断子链
			rightNode.next = null;
			ListNode reversedSubList = ReverseList(leftNode);
			ListNode.PrintList(prev);
			prev.next = reversedSubList;
			leftNode.next = rightNodeNext;

			return temp.next;
		}

		public ListNode ReverseList(ListNode head)
		{
			if (head.next == null)
				return head;
			ListNode last = ReverseList(head.next);
			head.next.next = head;
			head.next = null;
			return last;
		}
	}
}
