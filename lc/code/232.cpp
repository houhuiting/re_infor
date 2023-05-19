#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res;
        // 如果输出栈没有元素的话，就把输入栈所有元素拿过来
        if (out.empty()) {
            while (!in.empty()) {
                int top = in.top();
                in.pop();
                out.push(top);
            }
            res = out.top();
            out.pop();
        }
        // 如果输出栈有元素的话，就直接输出
        else {
            res = out.top();
            out.pop();
        }
        return res;
    }

    /** Get the front element. */
    int peek() {
        int res = this->pop();
        out.push(res);
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
    }
private:
    stack<int> in;
    stack<int> out;
};

int main()
{
    MyQueue* queue = new MyQueue();
    queue->push(1);
    queue->push(2);
    cout << queue->peek() << endl;  // 返回 1
    cout << queue->pop() << endl;   // 返回 1
    cout << queue->empty() << endl; // 返回 false
}
