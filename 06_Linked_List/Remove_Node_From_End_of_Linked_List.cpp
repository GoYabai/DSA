
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int l = 0;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            l++;
            curr = curr->next;
        }
        curr = head;
        int rm = l - n;
        if (rm == 0)
        {
            return head->next;
        }
        for (int i = 0; i < l; i++)
        {
            if (i + 1 == rm)
            {
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};
