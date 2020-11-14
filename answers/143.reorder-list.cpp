#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.
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
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }

        //使用快慢指针获取List的中间位置
        ListNode *slow = head, *fast = head;
        while (nullptr != fast->next && nullptr != fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *left = head;
        ListNode *right = slow->next;
        slow->next = nullptr;

        //翻转后半部分List列表
        ListNode *cur = right, *prev = nullptr;
        while (nullptr != cur)
        {
            ListNode *nextTmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextTmp;
        }
        right = prev;

        //合并左右两个数组
        ListNode *leftNextTmp = nullptr, *rightNextTmp = nullptr;
        while (nullptr != left && nullptr != right)
        {
            leftNextTmp = left->next;
            rightNextTmp = right->next;

            left->next = right;
            left = leftNextTmp;

            right->next = left;
            right = rightNextTmp;
        }
    }
    void reorderListSlow(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }
        vector<ListNode *> vec;
        ListNode *node = head;
        while (node != nullptr)
        {
            vec.emplace_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j)
        {
            vec[i]->next = vec[j];
            i++;
            if (i == j)
            {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};

void printList(ListNode *head)
{
    while (nullptr != head)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "(null)" << endl;
}

int main()
{
    Solution solution;
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    solution.reorderList(head);
    printList(head);
    return 0;
}
