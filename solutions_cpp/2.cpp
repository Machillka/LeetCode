/**
 * Definition for singly-linked list.
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *ansHead = nullptr, *ansTail = nullptr;

        // 进位
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;

            int sum = val1 + val2 + carry;
            int currentBit = sum % 10;

            if (ansHead == nullptr)
            {
                ansHead = ansTail = new ListNode(currentBit);
            }
            else
            {
                ansTail->next = new ListNode(currentBit);
                ansTail = ansTail->next;
            }

            carry = static_cast<int>(sum / 10);

            if (l1)
            {
                l1 = l1->next;
            }

            if (l2)
            {
                l2 = l2->next;
            }
        }

        if (carry > 0)
        {
            ansTail->next = new ListNode(carry);
        }

        return ansHead;
    }
};

int main()
{

    // auto ans = Solution{}.addTwoNumbers(ListNode *l1, ListNode *l2)

    return 0;
}