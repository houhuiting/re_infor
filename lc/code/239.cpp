#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue* que = new MyQueue();
        vector<int> res;
        for (int i = 0; i < k; i++) {
            que->push(nums[i]);
        }
        res.push_back(que->front());
        for (int i = k; i < nums.size(); i++) {
            que->push(nums[i]);
            que->pop(nums[i-3]);
            res.push_back(que->front());
        }
        return res;
    }
private:
    // 定义一个单调队列
    class MyQueue {
    public:
        deque<int> que;
        // 从队列中拿出一个元素
        void pop(int val) {
            // 只有当想要pop的元素为最大元素的时候，才会pop
            // 单调函数中维持一组递减元素，最右边的最大，也是最先进入队列的元素
            // 如果想要pop的元素小于que.front()的话，那这个元素不可能存在队列中
            // 因为小于que.front()，必然在队列的左边。而在队列左边的元素是比que.front()晚进入队列的
            // 在队列中，pop的规则是先入先出，也就是pop的元素必然是最早进入队列的，不可能是队列的左边的元素
            // 因此，当pop的元素小于que.front()，那这个元素肯定早在que.front()进入队列时，就已经被pop出去了
            if (!que.empty() && val == que.front()) {
                que.pop_front();
            }
        }
        // 压入一个元素
        void push(int val) {
            // 如果压入的元素大于队列末尾的话，就要把队列末尾pop掉，直到队列末尾大于压入的元素
            while (!que.empty() && val > que.back()) {
                que.pop_back();
            }
            que.push_back(val);
        }
        int front() {
            return que.front();
        }
    };
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(-1);
    nums.push_back(-3);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
    vector<int> res;
    res = sol.maxSlidingWindow(nums, 3);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}