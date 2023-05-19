#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    /** Push element x onto stack. */
    void push(int x) {
        int size = que.size();
        que.push(x);
        while (size--) {
            int y = que.front();
            que.pop();
            que.push(y);
        }
    }
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int y = que.front();
        que.pop();
        return y;
    }

    /** Get the top element. */
    int top() {
        int y = que.front();
        return y;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};

int main()
{
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    cout << param_2 << param_3 << param_4 << endl;
    return 0;
}