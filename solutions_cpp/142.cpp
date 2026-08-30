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
    ListNode* detectCycle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                fast = head;

                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }

        return nullptr;
    }

    ListNode* detectCycle_impl(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        int fastLen = 0;
        int slowLen = 0;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            fastLen += 2;
            ++slowLen;
            if (fast == slow)
                break;
        }

        if (fast != slow)
            return nullptr;

        // kL
        int delta = fastLen - slowLen;
        slow = fast = head;

        while (delta > 0)
        {
            delta--;
            fast = fast->next;
        }

        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};