#include <cstddef>
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution
{
  public:
    /*!
     * @brief  返回左半部分的最后一个节点地址
     *
     * @param  head
     * @return ListNode*
     * @author Machillka (machillka2007@gmail.com)
     * @date 2026-08-30
     */
    ListNode* findMidNode(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        return prev;
    }

    ListNode* merge(ListNode* a, ListNode* b)
    {
        // 虚拟头节点
        ListNode dummy;
        ListNode* tail = &dummy;

        while (a != nullptr && b != nullptr)
        {
            if (a->val <= b->val)
            {
                tail->next = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = a == nullptr ? b : a;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head)
    {
        return sortListImpl(head);
    }

    ListNode* sortListImpl(ListNode* head, void*)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode* midNode = findMidNode(head);
        ListNode* left = head;
        ListNode* right = midNode->next;
        midNode->next = nullptr;
        return merge(sortList(left), sortList(right));
    }

    std::size_t getListLength(ListNode* head)
    {
        std::size_t len = 0;

        while (head != nullptr)
        {
            ++len;
            head = head->next;
        }

        return len;
    }

    ListNode* split(ListNode* head, std::size_t n)
    {
        if (head == nullptr)
            return nullptr;

        ListNode* cutter = head;
        while (head != nullptr && n > 0)
        {
            --n;
            cutter = head;
            head = head->next;
        }

        cutter->next = nullptr;
        return head;
    }

    ListNode* sortListImpl(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        const std::size_t n = getListLength(head);

        for (std::size_t step = 1; step < n; step <<= 1)
        {
            ListNode dummy;
            ListNode* tail = &dummy;
            ListNode* current = head;

            while (current != nullptr)
            {
                ListNode* left = current;
                ListNode* right = split(current, step);

                current = split(right, step);

                tail->next = merge(left, right);
                while (tail->next != nullptr)
                {
                    tail = tail->next;
                }
            }

            head = dummy.next;
        }

        return head;
    }
};