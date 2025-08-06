/*
 * @lc app=leetcode.cn id=21 lang=csharp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start

// Definition for singly-linked list.

namespace Problem21;

public class ListNode
{
    public int val;
    public ListNode next;
    public ListNode(int val = 0, ListNode next = null)
    {
        this.val = val;
        this.next = next;
    }
}

public class Solution
{
    public ListNode MergeTwoLists(ListNode list1, ListNode list2)
    {
        ListNode res = new ListNode();
        ListNode currentNode = res;

        while (list1 != null && list2 != null)
        {
            if (list1.val < list2.val)
            {
                ListNode addonNode = new ListNode(list1.val);
                currentNode.next = addonNode;
                list1 = list1.next;
            }
            else
            {
                ListNode addonNode = new ListNode(list2.val);
                currentNode.next = addonNode;
                list2 = list2.next;
            }
            currentNode = currentNode.next;
        }

        currentNode.next = list1 ?? list2;

        return res.next;
    }
}
// @lc code=end

