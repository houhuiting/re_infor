#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    class compare{
        bool operator()(pair<int, int> node1, pair<int, int> node2) {
        return node1.second > node2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 将频率存在map中
        unordered_map<int,int> map;
        for (int i=0; i<nums.size(); i++) {
            map[nums[i]]++;
        }
        // 定义一个优先级队列
        priority_queue<pair<int,int>,vector<pair<int,int> >,compare> pri_que;

        // 遍历map，将map的频率放到priority_queue进行排序
        for (unordered_map<int,int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        vector<int> res(k);
        while (k--) {
            res[k] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};
