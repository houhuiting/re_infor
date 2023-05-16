#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 由于最后的结果是去重的，使用set来存结果进行去重
        unordered_set<int> res;
        // 直接将vector存入到set中，自动去重
        unordered_set<int> num(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); i++) {
            if (num.count(nums2[i]) >= 1) {
                // 由于题目输出的结果是去重的，利用unordered_set自动去重的特点，现将结果存到unordered_set中
                res.insert(nums2[i]);
            }
        }
        // 直接将unordered_set转为vector输出
        return vector<int>(res.begin(), res.end());
    }
};