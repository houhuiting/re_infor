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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;
        ListNode* p1 = new ListNode();
        ListNode* p2 = new ListNode();
        p1 = head;
        p2 = head->next;
        // 手动将第一个节点反转过来
        p1->next = nullptr;
        // 从第二个节点开始反转
        while (p2!=NULL) {
            ListNode* p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution solution;
    ListNode* newHead = solution.reverseList(head);

    while (newHead != NULL) {
        cout << newHead->val << " ";
        newHead= newHead->next;
    }
    cout << endl;
}