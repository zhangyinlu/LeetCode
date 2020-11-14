#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast)
        { //find mid node
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }

        while (slow)
        { //reverse
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        while (head && prev)
        { //check
            if (head->val != prev->val)
            {
                return false;
            }
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(0);

    cout << (solution.isPalindrome(head) ? "true" : "false") << endl;

    return 0;
}
