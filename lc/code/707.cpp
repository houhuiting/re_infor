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

class MyLinkedList {
public:
    MyLinkedList() {
        size = 0;
        head = new ListNode();
    }

    int get(int index) {
        if (index >= size || index < 0)
            return -1;
        ListNode* p = head;
        int cur_index = -1;
        while(cur_index != index) {
            p = p->next;
            cur_index++;
        }
        return p->val;
    }

    void addAtHead(int val) {
        ListNode* p = new ListNode(val);
        p->next = head->next;
        head->next = p;
        size++;
    }

    void addAtTail(int val) {
        ListNode* p = new ListNode(val);
        ListNode* p_last = head;
        while (p_last->next != NULL) {
            p_last = p_last->next;
        }
        p_last->next = p;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size || index < 0)
            return;
        ListNode* p = new ListNode(val);
        ListNode* p_index = head;
        int cur_index = -1;
        while (cur_index != index - 1) {
            p_index = p_index->next;
            cur_index++;
        }
        p->next = p_index->next;
        p_index->next = p;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size || index < 0)
            return;
        ListNode* p_index = head;
        int cur_index = -1;
        while(cur_index != index - 1) {
            p_index = p_index->next;
            cur_index++;
        }
        p_index->next = p_index->next->next;
        size--;
    }
private:
    int size;
    ListNode* head;
};