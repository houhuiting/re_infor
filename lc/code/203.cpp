#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return head;
        // 设置虚拟头节点，用于应对删除第一个节点的情况
        ListNode* dummy = new ListNode();
        dummy->next = head;
         // 设置一个循环遍历p，从前往后循环链表
        ListNode* p = new ListNode();
        p = dummy;
        while (p->next != NULL)
        {
            if (p->next->val == val) {
                p->next = p->next->next;
            }
            else {
                p = p->next; 
            }
        }
        return dummy->next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    Solution sol;
    int val = 6;
    ListNode* res = sol.removeElements(head, val);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}
