namespace DataStructions
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }

        public static ListNode CreateList(int[] vals)
        {
            ListNode node = new(vals[0]);
            ListNode curr = node;
            for (int i = 1; i < vals.Length; i++)
            {
                ListNode newNode = new ListNode(vals[i]);
                curr.next = newNode;
                curr = curr.next;
            }

            return node;
        }

        public static void PrintList(ListNode head)
        {
            var curr = head;
            while (curr != null)
            {
                Console.Write($"{curr.val} -> ");
                curr = curr.next;
            }
            Console.Write("null\n");
        }
    }
}