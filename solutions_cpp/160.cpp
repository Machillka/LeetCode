/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstddef>
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
  public:
    int _getLen(ListNode* head)
    {
        int len = 0;

        while (head != nullptr)
        {
            ++len;
            head = head->next;
        }

        return len;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        int lenA = _getLen(headA);
        int lenB = _getLen(headB);
        int deltaLen = 0;

        ListNode* longerHead = nullptr;
        ListNode* shorterHead = nullptr;

        if (lenA >= lenB)
        {
            longerHead = headA;
            shorterHead = headB;
            deltaLen = lenA - lenB;
        }
        else
        {
            longerHead = headB;
            shorterHead = headA;
            deltaLen = lenB - lenA;
        }

        while (deltaLen > 0 && longerHead != nullptr)
        {
            longerHead = longerHead->next;
            --deltaLen;
        }

        while (longerHead != nullptr && shorterHead != nullptr)
        {
            if (longerHead == shorterHead)
            {
                return longerHead;
            }

            longerHead = longerHead->next;
            shorterHead = shorterHead->next;
        }

        return nullptr;
    }
};