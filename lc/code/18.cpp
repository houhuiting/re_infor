#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if (nums.size() < 4)
            return res;
        // 排序一波，具体理由见三数之和思路
        sort(nums.begin(), nums.end());
        // 最后3个位置要留给b c d
        for (int i = 0; i < nums.size() - 3; i++) {
            // 对a去重
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int a = nums[i];
            // 最后2个位置要留给c d
            for (int j = i + 1; j < nums.size() - 2; j++) {
                // 对b去重
                if (j > i + 1 && nums[j] == nums[j-1])
                    continue;
                int b = nums[j];
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    int c = nums[left];
                    int d = nums[right];
                    // 如果a + b + c + d > target，说明这4个数取大了，就让right左移一点
                    if (a + b + c + d > target) {
                        right--;
                    }
                    // 如果a + b + c + d < target，说明这4个数取小了，就让right左移一点
                    else if (a + b + c + d < target) {
                        left++;
                    }
                    else {
                        // 先把结果存下来
                        vector<int> ele;
                        ele.push_back(a);
                        ele.push_back(b);
                        ele.push_back(c);
                        ele.push_back(d);
                        res.push_back(ele);
                        // 然后对c去重，下一个c不能和这一个c相同
                        // 先找到最后一个相同的c
                        while (nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        // 然后对d去重，下一个d不能和这一个d相同
                        // 先找到最后一个相同的d
                        while (nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        // 让下一个c和d和现在的cd不同
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(2);
    vector<vector<int> > res = s.fourSum(nums, 0);
    for (int i = 0; i < res.size(); i++) {
        vector<int> num = res[i];
        for (int j = 0; j < 4; j++) {
            cout << num[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

